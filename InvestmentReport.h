#ifndef INVESTMENT_REPORT_H
#define INVESTMENT_REPORT_H
/*
Conor Steward
11/21/23
This file is used to define the functions for the investment reports
conor.steward@snhu.edu
*/

#include "InvestmentCalculator.h"

class InvestmentReport {
public:
    // Function to display static reports
    static void displayStaticReports(const InvestmentCalculator& calculator);
};

#endif // INVESTMENT_REPORT_H
