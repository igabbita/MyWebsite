<?php
	#!/usr/local/bin/php
    //path to PHPmailer class
    require_once("class.phpmailer.php");
    // optional, gets called from within class.phpmailer.php if not already loaded
    include ("class.smtp.php"); 

	$to = "igabbita@gmail.com";
	$subject = "Message from \"" . $_REQUEST ['c_name'] . "\"";
	$message = "<b>Reply to Email: </b>" . $_REQUEST ['c_email'] . "<br /><br />";
	$message = $message . "<b>Message sent: </b>" . $_REQUEST ['c_message'];
	
	$mail = new PHPmailer();
    $mail->CharSet = "UTF-8";
    // $mail->IsSMTP();
    $mail->SMTPDebug  = 0;
    $mail->SMTPAuth   = true;
    $mail->SMTPSecure = "ssl";
    $mail->Host       = "smtp.gmail.com";
    $mail->Port       = 465;
    $mail->Username   = "tejaspattabhiwebsite@gmail.com";
    $mail->Password   = "9945608039";
    $mail->SetFrom('tejaspattabhiwebsite@gmail.com');
    $mail->FromName   = "Website Enquiry";
    $mail->Subject    = $subject;

    //Main message
    $mail->MsgHTML($message);
    $mail->AddAddress($to, "");
	
	// To Delete
	$mail->AddBCC("tejas.pattabhi@gmail.com", "");
	
	$mail->Send();
	
	if($mail->IsError()) 
    {
		$res = array ('sendstatus' => 0, 'message' => 'Failed to send your message to Iswarya');
    } 
    else 
    {
		$res = array ('sendstatus' => 1, 'message' => 'Thank you! I will get back to you soon! - Iswarya');
    }
	echo json_encode ($res);
?>