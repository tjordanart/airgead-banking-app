# Airgead Banking App

**Academic Project · SNHU · CS-210: Programming Languages**

A C++ investment calculator that models compound interest and compares investment growth with and without recurring monthly deposits.

## Overview

Airgead Banking App was developed for a fictional banking scenario as part of my C++ coursework at Southern New Hampshire University.

Users enter an initial investment, monthly deposit, annual interest rate, and investment duration. The program calculates projected investment growth and generates yearly reports showing balances and interest earned under two scenarios: with and without additional monthly deposits.

The application uses object-oriented design to separate user interaction and reporting from investment calculations.

## Features

- Initial investment and monthly deposit inputs
- Annual interest rate and investment duration inputs
- Monthly compound interest calculations
- Year-by-year investment growth reports
- Comparison of growth with and without monthly deposits
- Input validation and error handling
- Rejection of invalid, negative, and non-finite numeric values
- Formatted currency and percentage output
- Option to perform additional calculations
- Separate classes for user interaction and investment calculations
- Named constants instead of unexplained numeric values

## Example Output

The following example illustrates the application's report format using a $1,000 initial investment, $100 monthly deposits, a 5% annual interest rate, and a five-year period.

```text
Balance and Interest Without Additional Monthly Deposits
=========================================================
Year    Year End Balance    Year End Earned Interest
---------------------------------------------------------
1       $1051.16            $51.16
2       $1104.71            $53.55
3       $1159.76            $55.05
4       $1216.55            $56.79
5       $1275.31            $58.76

Balance and Interest With Additional Monthly Deposits
=========================================================
Year    Year End Balance    Year End Earned Interest
---------------------------------------------------------
1       $2308.90            $108.90
2       $3670.13            $161.23
3       $5101.24            $231.11
4       $6534.92            $333.68
5       $8078.31            $443.39
```

*Example output reproduced from the project documentation.*

## Input Validation

The application validates user input before performing calculations. Invalid entries prompt the user to try again.

Validation includes:

- Positive initial investment and monthly deposit amounts
- Positive annual interest rate
- Positive whole-number investment
