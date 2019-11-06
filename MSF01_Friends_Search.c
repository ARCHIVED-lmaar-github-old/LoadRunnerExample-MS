MSF01_Friends_Search( char *searchFirstName )
{

	lr_save_string( searchFirstName, "searchFirstName" );

/*
	web_url("adServerA.php", 
		"URL=http://ads.peel.com/peelMedia/adServerA.php?noPop=1&ws=myspace.com&ps=1&noWin=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://demr.mspaceads.com/html.ng/site=myspace&position=mrec&page=11000000&rand=429031196", 
		"Snapshot=t198.inf", 
		"Mode=HTML", 
		LAST);

	web_url("cre217819798.html", 
		"URL=http://ads.peel.com/peelMediaAds/13202/cre217819798.html?w=10188&newwin=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://demr.mspaceads.com/html.ng/site=myspace&position=mrec&page=11000000&rand=429031196", 
		"Snapshot=t199.inf", 
		"Mode=HTML", 
		LAST);
*/
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

/*
	web_add_cookie("NGUserID=ac120683-21236-1118126253-5; DOMAIN=delb.mspaceads.com");

	web_add_cookie("n=g; DOMAIN=delb.mspaceads.com");

	web_add_cookie("defc=BvgAAAFvOASFAAACbzgEGwAABnA4BCsAAAhzOAQqAAACiDgEJwAAAcE9BIwA; DOMAIN=delb.mspaceads.com");

	web_url("site=myspace&position=leaderboard&page=19001001&rand=212932320", 
		"URL=http://delb.mspaceads.com/html.ng/site=myspace&position=leaderboard&page=19001001&rand=212932320", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
		"Snapshot=t201.inf", 
		"Mode=HTML", 
		LAST);
*/
/*
	web_add_cookie("MYSPACE=myspace; DOMAIN=de.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=de.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=de.myspace.com");

	web_url("site=myspace&page=10000000&position=test&ord=1507634886", 
		"URL=http://de.myspace.com/html.ng/site=myspace&page=10000000&position=test&ord=1507634886?", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
		"Snapshot=t202.inf", 
		"Mode=HTML", 
		LAST);
*/
/*
	web_add_cookie("testbounce=\"testing\"; DOMAIN=ad.yieldmanager.com");

	web_add_cookie("ih=\"b!!!#A!!!%f!!!!#8GrV4!!!%g!!!!#8H0>!!!!%h!!!!$8Jo).!!!)A!!!!#8K#By!!!)H!!!!#8K#Cf!!!)J!!!!#8KV=h!!!+t!!!!'8KU.#!!!,@!!!!#8GrRj!!!./!!!!#8KV@G!!!/5!!!!#8Go7:!!!/x!!!!#8H$!/!!!2+!!!!$8K.2C!!!2R!!!!#8LU?Q!!!2g!!!!$8LU>y!!!4V!!!!$8H#x$!!!6*!!!!#8Grbq!!!6:!!!!#8H$.%!!!6Q!!!!#8G_)A!!!7-!!!!#8Go7%!!!7v!!!!#8H(F:!!!7x!!!!(8IY*$!!!8R!!!!#8H0m'!!!:d!!!!#8K#BR!!!<Q!!!!#8K%1n!!!?9!!!!#8KcLI!!#cX!!!!#8GrNV!!#dq!!!!#8KU.,!!#fe!!!!*8K_ig!!#fj!!!!#8IYOs!!#he!!!!#8H(D9!!#i@!!!!#8K%,F!!#mD!!!"
		"!#8GrbG!!#n9!!!!#8KcP_!!#o<!!!!#8Go6k!!#oD!!!!#8K+@1!!#qn!!!!$8LU@(!!#r6!!!!#8LU?g!!#r7!!!!%8LV)1!!#rV!!!!#8K%F9!!#rW!!!!#8KUXW!!#rl!!!!#8K+T#!!#sK!!!!#8Go7D!!#tV!!!!#8KV7B!!#t[!!!!#8H$$*!!#u%!!!!#8Gne(!!#v7!!!!#8K+SZ!!#vB!!!!#8Gr-]!!#vU!!!!#8GrP@!!#v`!!!!#8KU.t!!#w,!!!!$8H0m_!!#wD!!!!#8KUWX!!#wF!!!!)8LU?v!!#wN!!!!#8K#CN!!#wQ!!!!#8H(:?!!#wv!!!!#8IY)d!!#xD!!!!#8H0m9!!#xV!!!!#8H0m#!!#x[!!!!(8H1+T!!%KU!!!!#8Jy2A!!%K^!!!!#8Grb`!!%Nq!!!!#8Gn?.!!%Nr!!!!#8KU./!!%Pj!!!!%8KcN`!!%QE!!!!%8K%IP!!%QW!!!!#8IY+!"
		"!!%SG!!!!%8KcNO!!%Sn!!!!#8Gr-*!!%TI!!!!#8H(<9!!%U9!!!!#8GrPT!!%U?!!!!#8Grc)!!%V9!!!!#8Jy2<!!%WC!!!!$8KUY.!!%WH!!!!#8Gr-^!!%Wm!!!!#8GrS0!!%X+!!!!#8G_*C!!%[P!!!!#8Gg*B!!%^%!!!!(8LU?o!!%^4!!!!#8Go7A!!%^u!!!!#8Go6s!!%_e!!!!'8K%IR!!%`C!!!!#8LU@(!!%aU!!!!#8K#Eu!!%a`!!!!$8H1+!!!%dZ!!!!#8K#Bi!!(8'!!!!#8K.4u!!(8L!!!!%8KUY?!!(8g!!!!$8KcMj!!(8n!!!!#8H(9A!!(92!!!!$8LaHI!!(9J!!!!$8K%GG!!(9U!!!!$8LU?H!!(9c!!!!#8H#wQ!!(=b!!!!#8K%3^!!(>+!!!!#8H(79!!(>N!!!!#8Go9s!!(?/!!!!#8LU1:!!(?0!!!!$8KU-o!!(?>!!!!#8K+S]!!(?@!!"
		"!!#8KUV5!!(@H!!!!$8IY)1!!(@Z!!!!#8K#E`!!(A*!!!!#8K%HX!!(DV!!!!$8KU-_!!(Df!!!!*8Go?1!!(E5!!!!#8KV*)!!(E]!!!!#8H$!i!!(F(!!!!#8K+@<!!(Fg!!!!#8H$,d!!(HH!!!!(8LaHW!!(HM!!!!#8KcOa!!(HZ!!!!#8IY*m!!(I/!!!!#8H0h7!!(IZ!!!!#8IY)N!!(Kr!!!!#8K#Bb\"; DOMAIN=ad.yieldmanager.com");

	web_add_cookie("pv1=\"b!!!!.!!!)X~!!!O/!!(>N!!!9<~!?5%!$qF:0#<rm.!!!D4!!!:_!!!!/!!!R=~~~~8Go9s8L+$%~!!!+%~!!!29!!#fe!!!'!~!#W(2'k4l:![:Z,!!!0n!!!0+~~~~~~8K_ig8f#@M~!?mRw~!!!O(!!%Wm!!!>7~!?5%!'k>r6!ZmB(!!!,?!!!X+~~~~~~8GrS08L.>:~!?mRy~!!!O(!!%Wm!!!>7~!?5%!'k>r6!ZmB(!!!,?!!!X+~~~~~~8GrS08L.>:~!!!*d~!!!Y<!!(9c!!!?k!!!%#!?5%!%5kJ2!wVd-!!!D4!!!:_!!!ZC~~~~~8H#wQ8L7b[~!!!*f~!!!Y<!!(9c!!!?k!!!%#!?5%!%5kJ2!wVd-!!!D4!!!:_!!!ZC~~~~~8H#wQ8L7b[~!!!/P~!!!)[!!(9U!!!H$~!#a.3)H`=:!ZmB(!!!,?!!!hF~~~~~~8LU?H8Pi)R!!!%Q!!"
		"!%<~!!!)[!!(=b!!!AQ!!!%#!?5%!*b<tA!ZmB(!!!,?!!!]V~~~~~~8K%3^8K20/~!!!.e~!!!)[!!(=b!!!AQ!!!%#!?5%!*b<tA!ZmB(!!!,?!!!]V~~~~~~8K%3^8K%3^~!!!+=~!!!)[!!!2R!!!<e~!?5%!)H`=9!w1K)!!!,?!!!!/!!!Ul~~~~~8LU?Q8Pi)[!!!NB!!!0.~!!!O(!!(92!!!(C~!#a.3(h109![:Z,!!!,?!!!:6~~~~~~8LaHI8Lash!!!!a\"; DOMAIN=ad.yieldmanager.com");

	web_add_cookie("vh=\"b!!!!#!!!'T~~\"; DOMAIN=ad.yieldmanager.com");

	web_add_cookie("bh=\"b!!!!#!!!'T!!!!*8K^/H\"; DOMAIN=ad.yieldmanager.com");

	web_add_cookie("lh=\"b!!!!%!!!Yg8LgFl!!!:68LgF^!!!Ul8Lb<!\"; DOMAIN=ad.yieldmanager.com");

	web_add_cookie("lf=\"b!!!!(!!!:6!!!!#!!!Ul!!!!#!!!Us~!!!Yg!!!!#!!!^8~\"; DOMAIN=ad.yieldmanager.com");

	web_url("imp", 
		"URL=http://ad.yieldmanager.com/imp?z=6&s=3660&t=3", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://delb.mspaceads.com/html.ng/site=myspace&position=leaderboard&page=19001001&rand=212932320", 
		"Snapshot=t203.inf", 
		"Mode=HTML", 
		LAST);
*/
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
/*
	web_url("index.cfm_3", 
		"URL=http://www.myspace.com/index.cfm?fuseaction=find&circuitaction=search&searchType=network&interesttype=&country=&searchBy=First&f_first_name=lauren&Submit=Find", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
		"Snapshot=t204.inf", 
		"Mode=HTML", 
		LAST);
*/
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

/*
	web_url("site=myspace&position=leaderboard&page=19001001&rand=523845803", 
		"URL=http://delb.mspaceads.com/html.ng/site=myspace&position=leaderboard&page=19001001&rand=523845803", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.myspace.com/index.cfm?fuseaction=find&circuitaction=search&searchType=network&interesttype=&country=&searchBy=First&f_first_name=lauren&Submit=Find", 
		"Snapshot=t205.inf", 
		"Mode=HTML", 
		LAST);
*/

/*
	web_url("UsersOnline.html_3", 
		"URL=http://onlinenow.myspace.com/UsersOnline.html?UserIDList=683,3102,9284,10020,13014,13755,15726,16229,16329,18836", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.myspace.com/index.cfm?fuseaction=find&circuitaction=search&searchType=network&interesttype=&country=&searchBy=First&f_first_name=lauren&Submit=Find", 
		"Snapshot=t206.inf", 
		"Mode=HTML", 
		LAST);

*/
/*
	web_add_cookie("adrevid=4223d091; DOMAIN=media.adrevolver.com");

	web_add_cookie("prefs=50-20-0-0-0+150-9-5-0-0+60-21-1-0-0+160-82-0-0-0; DOMAIN=media.adrevolver.com");

	web_add_cookie("freq=1121214725278+3-3+0-0+0-0+1-1+1-1+2-2+1-2+2-3+2-3+0-0+0-3+4-6+2-6+4-6+4-4+0-0+0-0+0-0+0-0+0-1+1-2+0-0+0-0+0-0+0-0+0-0+0-0+1-2+2-2+3-3+1-3; DOMAIN=media.adrevolver.com");

	web_add_cookie("uid=1799796134415585; DOMAIN=media.adrevolver.com");

	web_add_cookie("gai=131842; DOMAIN=media.adrevolver.com");

	web_add_cookie("prefs=50-20-0-0-0+150-16-5-0-0+60-22-1-0-0+160-82-0-0-0; DOMAIN=media.adrevolver.com");

	web_url("banner", 
		"URL=http://media.adrevolver.com/adrevolver/banner?place=1779&cpy=98556", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://delb.mspaceads.com/html.ng/site=myspace&position=leaderboard&page=19001001&rand=523845803", 
		"Snapshot=t207.inf", 
		"Mode=HTML", 
		LAST);

	web_url("NATIONAL.xml", 
		"URL=http://www.delta-offers.com/dr_banners/NATIONAL.xml?cacheKiller=1121214805986", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t208.inf", 
		"Mode=HTML", 
		LAST);
*/
	lr_end_transaction("Search",LR_AUTO);

	lr_think_time(3);


	sprintf( tmpString, "%s", lr_eval_string( "{friendPages}" ) );

	lr_message( tmpString );

	MSF05_Friends_Search_Loop( tmpString );

	return 0;
}
