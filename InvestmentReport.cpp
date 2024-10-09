#include "InvestmentReport.h"
#include <iostream>
#include <iomanip>

/*
Programmer: Conor Steward
Contact: 1conorsteward@gmail.com
Date: 10/8/24
Version: 2.0
Purpose: This file presents various reports to customers, including regular investment, Dividend Reinvestment Plan (DRP), and High-Risk vs Low-Risk strategy comparison.
Issues: No known issues.
Runtime Complexities:
    - Static Investment Report: O(n), where n = number of years.
    - Risk Comparison Report: O(n), where n = number of years.
    - Dividend Reinvestment Plan Report: O(n), where n = number of years.
*/

// Function to display year-end balances without and with monthly deposits
// Purpose: Displays year-end balances with and without monthly deposits.
// Complexity: O(n), where n is the number of years.
void InvestmentReport::displayStaticReports(const InvestmentCalculator& calculator) {
    const int monthsInYear = 12;

    // Display balances without monthly deposits
    std::cout << "Year-End Balances Without Additional Monthly Deposits:\n";
    std::cout << "======================================================\n";
    std::cout << "\tYear\tYear End Balance\tYear End Earned Interest\n";

    double openingAmount = calculator.getInitialInvestment();
    double earnedInterestTotal = 0.0;

    for (int year = 1; year <= calculator.getNumOfYears(); ++year) {
        double yearlyInterest = openingAmount * (calculator.getAnnualInterestRate() / 100);
        earnedInterestTotal += yearlyInterest;
        double closingBalance = openingAmount + yearlyInterest;

        std::cout << year << "\t" 
                  << std::fixed << std::setprecision(2)
                  << closingBalance << "\t\t"
                  << yearlyInterest << "\n";

        openingAmount = closingBalance;
    }

    // Display balances with monthly deposits
    std::cout << "\nYear-End Balances (With Monthly Deposits of $" << calculator.getMonthlyDeposit() << "):\n";
    std::cout << "Year\tEnding Balance\tEarned Interest\n";

    openingAmount = calculator.getInitialInvestment();
    earnedInterestTotal = 0.0;

    for (int year = 1; year <= calculator.getNumOfYears(); ++year) {
        double total = openingAmount + (calculator.getMonthlyDeposit() * monthsInYear);
        double yearlyInterest = total * (calculator.getAnnualInterestRate() / 100);
        earnedInterestTotal += yearlyInterest;
        double closingBalance = total + yearlyInterest;

        std::cout << year << "\t" 
                  << std::fixed << std::setprecision(2)
                  << closingBalance << "\t\t"
                  << yearlyInterest << "\n";

        openingAmount = closingBalance;
    }
}

// Function to display comparison between high-risk and low-risk strategies
// Purpose: Compares the performance of high-risk and low-risk investment strategies.
// Complexity: O(n), where n is the number of years.
void InvestmentReport::displayRiskComparison(const InvestmentCalculator& calculator) {
    std::cout << "\nComparing High-Risk and Low-Risk Strategies:\n";
    std::cout << "===========================================\n";

    // Get rates for both strategies
    double highRiskRate = calculator.getHighRiskRate();
    double lowRiskRate = calculator.getLowRiskRate();

    double highRiskAmount = calculator.getInitialInvestment();
    double lowRiskAmount = calculator.getInitialInvestment();

    for (int year = 1; year <= calculator.getNumOfYears(); ++year) {
        // Calculate high-risk and low-risk portfolio amounts
        highRiskAmount += highRiskAmount * (highRiskRate / 100);
        lowRiskAmount += lowRiskAmount * (lowRiskRate / 100);

        // Display the results for each year
        std::cout << "Year " << year << ": High-Risk Balance = $" << std::fixed << std::setprecision(2)
                  << highRiskAmount << ", Low-Risk Balance = $" << lowRiskAmount << "\n";
    }
}

// Function to display the Dividend Reinvestment Plan (DRP) report
// Purpose: Displays the performance of investments using a Dividend Reinvestment Plan (DRP).
// Complexity: O(n), where n is the number of years.
void InvestmentReport::displayDividendReinvestment(const InvestmentCalculator& calculator, double dividendYield, double stockPriceGrowthRate) {
    std::cout << "\nDividend Reinvestment Plan (DRP) Report:\n";
    std::cout << "=========================================\n";

    double totalShares = calculator.getInitialInvestment();
    double stockPrice = 100.0;  // Example initial stock price
    double investmentValue = calculator.getInitialInvestment();

    // Loop through each year to calculate reinvested dividends
    for (int year = 1; year <= calculator.getNumOfYears(); ++year) {
        // Calculate dividends earned
        double dividends = totalShares * (dividendYield / 100);

        // Reinvest dividends to buy more shares
        double additionalShares = dividends / stockPrice;
        totalShares += additionalShares;

        // Adjust stock price based on growth rate
        stockPrice += stockPrice * (stockPriceGrowthRate / 100);

        // Calculate new investment value
        investmentValue = totalShares * stockPrice;

        // Display the report for each year
        std::cout << "Year " << year << ": Total Shares = " << std::fixed << std::setprecision(2)
                  << totalShares << ", Stock Price = $" << stockPrice
                  << ", Investment Value = $" << investmentValue << "\n";
    }
}
