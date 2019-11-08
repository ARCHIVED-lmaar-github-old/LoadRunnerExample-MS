Login()
{

	web_add_cookie("DERDB=ZG9tYWluPWhvdG1haWwmdGxkPWNvbSZzbW9rZXI9MCZzZXhwcmVmPTEmc2VyaW91c3JlbGF0aW9uc2hpcHM9MSZyZWxpZ2lvbmlkPTAmcmVnaW9uPSZwb3N0YWxjb2RlPTkxNzY1Jm1hcml0YWxzdGF0dXM9UyZpbmNvbWVpZD00JmhlaWdodD0xNzUmZ2VuZGVyPU0mZnJpZW5kcz0xJmV0aG5pY2lkPS0xJmFnZT0yNyZib2R5dHlwZWlkPTImY2hpbGRyZW5pZD0xJmNvdW50cnk9VVMmZGF0aW5nPTEmZHJpbmtlcj0xJmVkdWNhdGlvbmlkPTM%3D; DOMAIN=myspace.com");

	web_add_cookie("MYSPACE=myspace; DOMAIN=myspace.com");

	web_add_cookie("TIMEZONE=2; DOMAIN=myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=myspace.com");

	web_add_cookie("ME=laurence%5Fmaar%40hotmail%2Ecom; DOMAIN=myspace.com");

	web_url("myspace.com", 
		"URL=http://myspace.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t187.inf", 
		"Mode=HTTP", 
		LAST);

	lr_start_transaction("Login");

	web_add_cookie("MYSPACE=myspace; DOMAIN=home.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=home.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=home.myspace.com");

	// Correlate - Token ID
    web_reg_save_param(
		"tokenID", 
       	"LB=Mytoken=",
		"RB=\">", 
		LAST);

	web_submit_data("index.cfm", 
		"Action=http://myspace.com/index.cfm?fuseaction=login.process", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://myspace.com/", 
		"Snapshot=t193.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=email", "Value=laurence_maar@hotmail.com", ENDITEM, 
		"Name=password", "Value=asdh!293*", ENDITEM, 
		"Name=Remember", "Value=Remember", ENDITEM, 
		"Name=Submit22.x", "Value=13", ENDITEM, 
		"Name=Submit22.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(3);

	return 0;
}
