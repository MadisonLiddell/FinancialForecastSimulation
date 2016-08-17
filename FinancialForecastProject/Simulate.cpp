#include "Simulate.h"
#include <string>
#include <sstream>
#include "View.h"
#include "Budget.h"


Simulate::Simulate()
{
}


Simulate::Simulate(int months)
{

}

Simulate::~Simulate()
{
}

// Returns a random number between min and max
int Simulate::generateRandomBetween(int min, int max)
{
	srand(unsigned(time(nullptr)));
	return (rand() % max) + min;
}

// Returns the normal distribution using passed mean and standard deviation
double Simulate::normalDistribution(double mean, double stdDev)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(mean, stdDev);
	return d(gen);
}

bool Simulate::getIsComplete() const
{
	return isComplete;
}

void Simulate::setIsComplete(bool is_complete)
{
	isComplete = is_complete;
}

// Runs budget simulation for months times
void Simulate::simulate(int months)
{
	// first check if expenses are entered and income?
	view->viewAmounts();
	// generate random value using distribution for utilities each month needed?
	for (int i = 0; i < months; i++)
	{
		
	}
	// set percent to save each month
	budget->setSavingspercent();
	// run calculations for budget
	budget->calculateLeftOverMoney();
	budget->calculateSavings();
	// show budget
	budget->displayBudget();
}


View* Simulate::getView() const
{
	return view;
}

void Simulate::setView(View* view)
{
	this->view = view;
}

Budget* Simulate::getBudget() const
{
	return budget;
}

void Simulate::setBudget(Budget* budget)
{
	this->budget = budget;
}
