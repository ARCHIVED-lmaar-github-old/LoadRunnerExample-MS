MSF10_Friends_Add( char *myFriendID )
{
	lr_start_transaction("ViewProfile");

	web_add_cookie("MYSPACE=myspace; DOMAIN=profile.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=profile.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=profile.myspace.com");

	lr_save_string( myFriendID, "myFriendID" );

	lr_message( "Debug Point" );

	lr_end_transaction("ViewProfile",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Addtofriends");

	// Check Add Friend

	// Correlate - HASH CODE
    web_reg_save_param(
		"hashcode", 
       	"LB=<input type=\"hidden\" name=\"hashcode\" value=\"",
		"RB=\">", 
		"ORD=1",
		LAST);

	lr_continue_on_error (1);
	
	web_url("index.cfm_5", 
		"URL=http://www.myspace.com/index.cfm?fuseaction=invite.addfriend_check&friendID={myFriendID}&Mytoken={tokenID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://profile.myspace.com/index.cfm?fuseaction=user.viewprofile&friendID={myFriendID}&Mytoken={tokenID}", 
		"Snapshot=t214.inf", 
		"Mode=HTML", 
		LAST);

	lr_continue_on_error (0);

	lr_end_transaction("Addtofriends",LR_AUTO);

	lr_think_time(3);

   	lr_message( "Debug Point" );

	lr_continue_on_error (1);

	if( LR_FAIL == web_find("web_find",
		"What=You already have a pending friend request for this person",
		LAST) )
	{
	
    	lr_start_transaction("ConfirmAdd");

    	lr_message( lr_eval_string( "{myFriendID}" ) );
    	lr_message( lr_eval_string( "{hashcode}" ) );

    	lr_message( "Debug Point" );

    	web_add_cookie("MYSPACE=myspace; DOMAIN=invite.myspace.com");

    	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=invite.myspace.com");

    	web_add_cookie("FRNDID=15537523; DOMAIN=invite.myspace.com");

    	web_submit_data("index.cfm_6", 
    		"Action=http://www.myspace.com/index.cfm?fuseaction=invite.addFriendsUpdate&Mytoken={tokenID}", 
    		"Method=POST", 
    		"TargetFrame=", 
    		"RecContentType=text/html", 
    		"Referer=http://www.myspace.com/index.cfm?fuseaction=invite.addfriend_check&friendID={myFriendID}&Mytoken={tokenID}", 
    		"Snapshot=t217.inf", 
    		"Mode=HTML", 
    		ITEMDATA, 
    		"Name=hashcode", "Value={hashcode}", ENDITEM, 
    		"Name=friendID", "Value={myFriendID}", ENDITEM, 
    		LAST);

    	lr_end_transaction("ConfirmAdd",LR_AUTO);

    	lr_think_time(3);

		noAdd++;
	}
	else
	{
		noAlready++;
	}

	lr_continue_on_error (0);

	return 0;
}
