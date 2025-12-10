Register()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_add_cookie("__utmb=78382081.3.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_url("demowebshop.tricentis.com", 
		"URL=http://demowebshop.tricentis.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/images/top-menu-divider.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/images/bullet-right.gif", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/images/star-x-active.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/images/star-x-inactive.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Plugins/Widgets.NivoSlider/Content/nivoslider/themes/default/loading.gif", "Referer=https://demowebshop.tricentis.com/Plugins/Widgets.NivoSlider/Content/nivoslider/themes/default/default.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/images/ui-bg_flat_75_ffffff_40x100.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/images/top-menu-triangle.png", "Referer=https://demowebshop.tricentis.com/Themes/DefaultClean/Content/styles.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Plugins/Widgets.NivoSlider/Content/nivoslider/themes/default/arrows.png", "Referer=https://demowebshop.tricentis.com/Plugins/Widgets.NivoSlider/Content/nivoslider/themes/default/default.css", ENDITEM, 
		"Url=https://demowebshop.tricentis.com/Plugins/Widgets.NivoSlider/Content/nivoslider/themes/default/bullets.png", "Referer=https://demowebshop.tricentis.com/Plugins/Widgets.NivoSlider/Content/nivoslider/themes/default/default.css", ENDITEM, 
		LAST);


	web_link("Register", 
		"Text=Register", 
		"Snapshot=t73.inf", 
		LAST);

	web_add_cookie("__utma=78382081.1076200954.1765354749.1765354749.1765354749.1; DOMAIN=demowebshop.tricentis.com");

	web_add_cookie("__utmc=78382081; DOMAIN=demowebshop.tricentis.com");

	web_add_cookie("__utmz=78382081.1765354749.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none); DOMAIN=demowebshop.tricentis.com");

	web_add_cookie("__utmt=1; DOMAIN=demowebshop.tricentis.com");

	web_add_cookie("__utmb=78382081.1.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_submit_data("register", 
		"Action=https://demowebshop.tricentis.com/register", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/register", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=__RequestVerificationToken", "Value=VTHaWnEYZTV6BzN0_5u1scFmoalVgGtRyx67Eo2bz6ItHSqy51q3jK_HCAixWiSaVtJbHRVp1H0itGJuD5_yOOy9kHYKdDFoTOhBGo3ARYg1", ENDITEM, 
		"Name=Gender", "Value=M", ENDITEM, 
		"Name=FirstName", "Value=Aguero", ENDITEM, 
		"Name=LastName", "Value=Agnes", ENDITEM, 
		"Name=Email", "Value={email}", ENDITEM, 
		"Name=Password", "Value={password}", ENDITEM, 
		"Name=ConfirmPassword", "Value={password}", ENDITEM, 
		"Name=register-button", "Value=Register", ENDITEM, 
		LAST);

	web_add_cookie("__utmb=78382081.2.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	
//
//	web_link("Log out", 
//		"Text=Log out", 
//		"Snapshot=t76.inf", 
//		LAST);

	return 0;
}
