Airgead Banking App
CS 210 Project Two: Pseudocode
Tyler Jordan
Plan for the investment growth calculator

Overview
The program asks the user for four values. It then shows two reports. One report has no monthly deposits. The other report includes the monthly deposits. The user can run it again with new numbers.
The program has three parts: an Investment class for the data and math, a Display class for screens and input, and a small main function that runs the loop.

1. main()
Create an Investment object
Create a Display object
Set keepRunning to true
Start a try block
While keepRunning is true
Call display.showInputScreen
Call display.getInputs and store the values in the Investment object
Call display.showInputValues
Call display.waitForKey
Call investment.calculateYearlyResults with includeDeposits set to false
Call display.showReport with the title "Balance and Interest Without Additional Monthly Deposits"
Call investment.calculateYearlyResults with includeDeposits set to true
Call display.showReport with the title "Balance and Interest With Additional Monthly Deposits"
Call display.askToContinue and store the answer in keepRunning
End while
Catch any unexpected error
Print a message with the error
End program with an error code
End try
End program

2. Class Investment
Constants
Set MONTHS_PER_YEAR to 12
Set PERCENT_DIVISOR to 100

Private data
Store m_initialInvestment
Store m_monthlyDeposit
Store m_annualInterest
Store m_numberOfYears

Constructor
Set every private value to zero

Setter functions
Set each value from its t_ parameter
If the value is not positive, throw an error

Getter functions
Return the stored value

calculateYearlyResults(t_includeDeposits)
Set balance to m_initialInvestment
If t_includeDeposits is true
Set deposit to m_monthlyDeposit
Else
Set deposit to zero
End if
Set monthlyRate to (m_annualInterest divided by PERCENT_DIVISOR) divided by MONTHS_PER_YEAR
Create an empty list called results
For each year from 1 to m_numberOfYears
Set yearlyInterest to zero
For each month from 1 to MONTHS_PER_YEAR
Set total to balance plus deposit
Set monthlyInterest to total times monthlyRate
Set balance to total plus monthlyInterest
Add monthlyInterest to yearlyInterest
End for
Add year, balance, and yearlyInterest to results
End for
Return results

3. Class Display
showInputScreen
Print a line of asterisks
Print the title "Data Input" inside asterisks

getInputs(t_investment)
Call readPositiveDouble for the initial investment and save it in t_investment
Call readPositiveDouble for the monthly deposit and save it in t_investment
Call readPositiveDouble for the annual interest and save it in t_investment
Call readPositiveInt for the number of years and save it in t_investment

readPositiveDouble(t_prompt)  [private helper]
Repeat until a good value is entered
Print t_prompt
Read a full line of text from the user
Start a try block
Convert the text to a decimal number
If there is extra text after the number, throw an error
If the number is zero or negative, throw an error
Return the number
Catch the error
Print "Please enter a positive number."
End try
End repeat

readPositiveInt(t_prompt)  [private helper]
Repeat until a good value is entered
Print t_prompt
Read a full line of text from the user
Start a try block
Convert the text to a whole number
If there is extra text after the number, throw an error
If the number is zero or negative, throw an error
Return the number
Catch the error
Print "Please enter a positive whole number."
End try
End repeat

showInputValues(t_investment)
Print the screen header again
Print each value the user entered
Format money and percent with two decimal places

waitForKey
Print "Press Enter to continue . . ."
Wait for the user to press Enter

showReport(t_title, t_results)
Print the report title
Print a line of equal signs
Print the column headers
Print a line of dashes
For each row in t_results
Print year, year end balance, and year end interest
Format money with two decimal places
End for

askToContinue
Repeat until the answer is good
Ask "Try new numbers? (y/n)"
Read the answer and change it to lower case
If the answer is y or yes, return true
If the answer is n or no, return false
Else print "Please type y or n."
End repeat
