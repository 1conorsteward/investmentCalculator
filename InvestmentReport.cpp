#include "InvestmentReport.h"

#include <iostream>
#include <iomanip>
/*
Conor Steward
11/21/23
This file is used to present the two reports to the customers. One including monthly depostis and another not including monthly deposits
conor.steward@snhu.edu
*/

using namespace std;

void InvestmentReport::displayStaticReports(const InvestmentCalculator& calculator) {
    // Constants
    const int monthsInYear = 12;

    // Output header for static reports
    std::cout << "Year-End Balances Without Additional Monthly Deposits:\n";
    std::cout << "======================================================\n";
    std::cout << "\tYear\tYear End Balance\tYear End Earned Interest\n";

    // Calculate and display year-end balances and earned interest without additional deposits
    double openingAmount = calculator.getInitialInvestment();
    double earnedInterestTotal = 0.0;
    for (int year = 1; year <= calculator.getNumOfYears(); ++year) {
        double total = openingAmount;
        double yearlyInterest = total * (calculator.getAnnualInterestRate() / 100);
        earnedInterestTotal += yearlyInterest;
        double closingBalance = total + yearlyInterest;

        // Display details for the current year
        std::cout << year << "\t"
                  << std::fixed << std::setprecision(2)
                  << closingBalance << "\t\t"
                  << yearlyInterest << "\n";

        // Update opening amount for the next year
        openingAmount = closingBalance;
    }

    // Output header for static reports with additional monthly deposits
    std::cout << "\nYear-End Balances (With Monthly Deposits of $" << calculator.getMonthlyDeposit() << "):\n";
    std::cout << "Year\tEnding Balance\tEarned Interest\n";

    // Calculate and display year-end balances and earned interest with additional deposits
    openingAmount = calculator.getInitialInvestment();
    earnedInterestTotal = 0.0;
    for (int year = 1; year <= calculator.getNumOfYears(); ++year) {
        double total = openingAmount + (calculator.getMonthlyDeposit() * monthsInYear);
        double yearlyInterest = total * (calculator.getAnnualInterestRate() / 100);
        earnedInterestTotal += yearlyInterest;
        double closingBalance = total + yearlyInterest;

        // Display details for the current year
        std::cout << year << "\t"
                  << std::fixed << std::setprecision(2)
                  << closingBalance << "\t\t"
                  << yearlyInterest << "\n";

        // Update opening amount for the next year
        openingAmount = closingBalance;
    }
}
