#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H
/*
Conor Steward
11/21/23
This file is used to define the functions for the investment calulator
conor.steward@snhu.edu
*/

class InvestmentCalculator {
public:
	//Constructor
	InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numOfYears);

	//Function to calculate and display investment details
	void calculateInvestment() const;

	//Getter functions
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getAnnualInterestRate() const;
	int getNumOfYears() const;
//Private functions for variables
private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterestRate;
	int numOfYears;
};

#endif //INVESTMENT_CALCULATOR_H