<?php
require_once '../util/common.php';

?>
<!DOCTYPE html>
<html lang ="en">
<head>
    <?php
    printHeader();
    ?>
</head>
<body>
	<?php
	drawNavBar('doc');
	?>
    <div class="container">
    <div class="row">
    <div class="col-sm-3">
    <?php
    drawDocSidebar('terms');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>Terms of Use </h2>
        <p>
        <b>1. Introduction</b>
        Welcome to Osoconn ("the App"). By accessing or using the App, you agree to comply with these Terms of Use. If you do not agree to these terms, please do not use the App.
        </p>
        <p>
        <b>2. Purpose</b>
        The App is designed for educational purposes, providing engineering students and professionals with tools and resources to enhance their learning and skills. The content provided is for informational purposes only and should not be used for professional engineering decisions without verification.
        </p>
        <p>
        <b>3. User Responsibilities</b>
        </p>
        <p>
        (a) Users must be at least 13 years old to access the App.
        </p>
        <p>
        (b) Users agree to use the App ethically and in accordance with all applicable laws and regulations.

        </p>
        <p>
        (c) Users shall not misuse the App, including engaging in unauthorized access, distributing malware, or violating intellectual property rights.

        </p>
        <p>
        <b>4. Intellectual Property</b>
        All content, including but not limited to text, software, graphics, and tools, is owned by or licensed to the App and is protected by copyright and intellectual property laws. Users may use the content for educational and non-commercial purposes but may not reproduce, distribute, or modify it without permission.

        </p>
        <p>
        <b>5. Limitation of Liability</b>
        The App is provided "as is" without warranties of any kind. While we strive to provide accurate and useful information, we do not guarantee the completeness or reliability of any content. We are not responsible for any loss, damage, or inconvenience resulting from the use of the App.

        </p>
        <p>
        <b>6. Third-Party Links</b>
        The App may contain links to third-party websites or resources. We are not responsible for the availability, accuracy, or content of third-party sites and do not endorse any services or products offered by them.

        </p>
        <p>
        <b>7. Modifications to Terms</b>
        We reserve the right to update or modify these Terms of Use at any time. Continued use of the App after changes are posted constitutes acceptance of the revised terms.

        </p>
        <p>
        <b>8. Termination</b>
        We may suspend or terminate access to the App if users violate these Terms of Use or engage in activities that harm the App or its users.
        </p>
    </div>
    </div>
    </div>
    <?php
    drawFooter();
    ?>
</body>
</html>
