#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

/*
Programmer: Conor Steward
Contact: 1conorsteward@gmail.com
Date: 10/8/24
Version: 2.0
Purpose: This header file defines the interface for the `InvestmentCalculator` class, which calculates various investment strategies, including Dividend Reinvestment Plan (DRP) and High-Risk vs Low-Risk strategy comparison.
Issues: No known issues.
*/

// Class to calculate various investment outcomes
class InvestmentCalculator {
public:
    // Constructor for regular investment strategy
    // Purpose: Initializes the calculator with basic investment parameters.
    // Complexity: O(1)
    InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numOfYears);

    // Overloaded constructor for adding high-risk and low-risk rates
    // Purpose: Initializes the calculator with high-risk and low-risk investment parameters.
    // Complexity: O(1)
    InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, 
                         double highRiskRate, double lowRiskRate, int numOfYears);

    // Function to calculate and display regular investment details
    // Purpose: Calculates the growth of regular investments based on monthly deposits and interest.
    // Complexity: O(n), where n is the total number of months.
    void calculateInvestment() const;

    // Function to calculate Dividend Reinvestment Plan (DRP)
    // Purpose: Calculates investment growth using dividends reinvested into additional shares.
    // Complexity: O(n), where n is the number of years.
    void calculateDividendReinvestment(double dividendYield, double stockPriceGrowthRate) const;

    // Function to calculate high-risk vs low-risk investment strategies
    // Purpose: Compares the results of high-risk and low-risk strategies.
    // Complexity: O(n), where n is the number of years.
    void calculateRiskStrategies() const;

    // Getter functions
    // Purpose: Retrieves respective investment attributes.
    // Complexity: O(1) for all getters.
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterestRate() const;
    double getHighRiskRate() const;
    double getLowRiskRate() const;
    int getNumOfYears() const;

private:
    // Data members
    double initialInvestment;   // The initial amount invested
    double monthlyDeposit;      // The amount deposited monthly
    double annualInterestRate;  // The annual interest rate for the investment
    double highRiskRate;        // The annual growth rate for high-risk investments
    double lowRiskRate;         // The annual growth rate for low-risk investments
    int numOfYears;             // The total number of years for the investment
};

#endif //INVESTMENT_CALCULATOR_H
