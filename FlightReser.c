FlightReser()
{

	int i;
	
	lr_output_message("Itertion number is %s",lr_eval_string("{pIterationCount}"));
	lr_output_message("GIt");
		lr_output_message("Second Commit");
		lr_output_message("Third Commit");
	
		
	lr_log_message("From Country is %s and To country is %s",lr_eval_string("{pFromCountry}"),lr_eval_string("{pToCountry}"));
	
	lr_output_message("Load Genarator name is %s", lr_eval_string("{pLGName}"));
	lr_output_message("Tomorrows Date is %s",lr_eval_string("{pDate}"));
	// TODO complete this scirpt 
	// UNDONE 
	// FIXME correlation
	
	web_url("blazedemo.com", 
		"URL={pUrl}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(10);

	lr_start_transaction("01_SelectCountry");

	web_submit_data("reserve.php", 
		"Action={pUrl}/reserve.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={pUrl}/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=fromPort", "Value={pFromCountry}", ENDITEM, 
		"Name=toPort", "Value={pToCountry}", ENDITEM, 
		LAST);

	lr_end_transaction("01_SelectCountry",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("02_SelectFlight");

	web_submit_data("purchase.php", 
		"Action={pUrl}/purchase.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={pUrl}/reserve.php", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flight", "Value=9696", ENDITEM, 
		"Name=price", "Value=200.98", ENDITEM, 
		"Name=airline", "Value=Aer Lingus", ENDITEM, 
		"Name=fromPort", "Value={pFromCountry}", ENDITEM, 
		"Name=toPort", "Value={pToCountry}", ENDITEM, 
		LAST);

	lr_end_transaction("02_SelectFlight",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("03_Purchase");

	web_submit_data("confirmation.php", 
		"Action={pUrl}/confirmation.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={pUrl}/purchase.php", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_token", "Value=", ENDITEM, 
		"Name=inputName", "Value=dw", ENDITEM, 
		"Name=address", "Value=k", ENDITEM, 
		"Name=city", "Value=k", ENDITEM, 
		"Name=state", "Value=k", ENDITEM, 
		"Name=zipCode", "Value=k", ENDITEM, 
		"Name=cardType", "Value=visa", ENDITEM, 
		"Name=creditCardNumber", "Value=k", ENDITEM, 
		"Name=creditCardMonth", "Value=k", ENDITEM, 
		"Name=creditCardYear", "Value=k", ENDITEM, 
		"Name=nameOnCard", "Value=l", ENDITEM, 
		LAST);

	lr_end_transaction("03_Purchase",LR_AUTO);

	return 0;
}