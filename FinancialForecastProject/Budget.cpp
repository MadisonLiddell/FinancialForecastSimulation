#include "Budget.h"

using namespace std;

//Budget::Budget()
//{
//
//	// incomeAmount, and Expense Amounnt would be found from global variable form other classes
//	// for testing added ability to enter the monthly salary and expenses.
//	//cout << "Enter the total monthly income: " << endl;
//	//cin >> incomeAmount;
//	//cout << "Enter the total expense amount " << endl;
//	//cin >> expenseAmount;
//
//	
//	// I copied the code from here into class functions -ML
//
//	
//}


Budget::Budget()
{
}

Budget::Budget(View v, Simulate s)
{
}

Budget::~Budget()
{
}


void Budget::displayBudget()
{
	// display the budget
	std::cout << "Here is the budget for a monthly income of " << getTotalIncome() << " with " << savingsPercent << " percent being designated to savings" << std::endl;
	std::cout << "$ " << getTotalExpenses() << " designated for monthly expenses" << std::endl;
	std::cout << "$ " << savings << " designated for savings" << std::endl;
	std::cout << "$ " << leftOverMoney << " designated for left over Spending Money" << std::endl;
}


// Adds all expenses together and returns the total
double Budget::getTotalExpenses()
{
	double totalExpenses = 0;
	for (std::vector<int>::const_iterator iterator = expenseAmount.begin(); iterator != expenseAmount.end(); ++iterator)
	{
		totalExpenses += *iterator;
	}

	return totalExpenses;
}

double Budget::getTotalIncome()
{
	double totalIncome = 0;
	for (std::vector<int>::const_iterator iterator = incomeAmount.begin(); iterator != incomeAmount.end(); ++iterator)
	{
		totalIncome += *iterator;
	}

	return totalIncome;
}

// Calcs how much money is left over after expenses and savings
void Budget::calculateLeftOverMoney()
{
	initialLeftOverMoney = getTotalIncome() - getTotalExpenses();
	leftOverMoney = getTotalIncome() - getTotalExpenses();
	leftOverMoney -= salary * savingsPercent;
}

void Budget::calculateSavings()
{
	savings = (initialLeftOverMoney * savingsPercent) / 100;
	leftOverMoney = initialLeftOverMoney - savings;
}

double Budget::getSavingsPercent() 
{
	return savingsPercent;
}

void Budget::setSavingspercent()
{
	cout << "Enter the Percent of left over money you would like to designate for Savings" << endl;
	cout << endl;
	cin >> savingsPercent;
}
void Budget::setSavingsPercent(int savingsPercent)
{
	this->savingsPercent = savingsPercent;
}


int Budget::getInitialLeftOverMoney() const
{
	return initialLeftOverMoney;
}

void Budget::setInitialLeftOverMoney(int initialLeftOverMoney)
{
	this->initialLeftOverMoney = initialLeftOverMoney;
}


int Budget::getSavings() const
{
	return savings;
}


int Budget::getLeftOverMoney() const
{
	return leftOverMoney;
}

std::vector<int> Budget::getExpenseAmount() const
{
	return expenseAmount;
}

std::vector<int> Budget::getIncomeAmount() const
{
	return incomeAmount;
}

Simulate* Budget::getSimulation() const
{
	return simulation;
}

void Budget::setSimulation(Simulate* simulation)
{
	this->simulation = simulation;
}

View* Budget::getView() const
{
	return view;
}

void Budget::setView(View* view)
{
	this->view = view;
}
