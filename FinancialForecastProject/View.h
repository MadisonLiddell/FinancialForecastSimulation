#pragma once
#include <string>
#include <vector>
#include <iostream>

class Simulate;
class Budget;

class View
{
public:
	View();
	~View();
	void outputDirections();
	void getExpenses();
	void getIncomeExpenses();
	void viewAmounts();
	void showOptionsMenu();		// display all options to user -ML
	Simulate* getSimulation();
	Budget* getBudget();
	void setBudget(Budget* budget);
	void setSimulation(Simulate* simulation);
protected:
	Simulate* simulation;
	Budget* budget;

private:
	//std::vector <int> expenseAmount;// Allows me to use array.push_back(Value);
	std::vector <std::string> expenseName; // Allows me to use array.push_back(Value);
	//std::vector <int> incomeAmount;  // Allows me to use array.push_back(Value);
	std::vector<std::string> incomeName;   // Allows me to use array.push_back(Value);

};

