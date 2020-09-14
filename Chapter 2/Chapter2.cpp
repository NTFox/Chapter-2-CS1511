#include <iostream>

using namespace std;


//User input
int hoursWorked, numberOfDependents;
//Integer Variables
int unionDues, dependentCosts, overtimeHours;
//float Variables for decimal points
double grossPay, payRate, netPay, socialSecurityTax, federalIncomeTax, stateIncomeTax;


int main() {
	//Magical formula from the book for making doubles have a a precision of 2
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	//Stating float variables locally since main() is our only function
	payRate = 16.78;
	


	//Ask for User Input of Hours worked and Dependents
	cout << "Hello, welcome to the Payment Calculator please enter\n" << "Hours Worked \n";
	cin >> hoursWorked;
	cout << "Number of dependents\n";
	cin >> numberOfDependents;

	//Calculate Overtime. If hoursWorked > 40, multiply excess by overtimeRate and add it to final Gross
	if (hoursWorked > 40) {
		overtimeHours = hoursWorked - 40;
		grossPay = (40 * payRate) + (overtimeHours * payRate * 1.5);
	}
	else grossPay = payRate * hoursWorked;

	//From grossPay, take out Social security, Federal tax, state income tax and $10 per week for union dues. 
	socialSecurityTax = grossPay * 0.06;
	federalIncomeTax = grossPay * 0.14;
	stateIncomeTax = grossPay * 0.05;
	unionDues = 10;

	netPay = grossPay - socialSecurityTax - federalIncomeTax - stateIncomeTax - unionDues;

	//If worker has 3+ dependents, take antoher $35 for health insurance
	if (numberOfDependents > 3)
		netPay = netPay - 35;
	

	//Cout the sad reality of TAXES and DEPENDENTS
	cout << "Your Gross Pay is $" << grossPay << "\nSocial Security Tax (6%) $" << socialSecurityTax << "\nFederal Income Tax (14%) $" << federalIncomeTax << "\nState Income Tax (5%) $"
		<< stateIncomeTax << "\nUnion dues withheld $" << unionDues;

	//Change final cout based on number of dependents
	if (numberOfDependents > 3)
		cout << "\nAnother $35 was withheld to cover the extra cost of health insurance beyond what your employer pays";
	
	//Net pay
	cout << "\nYour net take home pay is $" << netPay << "\n";


}