# Sample code for accelerometer

This is the sample code for using the accelerometer. Here is a [link to our webpage](https://jentronic.dk/content/17-accelerometer-kode-eksempel), with danish translation of the example.<br />

# Wiring
Tool for generating labels for letters - using LibreOffice Writer and customer data from Prestashop.<br />

![Wiring](/Images/Accelerometer-Schematic-Colored.png)

# How to use Build Letter?

First start is all about gaining access to your PrestaShop database, and preparing needed templates:<br /><br />
<ol>
<li>Run "Build Letter.ps1" using PowerShell.</li>
<li>Fill in the database information - for your PrestaShop database, and hit the "Save Settings" button.</li>
<li>Modify the LibreOffice Writer templates, located within the Templates folder.</li>
</ol>
<br />
Now Build Letter is ready for use, so for each label needed, all you do is:<br /><br />
<ol>
<li>Run "Build Letter.ps1" using PowerShell.</li>
<li>Enter a valid order ID, from your PrestaShop webshop.</li>
<li>Select which type of address to retrieve, and which template to use - and click the "Generate" button.</li>
<li>LibreOffice will now open the new label for final modification - i.e entering of the postage code.</li>
<li>Save the new label, and click the "Print Label" button.
</ol><br />

# Running code before and after printing 

Some printers may need special configuration, in order to print the labels - or perhaps you just need to run some code when printing.

If running additional code is needed, you may edit the "Functions.ps1" file, and create new functions, that will run automatically, when a specific printer is used:

Before-[printer_name]: <span style="color:gray;font-size:0.8em">*(Code is running before printing)*</span><br />
After-[printer_name]: <span style="color:gray;font-size:0.8em">*(Code is running after printing)*</span>

(Note that spaces " " in [printer_name] must be replaced with underscores "_". )