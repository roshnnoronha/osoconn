
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
    drawDocSidebar('privacy');
    ?>
    </div>
	<div class="container col-sm-9">	
        <h2> Privacy Policy </h2>
        <p>
        This Privacy Policy explains our practices regarding data collection, usage, and disclosure.
        </p>
        <p>
        <b>Information We Do Not Collect</b>
        We respect your privacy and do not collect, store, or share any personal information, browsing data, or usage analytics. Our web app operates without requiring user registration, cookies, or tracking technologies.
        </p>
        <p>
        <b>Third-Party Links and Services</b>
        Our web app may contain links to third-party websites or services. Please be aware that we are not responsible for the privacy practices of those third parties. We encourage you to review their privacy policies before interacting with their services.
        </p>
        <p>
        <b>Security</b>
        Since we do not collect or store user data, there is no risk of unauthorized access, data breaches, or misuse of personal information through our app.
        </p>
        <p>
        <b>Changes to This Privacy Policy</b>
        We may update this Privacy Policy from time to time. Any changes will be posted on this page with an updated effective date.
        </p>
        <p>
        By using our web app, you agree to the terms of this Privacy Policy.
        </p>.	
    </div>
    </div>
    </div>
    <?php
    drawFooter();
    ?>
</body>
</html>
