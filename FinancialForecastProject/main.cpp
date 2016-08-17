// FinancialForecastProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Simulate.h"
#include "View.h"
#include "Budget.h"

/* Main application entry point */
int main()
{
	// Jason Budget class
	Budget budget;
	// Josh View class
	View view;
	// Madison Simulation class
	Simulate simulation;
	simulation.setBudget(&budget);

	view.setSimulation(&simulation);
	view.setBudget(&budget);


	while (!simulation.getIsComplete())
	{
		view.showOptionsMenu();
	}


	system("pause");
    return 0;
}

