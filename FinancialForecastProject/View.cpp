
#include "Simulate.h"
#include "View.h"
using namespace std;

View::View()
{
	
}


View::~View()
{
}

void View::outputDirections()
{
	cout << "Directions: " << endl;
	cout << "Enter the name of the item first, then enter a dollar amount to represent the name." << endl;
	cout << "It will ask you each time if you want to add another item. " << endl;
}

void View::getExpenses()
{
	outputDirections();
	cout << "------------------------------------------------------" << endl;
	cout << "Do you want to enter an expense amount Source: Y/N " << endl;
	char response;
	cin >> response;
	if ((response == 'Y') || (response == 'y'))
	{
		system("CLS"); // Screen is getting messy. 
		cout << "Enter expense NAME: " << endl;
		string name;
		cin.ignore(); // Clean up the CIN buffer. 
		getline(cin, name);
		
		expenseName.push_back(name);
		//cout << "test name: " << expenseName[0];  // TEST CASE


		cout << "Enter expense AMOUNT: " << endl;
		int x;
		cin >> x;
		budget->getExpenseAmount().push_back(x);
		//cout << "test amount: " << expenseAmount[0]; // TEST CASE
		getExpenses(); // Return back and ask this again, They Might have more finances. 
	}
	else if ((response == 'N') || (response == 'n'))
	{
		// Move to next option
	}

}

void View::getIncomeExpenses()
{
	outputDirections();
	cout << "------------------------------------------------------" << endl;
	cout << "Do you want to enter an Income Source: Y/N " << endl;
	char response;
	cin >> response;
	if ((response == 'Y') || (response == 'y'))
	{
		system("CLS"); // Screen is getting messy. 
		cout << "Enter income NAME: " << endl;
		string name;
		cin.ignore(); // Clean up the CIN buffer. 
		getline(cin, name);

		incomeName.push_back(name);
		//cout << "test name: " << incomeName[0];


		cout << "Enter income AMOUNT: " << endl;
		int x;
		cin >> x;
		budget->getIncomeAmount().push_back(x);
		//cout << "test amount: " << incomeAmount[0];
		getIncomeExpenses(); // Return back and ask this again, They Might have more finances. 
	}
	else if ((response == 'N') || (response == 'n'))
	{
		// Move to next option
		getExpenses();
	}
}

void View::viewAmounts()
{
	int expenseSize = budget->getExpenseAmount().size(); // Stores array since this can change depending on the amount of expeneses. 
	int incomeSize = budget->getIncomeAmount().size(); // Stores array since this can change depending on the amount of income sources. 

	int runningExpenses; int runningIncome; // Stores total "expense amount" 



											// Two loops one for each type: 
	int x = 0;
	while (x < expenseSize)
	{
		cout << "Expense Name: " << expenseName[x] << "Expense Amount: " << budget->getExpenseAmount()[x] << endl;
		x++;

	}
	x = 0;
	while (x < incomeSize)
	{
		cout << "Income Name: " << incomeName[x] << "Income Amount: " << budget->getIncomeAmount()[x] << endl;
		x++;

	}

}

void View::showOptionsMenu()
{
	std::cout << "\t\t\t*** Main Menu ***\n";
	std::cout << "Enter any one of the numbers below to choose an option\n";
	std::cout << "1 - Update income\n2 - Update expenses\n3 - Run budget forecast\n0 - Exit";
	int input = 0;
	std::cin >> input;

	switch (input) {
		case 0:
			simulation->setIsComplete(true);
			return;
		case 1:
			getIncomeExpenses();
			break;
		case 2:
			getExpenses();
			break;
		case 3:
			std::cout << "How many months in advance would you like to run the simulation for? ";
			int i;
			std::cin >> i;
			simulation->simulate(i);
			break;
		default:
			std::cout << "You may only enter a 0, 1, 2, or 3.";
			showOptionsMenu();
			break;
	}
}

Simulate* View::getSimulation()
{
	return simulation;
}

Budget* View::getBudget()
{
	return budget;
}

void View::setBudget(Budget* budget)
{
	this->budget = budget;
}

void View::setSimulation(Simulate* simulation)
{
	this->simulation = simulation;
}
