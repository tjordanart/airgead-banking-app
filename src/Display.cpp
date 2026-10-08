#include "Display.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

// Constants are all upper case, per the standards doc
const std::string STAR_LINE = "**********************************";
const std::string HEADER_LINE = "********** Data Input ************";

// Prints the top banner for the input screen
void Display::showInputScreen() const
{
    std::cout << STAR_LINE << std::endl;
    std::cout << HEADER_LINE << std::endl;
}

// Asks for each value and saves it in the Investment object
void Display::getInputs(Investment& t_investment) const
{
    t_investment.setInitialInvestment(readPositiveDouble("Initial Investment Amount: $"));
    t_investment.setMonthlyDeposit(readPositiveDouble("Monthly Deposit: $"));
    t_investment.setAnnualInterest(readPositiveDouble("Annual Interest (%): "));
    t_investment.setNumberOfYears(readPositiveInt("Number of years: "));
}

// Shows the banner again, this time with the user's values filled in
void Display::showInputValues(const Investment& t_investment) const
{
    std::cout << std::endl;
    std::cout << STAR_LINE << std::endl;
    std::cout << HEADER_LINE << std::endl;

    // Money and percent show two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Initial Investment Amount: $" << t_investment.getInitialInvestment() << std::endl;
    std::cout << "Monthly Deposit: $" << t_investment.getMonthlyDeposit() << std::endl;
    std::cout << "Annual Interest: " << t_investment.getAnnualInterest() << "%" << std::endl;
    std::cout << "Number of years: " << t_investment.getNumberOfYears() << std::endl;
}

// Pauses until the user presses Enter
void Display::waitForKey() const
{
    std::cout << "Press Enter to continue . . .";
    std::cin.get();
    std::cout << std::endl;
}

// Prints one report table
void Display::showReport(const std::string& t_title,
    const std::vector<YearlyResult>& t_results) const
{
    // Money shows two decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Title and column headers
    std::cout << "  " << t_title << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::left << std::setw(8) << "Year"
        << std::setw(24) << "Year End Balance"
        << "Year End Earned Interest" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    // One row per year
    for (const YearlyResult& row : t_results)
    {
        std::cout << std::left << std::setw(8) << row.year
            << "$" << std::setw(23) << row.yearEndBalance
            << "$" << row.yearEndInterest << std::endl;
    }
    std::cout << std::endl;
}

// Asks the user if they want to run again
bool Display::askToContinue() const
{
    while (true)
    {
        std::cout << "Try new numbers? (y/n): ";
        std::string answer;
        std::getline(std::cin, answer);

        // Make the answer lower case so "Y" and "y" both work
        std::transform(answer.begin(), answer.end(), answer.begin(),
            [](unsigned char t_letter) { return static_cast<char>(std::tolower(t_letter)); });

        if (answer == "y" || answer == "yes")
        {
            return true;
        }
        if (answer == "n" || answer == "no")
        {
            return false;
        }
        std::cout << "Please type y or n." << std::endl;
    }
}

// Keeps asking until the user types a positive number
double Display::readPositiveDouble(const std::string& t_prompt) const
{
    while (true)
    {
        std::cout << t_prompt;
        std::string line;
        std::getline(std::cin, line);

        try
        {
            std::size_t charsUsed = 0;
            double value = std::stod(line, &charsUsed);

            // Reject leftover text like "5abc", and reject zero, negatives, and infinity
            if (charsUsed != line.size() || value <= 0.0 || !std::isfinite(value))
            {
                throw std::invalid_argument("Not a positive number.");
            }
            return value;
        }
        catch (const std::exception&)
        {
            // Covers letters, blanks, and bad values
            std::cout << "Please enter a positive number." << std::endl;
        }
    }
}

// Keeps asking until the user types a positive whole number
int Display::readPositiveInt(const std::string& t_prompt) const
{
    while (true)
    {
        std::cout << t_prompt;
        std::string line;
        std::getline(std::cin, line);

        try
        {
            std::size_t charsUsed = 0;
            int value = std::stoi(line, &charsUsed);

            // Reject leftover text like "5.5", and reject zero and negatives
            if (charsUsed != line.size() || value <= 0)
            {
                throw std::invalid_argument("Not a positive whole number.");
            }
            return value;
        }
        catch (const std::exception&)
        {
            std::cout << "Please enter a positive whole number." << std::endl;
        }
    }
}