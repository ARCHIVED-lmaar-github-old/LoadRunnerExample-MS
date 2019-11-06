MSF10_Friends_Add( char *myFriendID )
{
	lr_start_transaction("ViewProfile");

	web_add_cookie("MYSPACE=myspace; DOMAIN=profile.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=profile.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=profile.myspace.com");

	lr_save_string( myFriendID, "myFriendID" );

	lr_message( "Debug Point" );

	/*
	web_url("index.cfm_4", 
		"URL=http://profile.myspace.com/index.cfm?fuseaction=user.viewprofile&friendID={myFriendID}&Mytoken={tokenID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.myspace.com/index.cfm?fuseaction=find&circuitaction=search&searchType=network&interesttype=&country=&searchBy=First&f_first_name=lauren&Submit=Find", 
		"Snapshot=t209.inf", 
		"Mode=HTML", 
		LAST);
	*/
/*
	web_url("site=myspace&position=leaderboard&page=11013005&rand=307746927", 
		"URL=http://delb.mspaceads.com/html.ng/site=myspace&position=leaderboard&page=11013005&rand=307746927", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://profile.myspace.com/index.cfm?fuseaction=user.viewprofile&friendID={myFriendID}&Mytoken={tokenID}", 
		"Snapshot=t210.inf", 
		"Mode=HTML", 
		LAST);
*/
/*
	web_url("UsersOnline.html_3", 
		"URL=http://onlinenow.myspace.com/UsersOnline.html?UserIDList=9284,19073,71511,119301,133342,167253,172038,189450,194684,1957409,12141204,3948805,3108683,3613906,11843100,9552229,4798770,2834130,3277152,1685735,4857401,2641369,8386804,5231202,339220,6610306,3410734,526648,6688032,2015734,8778674,2947217,3383436,6665407,2447121,3727039,2063278,3229871,4168377,1289996,4001259,4726338,2762365", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://profile.myspace.com/index.cfm?fuseaction=user.viewprofile&friendID={myFriendID}&Mytoken={tokenID}", 
		"Snapshot=t211.inf", 
		"Mode=HTML", 
		LAST);

	web_url("poster.jpg", 
		"URL=http://i2.photobucket.com/albums/y26/kbranch/poster.jpg", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://profile.myspace.com/index.cfm?fuseaction=user.viewprofile&friendID={myFriendID}&Mytoken={tokenID}", 
		"Snapshot=t212.inf", 
		"Mode=HTML", 
		LAST);
*/
/*
	web_add_cookie("as=46be8d87-0164-445f-8ac2-2f622d62768f; DOMAIN=adsvr.adknowledge.com");

	web_url("get_ad.cgi", 
		"URL=http://adsvr.adknowledge.com/get_ad.cgi?pid=usamedia&tg=test&sz=728x90&skn=I&fm=F&fid=0&ran=gopeVEKQhIE4I8ZP&ref=http%253A//profile.myspace.com/index.cfm%253Ffuseaction%253Duser.viewprofile%2526friendID%253D9284%2526Mytoken%253D20050712173325&clickUrl=http%3A%2F%2Fmedia.fastclick.net%2Fw%2Fclick.here%3Fcid%3D32264%26mid%3D69817%26sid%3D21511%26m%3D1%26c%3D0%26forced_click=&ue=n", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://delb.mspaceads.com/html.ng/site=myspace&position=leaderboard&page=11013005&rand=307746927", 
		"Snapshot=t213.inf", 
		"Mode=HTML", 
		LAST);
*/
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
