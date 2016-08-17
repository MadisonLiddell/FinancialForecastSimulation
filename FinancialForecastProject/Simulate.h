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
#include <list>
#include "View.h"
#include "Budget.h"

class Simulate
{
public:
	Simulate();
	Simulate(int months);
	~Simulate();
	int generateRandomBetween(int min, int max);
	double normalDistribution(double mean, double stdDev);
	bool getIsComplete() const;
	void setIsComplete(bool is_complete);
	void simulate(int totalMonths);
	View* getView() const;
	void setView(View* view);
	Budget* getBudget() const;
	void setBudget(Budget* budget);

private:
	bool isComplete = false;
protected:
	View* view;
	Budget* budget;
};

