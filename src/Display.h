#ifndef AIRGEAD_DISPLAY_H_
#define AIRGEAD_DISPLAY_H_

#include <string>
#include <vector>
#include "Investment.h"

// Handles everything the user sees and types
class Display
{
public:
    // Shows the empty data input screen
    void showInputScreen() const;

    // Asks for all four values and saves them in the Investment object
    void getInputs(Investment& t_investment) const;

    // Shows the values the user entered
    void showInputValues(const Investment& t_investment) const;

    // Waits for the user to press a key
    void waitForKey() const;

    // Prints one report table with a title
    void showReport(const std::string& t_title,
        const std::vector<YearlyResult>& t_results) const;

    // Asks if the user wants to try new numbers
    bool askToContinue() const;

private:
    // Helpers: keep asking until the user types a good number
    double readPositiveDouble(const std::string& t_prompt) const;
    int readPositiveInt(const std::string& t_prompt) const;
};

#endif // AIRGEAD_DISPLAY_H_