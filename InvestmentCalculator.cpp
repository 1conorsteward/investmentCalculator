#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>
#include <cmath>
/*
Conor Steward
11/21/23
This file is used to calcualte the varying displayables for the reports
conor.steward@snhu.edu
*/

using namespace std;

InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numOfYears) : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit), annualInterestRate(annualInterestRate), numOfYears(numOfYears) {}

void InvestmentCalculator::calculateInvestment() const {
	//Number of months in the year
	const int monthsInYear = 12;

	//Header
	std::cout << "Month\tOpening Amount\tDeposited Amount\tTotal\tInterest\tClosing Balance\n" << std::endl;

    // Calculate and display investment details for each month
    double openingAmount = initialInvestment;
    for (int month = 1; month <= numOfYears * monthsInYear; ++month) {
        double total = openingAmount + monthlyDeposit;
        double monthlyInterest = total * (annualInterestRate / 100) / monthsInYear;
        double closingBalance = total + monthlyInterest;

        // Display details for the current month
        std::cout << month << "\t"
                  << std::fixed << std::setprecision(2)
                  << openingAmount << "\t\t"
                  << monthlyDeposit << "\t\t"
                  << total << "\t"
                  << monthlyInterest << "\t"
                  << closingBalance << "\n";

        // Update opening amount for the next month
        openingAmount = closingBalance;
    }
}

double InvestmentCalculator::getInitialInvestment() const {
    return initialInvestment;
}

double InvestmentCalculator::getMonthlyDeposit() const {
    return monthlyDeposit;
}

double InvestmentCalculator::getAnnualInterestRate() const {
    return annualInterestRate;
}

int InvestmentCalculator::getNumOfYears() const {
    return numOfYears;
}