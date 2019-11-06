MSF01_Friends_Search( char *searchFirstName )
{

	lr_save_string( searchFirstName, "searchFirstName" );

	lr_start_transaction("SearchLink");

	web_add_cookie("MYSPACE=myspace; DOMAIN=search.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=search.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=search.myspace.com");

	lr_continue_on_error (1);

	web_url("index.cfm_2", 
		"URL=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://home.myspace.com/index.cfm?fuseaction=user&DERDB=ZG9tYWluPWhvdG1haWwmdGxkPWNvbSZzbW9rZXI9MCZzZXhwcmVmPTEmc2VyaW91c3JlbGF0aW9uc2hpcHM9MSZyZWxpZ2lvbmlkPTAmcmVnaW9uPSZwb3N0YWxjb2RlPTkxNzY1Jm1hcml0YWxzdGF0dXM9UyZpbmNvbWVpZD00JmhlaWdodD0xNzUmZ2VuZGVyPU0mZnJpZW5kcz0xJmV0aG5pY2lkPS0xJmFnZT0yNyZib2R5dHlwZWlkPTImY2hpbGRyZW5pZD0xJmNvdW50cnk9VVMmZGF0aW5nPTEmZHJpbmtlcj0xJmVkdWNhdGlvbmlkPTM=&setonlinenow=1", 
		"Snapshot=t200.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_continue_on_error (0);

	lr_end_transaction("SearchLink",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Search");

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

	// Correlate - Friend Pages
    web_reg_save_param(
		"friendPages", 
       	"LB=<td>1-10 of ",
		"RB=</td>", 
		"ORD=1",
		LAST);

	/*
	index.cfm?fuseaction=find&Mytoken=20050713091837&circuitaction=search&searchType=network&f_first_name=lauren&InterestType=&f_search_criteria=&noDetail=0&first=No&Major=&Clubs=&CurrentCourses=&noDetail=0&Country=&distance=-1&Postal=91765&Photos=1&Gender=2&AgeFrom=18&AgeTo=35&Page=6846
	*/

	web_url("index.cfm_3", 
		"URL=http://www.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}&circuitaction=search&searchType=network&f_first_name={searchFirstName}&InterestType=&f_search_criteria=&noDetail=0&first=No&Major=&Clubs=&CurrentCourses=&noDetail=0&Country=&distance=-1&Postal=91765&Photos=1&Gender=2&AgeFrom=18&AgeTo=35&Page=0", 
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

		/*
		if( c>1 )
		{
			if( strcmp( tmpString, lastString ) != 0 )
			{
				// Unique String
				sprintf( friendArray[friendCounter++], "%s", tmpString );
			}
		}
		*/

		sprintf( lastString, "%s", tmpString );
	}

	lr_message( lr_eval_string( "{friendPages}" ) );

	sprintf( tmpString, "%lu", friendCounter );

	lr_message( tmpString );

	lr_end_transaction("Search",LR_AUTO);

	lr_think_time(3);

	sprintf( tmpString, "%s", lr_eval_string( "{friendPages}" ) );

	lr_message( tmpString );

	MSF05_Friends_Search_Loop( tmpString );

	return 0;
}
