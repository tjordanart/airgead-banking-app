// 5-3-ProjectTwo
// Tyler Jordan

#include <iostream>
#include "Investment.h"
#include "Display.h"

int main()
{
    Investment investment;
    Display display;
    bool keepRunning = true;

    try
    {
        while (keepRunning)
        {
            // Input screen
            display.showInputScreen();
            display.getInputs(investment);
            display.showInputValues(investment);
            display.waitForKey();

            // Report 1: no monthly deposits
            display.showReport("Balance and Interest Without Additional Monthly Deposits",
                investment.calculateYearlyResults(false));

            // Report 2: with monthly deposits
            display.showReport("Balance and Interest With Additional Monthly Deposits",
                investment.calculateYearlyResults(true));

            // Ask if the user wants to try new numbers
            keepRunning = display.askToContinue();
            std::cout << std::endl;
        }
    }
    catch (const std::exception& t_error)
    {
        // Last safety net so the program exits with a clear message
        std::cout << "Something went wrong: " << t_error.what() << std::endl;
        return 1;
    }

    return 0;
}
