#ifndef INVESTMENT_REPORT_H
#define INVESTMENT_REPORT_H

/*
Programmer: Conor Steward
Contact: 1conorsteward@gmail.com
Date: 10/8/24
Version: 2.0
Purpose: This header file defines the interface for the `InvestmentReport` class, which generates reports for various investment strategies, including regular investment, Dividend Reinvestment Plan (DRP), and High-Risk vs Low-Risk comparison.
Issues: No known issues.
*/

// Include the InvestmentCalculator class
#include "InvestmentCalculator.h"

// Class to generate investment reports
class InvestmentReport {
public:
    // Function to display static reports (without and with monthly deposits)
    // Purpose: Displays year-end balances for investments, both with and without monthly deposits.
    // Complexity: O(n), where n is the number of years.
    static void displayStaticReports(const InvestmentCalculator& calculator);

    // Function to display the high-risk vs low-risk strategy
    // Purpose: Compares and displays the performance of high-risk and low-risk investment strategies.
    // Complexity: O(n), where n is the number of years.
    static void displayRiskComparison(const InvestmentCalculator& calculator);

    // Function to display the dividend reinvestment strategy
    // Purpose: Displays the performance of investments using a Dividend Reinvestment Plan (DRP).
    // Complexity: O(n), where n is the number of years.
    static void displayDividendReinvestment(const InvestmentCalculator& calculator, double dividendYield, double stockPriceGrowthRate);
};

#endif // INVESTMENT_REPORT_H
