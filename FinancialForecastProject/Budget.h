#pragma once
#include <iostream>
#include "Simulate.h"
#include "View.h"

class Budget
{
public:
	Budget();
	Budget(View v, Simulate s);
	~Budget();
	double getTotalExpenses();
	double getTotalIncome();
	void displayBudget();
	void calculateLeftOverMoney();
	void calculateSavings();

	// getters and setters -ML
	double getSavingsPercent();
	void setSavingspercent();
	void setSavingsPercent(int savingsPercent);
	int getInitialLeftOverMoney() const;
	void setInitialLeftOverMoney(int initialLeftOverMoney);
	int getSavings() const;
	int getLeftOverMoney() const;
	std::vector<int> getExpenseAmount() const;
	std::vector<int> getIncomeAmount() const;
	Simulate* getSimulation() const;
	void setSimulation(Simulate* simulation);
	View* getView() const;
	void setView(View* view);

private:
	double savingsPercent;
	int initialLeftOverMoney;
	int savings;
	int leftOverMoney;
	double salary;
	std::vector <int> expenseAmount; // Allows me to use array.push_back(Value);
	std::vector <int> incomeAmount;  // Allows me to use array.push_back(Value);
protected:
	Simulate *simulation;
	View *view;
};

