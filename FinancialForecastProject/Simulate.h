/*
	Written by Madison Liddell
	8/5/2016
	For Simulation Analysis & Design Team Project

	Simulate class is like a utility class that can simulate different situations on the data. The data are a user's expenses, income, etc. It can simulate values over time for things like bills and expenses using normal distribution. So a user can simulate their account state days or months from current.
*/
#pragma once
#include <ctime> 
#include <iostream>
#include <cmath>
#include <random>

class Simulate
{
public:
	Simulate();
	~Simulate();
	int getTotalExpenses();
	int getMoneyLeftOver();
	int generateRandomBetween(int min, int max);
	double normalDistribution(double mean, double stdDev);
	void updateSimulation();
private:
	int savingsPercent;
	int salary;		// should this be apart of this class? I was thinking a "user" class maybe
	int totalSavings;
	int leftOverMoney;
	int expenses[];
};

