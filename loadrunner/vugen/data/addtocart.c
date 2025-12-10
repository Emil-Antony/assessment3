addtocart()
{

	web_add_cookie("__utmb=78382081.9.10.1765354749; DOMAIN=demowebshop.tricentis.com");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	lr_think_time(9);

	web_url("cart", 
		"URL=https://demowebshop.tricentis.com/cart", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/notebooks", 
		"Snapshot=t82.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-icons_222222_256x240.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-icons_888888_256x240.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-bg_highlight-soft_75_cccccc_1x100.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-bg_glass_75_e6e6e6_1x400.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-bg_glass_75_dadada_1x400.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-icons_454545_256x240.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		"Url=/Content/jquery-ui-themes/smoothness/images/ui-bg_glass_65_ffffff_1x400.png", "Referer=https://demowebshop.tricentis.com/Content/jquery-ui-themes/smoothness/jquery-ui-1.10.3.custom.min.css", ENDITEM, 
		LAST);

	web_submit_data("cart_2", 
		"Action=https://demowebshop.tricentis.com/cart", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"RecContentType=text/html", 
		"Referer=https://demowebshop.tricentis.com/cart", 
		"Snapshot=t83.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=itemquantity6124369", "Value=1", ENDITEM, 
		"Name=discountcouponcode", "Value=", ENDITEM, 
		"Name=giftcardcouponcode", "Value=", ENDITEM, 
		"Name=CountryId", "Value=0", ENDITEM, 
		"Name=StateProvinceId", "Value=0", ENDITEM, 
		"Name=ZipPostalCode", "Value=", ENDITEM, 
		"Name=termsofservice", "Value=on", ENDITEM, 
		"Name=checkout", "Value=checkout", ENDITEM, 
		LAST);

	return 0;
}
