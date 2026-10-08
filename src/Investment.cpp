#include "Investment.h"
#include <stdexcept>

// Constants are all upper case, per the standards doc
const int MONTHS_PER_YEAR = 12;
const double PERCENT_DIVISOR = 100.0;

// Start every value at zero
Investment::Investment()
    : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterest(0.0),
    m_numberOfYears(0)
{
}
// Save the initial investment, but only if it is positive
void Investment::setInitialInvestment(double t_initialInvestment)
{
    if (t_initialInvestment <= 0.0)
    {
        throw std::invalid_argument("Initial investment must be a positive number.");
    }
    m_initialInvestment = t_initialInvestment;
}

// Save the monthly deposit, but only if it is positive
void Investment::setMonthlyDeposit(double t_monthlyDeposit)
{
    if (t_monthlyDeposit <= 0.0)
    {
        throw std::invalid_argument("Monthly deposit must be a positive number.");
    }
    m_monthlyDeposit = t_monthlyDeposit;
}

// Save the annual interest rate, but only if it is positive
void Investment::setAnnualInterest(double t_annualInterest)
{
    if (t_annualInterest <= 0.0)
    {
        throw std::invalid_argument("Annual interest must be a positive number.");
    }
    m_annualInterest = t_annualInterest;
}

// Save the number of years, but only if it is positive
void Investment::setNumberOfYears(int t_numberOfYears)
{
    if (t_numberOfYears <= 0)
    {
        throw std::invalid_argument("Number of years must be a positive number.");
    }
    m_numberOfYears = t_numberOfYears;
}

// Getters just hand back the stored values
double Investment::getInitialInvestment() const
{
    return m_initialInvestment;
}
double Investment::getMonthlyDeposit() const
{
    return m_monthlyDeposit;
}

double Investment::getAnnualInterest() const
{
    return m_annualInterest;
}

int Investment::getNumberOfYears() const
{
    return m_numberOfYears;
}

// Builds one row per year. Pass true to add the monthly deposit each month.
std::vector<YearlyResult> Investment::calculateYearlyResults(bool t_includeDeposits) const
{
    // The balance starts at the initial investment
    double balance = m_initialInvestment;

    // Use the monthly deposit only if the report needs it
    double deposit = 0.0;
    if (t_includeDeposits)
    {
        deposit = m_monthlyDeposit;
    }

    // Turn the yearly percent into a monthly decimal rate
    double monthlyRate = (m_annualInterest / PERCENT_DIVISOR) / MONTHS_PER_YEAR;

    std::vector<YearlyResult> results;

    for (int year = 1; year <= m_numberOfYears; ++year)
    {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= MONTHS_PER_YEAR; ++month)
        {
            double total = balance + deposit;             // opening amount plus deposit
            double monthlyInterest = total * monthlyRate; // interest earned this month
            balance = total + monthlyInterest;            // closing balance becomes next opening
            yearlyInterest += monthlyInterest;            // keep a running total for the year
        }

        // Save this year's row (rounding happens later, when we print)
        YearlyResult row;
        row.year = year;
        row.yearEndBalance = balance;
        row.yearEndInterest = yearlyInterest;
        results.push_back(row);
    }

    return results;
}