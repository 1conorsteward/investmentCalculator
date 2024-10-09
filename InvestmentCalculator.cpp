#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>

/*
Programmer: Conor Steward
Contact: 1conorsteward@gmail.com
Date: 10/8/24
Version: 2.0
Purpose: This file calculates various investment outcomes, including regular investment, Dividend Reinvestment Plan (DRP), and High-Risk vs Low-Risk comparisons.
Issues: No known issues.
Runtime Complexities: 
    - Regular Investment Calculation: O(n), where n = number of months.
    - Dividend Reinvestment Plan: O(n), where n = number of years.
    - High-Risk vs Low-Risk Strategy Comparison: O(n), where n = number of years.
*/

// Constructor for the regular investment strategy
// Purpose: Initializes the investment calculator with basic investment parameters.
// Complexity: O(1)
InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numOfYears)
    : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit), annualInterestRate(annualInterestRate), numOfYears(numOfYears), highRiskRate(0.0), lowRiskRate(0.0) {}

// Overloaded constructor to include high-risk and low-risk rates
// Purpose: Initializes the investment calculator with additional high-risk and low-risk rates.
// Complexity: O(1)
InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, 
                                           double highRiskRate, double lowRiskRate, int numOfYears)
    : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit), annualInterestRate(annualInterestRate), 
      highRiskRate(highRiskRate), lowRiskRate(lowRiskRate), numOfYears(numOfYears) {}

// Function to calculate and display investment details
// Purpose: Calculates the total investment growth based on monthly deposits and an annual interest rate.
// Complexity: O(n), where n is the total number of months.
void InvestmentCalculator::calculateInvestment() const {
    const int monthsInYear = 12;
    std::cout << "Month\tOpening Amount\tDeposited Amount\tTotal\tInterest\tClosing Balance\n" << std::endl;

    double openingAmount = initialInvestment;

    for (int month = 1; month <= numOfYears * monthsInYear; ++month) {
        double total = openingAmount + monthlyDeposit;
        double monthlyInterest = total * (annualInterestRate / 100) / monthsInYear;
        double closingBalance = total + monthlyInterest;

        std::cout << month << "\t"
                  << std::fixed << std::setprecision(2)
                  << openingAmount << "\t\t"
                  << monthlyDeposit << "\t\t"
                  << total << "\t"
                  << monthlyInterest << "\t"
                  << closingBalance << "\n";

        openingAmount = closingBalance;
    }
}

// Function for Dividend Reinvestment Plan (DRP)
// Purpose: Simulates the growth of an investment when dividends are reinvested.
// Complexity: O(n), where n is the number of years.
void InvestmentCalculator::calculateDividendReinvestment(double dividendYield, double stockPriceGrowthRate) const {
    double totalShares = initialInvestment;
    double stockPrice = 100.0;  // Example initial stock price
    double investmentValue = initialInvestment;

    for (int year = 1; year <= numOfYears; ++year) {
        double dividends = totalShares * (dividendYield / 100);
        double additionalShares = dividends / stockPrice;
        totalShares += additionalShares;

        stockPrice += stockPrice * (stockPriceGrowthRate / 100);
        investmentValue = totalShares * stockPrice;

        std::cout << "Year " << year << ": Total Shares = " << std::fixed << std::setprecision(2)
                  << totalShares << ", Stock Price = $" << stockPrice
                  << ", Investment Value = $" << investmentValue << "\n";
    }
}

// Function for High-Risk vs Low-Risk strategy comparison
// Purpose: Compares the outcomes of high-risk and low-risk investment strategies.
// Complexity: O(n), where n is the number of years.
void InvestmentCalculator::calculateRiskStrategies() const {
    double highRiskAmount = initialInvestment;
    double lowRiskAmount = initialInvestment;

    for (int year = 1; year <= numOfYears; ++year) {
        highRiskAmount += highRiskAmount * (highRiskRate / 100);
        lowRiskAmount += lowRiskAmount * (lowRiskRate / 100);

        std::cout << "Year " << year << ": High-Risk Balance = $" << std::fixed << std::setprecision(2)
                  << highRiskAmount << ", Low-Risk Balance = $" << lowRiskAmount << "\n";
    }
}

// Getter functions
// Purpose: Retrieves respective investment attributes.
// Complexity: O(1)
double InvestmentCalculator::getInitialInvestment() const { return initialInvestment; }
double InvestmentCalculator::getMonthlyDeposit() const { return monthlyDeposit; }
double InvestmentCalculator::getAnnualInterestRate() const { return annualInterestRate; }
double InvestmentCalculator::getHighRiskRate() const { return highRiskRate; }
double InvestmentCalculator::getLowRiskRate() const { return lowRiskRate; }
int InvestmentCalculator::getNumOfYears() const { return numOfYears; }
