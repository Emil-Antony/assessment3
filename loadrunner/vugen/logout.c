logout()
{

	web_add_cookie("__utmb=78382081.10.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_url("logout", 
		"URL=https://demowebshop.tricentis.com/logout", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/onepagecheckout", 
		"Snapshot=t84.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}