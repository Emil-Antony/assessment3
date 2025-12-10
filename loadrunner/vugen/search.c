search()
{

	web_add_cookie("__utmb=78382081.7.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_add_cookie("__utmb=78382081.8.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_url("notebooks", 
		"URL=https://demowebshop.tricentis.com/notebooks", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/computers", 
		"Snapshot=t80.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/Themes/DefaultClean/Content/images/ico-arrow-r.gif", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=/Themes/DefaultClean/Content/images/ajax_loader_large.gif", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=/content/images/thumbs/0000224_141-inch-laptop_47.png", ENDITEM, 
		LAST);

	web_custom_request("1", 
		"URL=https://demowebshop.tricentis.com/addproducttocart/catalog/31/1/1", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://demowebshop.tricentis.com/notebooks", 
		"Snapshot=t81.inf", 
		"Mode=HTML", 
		"EncType=", 
		EXTRARES, 
		"Url=/Themes/DefaultClean/Content/images/ico-close-notification-bar.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		LAST);

	return 0;
}
