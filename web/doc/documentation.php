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
    drawDocSidebar('about');
    ?>
    </div>
	<div class="container col-sm-9">	
        <h2>About Osoconn</h2>
		<p>
        Osoconn is a free and open source steel connection design application authored by Roshn Noronha. The program can be used as either a 
        web app or downloaded and run as a command line app (CLA). The objective of the Osoconn Project is to develop a 
        calculation repository of the various types of connection details used in steel fabrication.
        The source-code for Osoconn is available  under the MIT open-source license and
         can be downloaded from its <a href="https://github.com/roshnnoronha/osoconn" target="_blank">github repository</a>.  
        </p>
        <p>        
        While using Osoconn, you agree to have read and accepted our <a href="doc_terms_of_use.php">terms of use</a> and <a href="doc_privacy.php">privacy policy</a>.
        </p>
        <p>
        You may contact the author through his <a href="https://www.linkedin.com/in/roshn-noronha-19ba9217/" target="_blank">Linkedin</a> page.
        You may also report any bugs through the <a href="https://github.com/roshnnoronha/osoconn/issues" target="_blank">issues</a> page in github. 
        </p>
        <hr><h4>Disclaimer & Limitation of Liability</h4>
        <p>
        <b>1. General Disclaimer</b> Osoconn ("the App") is provided on an "as-is" and "as-available" basis. While we strive to ensure accuracy 
            and reliability, we make no representations or warranties of any kind, express or implied, regarding the App’s operation, data, 
            or results generated.
        </p>
        <p>
        <b>2. No Professional Advice</b> The App is intended for informational and educational purposes only. It does not constitute professional 
            advice, and users should verify results with qualified professionals before making any decisions based on the App’s output.
        </p>
        <p>
        <b>3. Limitation of Liability</b> To the fullest extent permitted by law, the author and contributors 
            shall not be liable for any direct, indirect, incidental, consequential, or special damages arising from: (a) Use or inability to 
            use the App. (b) Inaccuracies or errors in calculations or results. (c) Any reliance on information provided by the App. 
            (d) Data loss, system failures, or unauthorized access to user data.
        </p>
        <p>
        <b>4. Indemnification</b> By using the App, you agree to indemnify and hold harmless the author  and contributors 
            from any claims, damages, or liabilities arising from your use of the App.
        </p>
        <p>
        <b>5. Changes to This Disclaimer </b>We reserve the right to modify this Disclaimer at any time. Updates will be posted on this page, 
            and continued use of the App constitutes acceptance of any changes.

        </p>
    </div>
    </div>
    </div>
    <?php
    drawFooter();
    ?>
</body>
</html>
