#include "Simulate.h"



Simulate::Simulate()
{
}


Simulate::~Simulate()
{
}

int Simulate::getTotalExpenses()
{
	int totalExpenses = 0;
	for (int i = 0; i < (sizeof(expenses)/sizeof(expenses[0])); i++)
	{
		totalExpenses += expenses[i];
	}
	return totalExpenses;
}

int Simulate::getMoneyLeftOver()
{
	leftOverMoney = salary - getTotalExpenses();
	leftOverMoney -= salary * savingsPercent;
	return leftOverMoney;
}

int Simulate::generateRandomBetween(int min, int max)
{
	srand(unsigned(time(nullptr)));
	return (rand() % max) + min;
}

double Simulate::normalDistribution(double mean, double stdDev)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(mean, stdDev);
	return d(gen);
}

// Not sure if needed or what its function will be
void Simulate::updateSimulation()
{
	// might use to loop through x amount of days or months generating random values
	// for things like grocery or doctors or gas bills

}
