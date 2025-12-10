Login()
{

	web_add_cookie("__utmb=78382081.4.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_url("login", 
		"URL=https://demowebshop.tricentis.com/login", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/", 
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("__utmb=78382081.5.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_add_cookie("__utmb=78382081.6.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_submit_data("login_2", 
		"Action=https://demowebshop.tricentis.com/login", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/login", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=Email", "Value={email}", ENDITEM, 
		"Name=Password", "Value={password}", ENDITEM, 
		"Name=RememberMe", "Value=false", ENDITEM, 
		EXTRARES, 
		"Url=/Themes/DefaultClean/Content/images/top-menu-background.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=/Themes/DefaultClean/Content/images/top-menu-list-image.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		LAST);

	web_link("Computers", 
		"Text=Computers", 
		"Ordinal=1", 
		"Snapshot=t79.inf", 
		LAST);

	return 0;
}
