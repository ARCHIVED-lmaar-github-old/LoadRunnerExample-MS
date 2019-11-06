MSF05_Friends_Search_Loop( char *myFriendPages )
{
	int MFP, StartPage, EndPage;

	MFP = (atoi( myFriendPages ) / 10);

	lr_message( myFriendPages );

	sprintf( tmpString, "%s friends, %d pages TOTAL", myFriendPages, MFP );

	lr_message( tmpString );

	//srand is called before rand 
    srand(time(NULL));

	StartPage = rand() % (MFP-10);

	sprintf( tmpString, "***!~ Random Start Page = %d", StartPage );
	lr_message( tmpString );

	//StartPage = 0;
	EndPage = StartPage + 10;

	lr_message( "Debug Point" );

	for( i=StartPage; i<EndPage; i++ )
	{
    	lr_start_transaction("SearchLoop");

		noPages++;

		sprintf( tmpString, "***!~ Search Loop Page = %d", i );
		lr_message( tmpString );

  		sprintf( tmpString, "%d", i );
  		lr_save_string( tmpString, "myFriendPage" );

		lr_message( "Debug Point" );

    	web_add_cookie("MYSPACE=myspace; DOMAIN=www.myspace.com");

    	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=www.myspace.com");

    	web_add_cookie("FRNDID=15537523; DOMAIN=www.myspace.com");

    	// Correlate - Friend ID
        web_reg_save_param(
    		"friendID", 
           	"LB=.viewprofile&friendID=",
    		"RB=&Mytoken=", 
    		"ORD=ALL",
    		LAST);
		/*
    	// Correlate - Friend Pages
        web_reg_save_param(
    		"friendPages", 
           	"LB=<td>1-10 of ",
    		"RB=</td>", 
    		"ORD=1",
    		LAST);
		*/
    	/*
    	index.cfm?fuseaction=find&Mytoken=20050713091837&circuitaction=search&searchType=network&f_first_name=lauren&InterestType=&f_search_criteria=&noDetail=0&first=No&Major=&Clubs=&CurrentCourses=&noDetail=0&Country=&distance=-1&Postal=91765&Photos=1&Gender=2&AgeFrom=18&AgeTo=35&Page=6846
    	*/

    	web_url("index.cfm_3", 
    		"URL=http://www.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}&circuitaction=search&searchType=network&f_first_name=lauren&InterestType=&f_search_criteria=&noDetail=0&first=No&Major=&Clubs=&CurrentCourses=&noDetail=0&Country=&distance=-1&Postal=91765&Photos=1&Gender=2&AgeFrom=18&AgeTo=35&Page={myFriendPage}", 
    		"TargetFrame=", 
    		"Resource=0", 
    		"RecContentType=text/html", 
    		"Referer=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
    		"Snapshot=t204.inf", 
    		"Mode=HTML", 
    		LAST);
		
    	lr_message( lr_eval_string( "{friendID_count}" ) );

    	x = atoi( lr_eval_string( "{friendID_count}" ) );

    	for( c=1; c<x+1; c++ )
    	{
    		sprintf( tmpString, "%d", c );
    		lr_save_string( tmpString, "c" );
    		lr_save_string( lr_eval_string( lr_eval_string( "{friendID_{c}}" ) ), "friendIDstring" );

    		sprintf( tmpString, "%s", lr_eval_string( "{friendIDstring}" ) );

    		lr_message( tmpString );

    		if( c>1 )
    		{
    			if( strcmp( tmpString, lastString ) != 0 )
    			{
    				// Unique String
    				sprintf( friendArray[friendCounter++], "%s", tmpString );
    			}
    		}

    		sprintf( lastString, "%s", tmpString );
    	}

    	lr_message( lr_eval_string( "{friendPages}" ) );

    	sprintf( tmpString, "%lu", friendCounter );

    	lr_message( tmpString );

		for( c=0; c<friendCounter; c++ )
		{
			sprintf( tmpString, "%d - %s", c, friendArray[c] );
			lr_message( tmpString );
		}

		for( c=0; c<friendCounter; c++ )
		{
			sprintf( tmpString, "%d - %s", c, friendArray[c] );
			lr_message( tmpString );

			sprintf( tmpString, "***!~ Search Loop Page = %d, Friend Count = %d", i, c );
			lr_message( tmpString );

          	MSF10_Friends_Add( friendArray[c] );

			noFriends++;
		}

    	lr_end_transaction("SearchLoop",LR_AUTO);

    	lr_think_time(3);

		lr_message( "***!~ COMPLETED LOOP ~!***" );

		for( c=0; c<friendCounter; c++ )
		{
			sprintf( tmpString, "%d - %s", c, friendArray[c] );
			lr_message( tmpString );
		}

		friendCounter=0;
	}

	return 0;
}
