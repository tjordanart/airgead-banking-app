# Airgead Banking App

A console investment calculator built with C++.

Enter an initial investment, monthly deposit, annual interest rate, and number of years. The program then shows how the investment grows over time with and without additional monthly deposits.

*Built for CS 210 at SNHU.*

## Overview

Airgead Banking App was built around a fictional banking scenario. The goal was to create an investment growth calculator that shows the effect of compound interest over multiple years.

The user enters four values:

- Initial investment amount
- Monthly deposit
- Annual interest rate
- Number of years

The program then generates two yearly reports. The first shows investment growth without additional monthly deposits. The second shows growth with the monthly deposits included.

The program can be run again with a new set of values.

## Features

- Initial investment input
- Monthly deposit input
- Annual interest rate input
- Number of years input
- Year-by-year investment growth
- Report without monthly deposits
- Report with monthly deposits
- Monthly compound interest calculations
- Input validation
- Exception handling
- Formatted currency and percentage values
- Option to run another calculation
- Separate classes for investment calculations and user interaction
- Named constants instead of magic numbers

## Example Output

```text
**********************************
********** Data Input ************
Initial Investment Amount: $1000
Monthly Deposit: $100
Annual Interest (%): 5
Number of years: 5

Balance and Interest Without Additional Monthly Deposits
=========================================================
Year    Year End Balance        Year End Earned Interest
---------------------------------------------------------
1       $1051.16               $51.16
2       $1104.71               $53.55
3       $1159.76               $55.05
4       $1216.55               $56.79
5       $1275.31               $58.76

Balance and Interest With Additional Monthly Deposits
=========================================================
Year    Year End Balance        Year End Earned Interest
---------------------------------------------------------
1       $2308.90               $108.90
2       $3670.13               $161.23
3       $5101.24               $231.11
4       $6534.92               $333.68
5       $8078.31               $443.39
```

*Example values are for demonstration.*

## Input Validation

The program validates every value entered by the user.

If the input is not valid, the program asks the user to enter it again. Invalid text, zero, negative numbers, and values containing extra characters are rejected.

For example:

- Initial investment must be positive
- Monthly deposit must be positive
- Annual interest must be positive
- Number of years must be a positive whole number
- Responses to the continue prompt must be `y`, `yes`, `n`, or `no`

The program also checks for non-finite values such as infinity when reading decimal numbers.

## How the Investment Calculation Works

The program converts the annual interest percentage into a monthly interest rate.

Each month, it:

1. Adds the monthly deposit when deposits are enabled.
2. Calculates the interest earned for that month.
3. Adds the interest to the current balance.
4. Continues until all 12 months are completed.
5. Stores the ending balance and total interest earned for the year.

The process repeats for the number of years entered by the user.

Two calculations are performed:

- **Without Additional Monthly Deposits** — only the initial investment earns compound interest.
- **With Additional Monthly Deposits** — the monthly deposit is added before calculating each month's interest.

## Project Structure

| File | Purpose |
|---|---|
| `main.cpp` | Creates the `Investment` and `Display` objects and controls the main program loop |
| `main.h` | Main program header |
| `Display.cpp` | Handles user input, validation, formatting, and report display |
| `Display.h` | Display class declarations |
| `Investment.cpp` | Handles investment data and yearly growth calculations |
| `Investment.h` | Investment class declarations |
| `docs/pseudocode.md` | Original project pseudocode and program planning |

The program separates user interface functionality from investment calculations using two classes: `Display` and `Investment`.

## Requirements

- A C++ compiler (g++, clang, or Visual Studio)
- No external libraries

The program uses the C++ standard library, including:

- `iostream`
- `iomanip`
- `string`
- `vector`
- `algorithm`
- `cctype`
- `cmath`
- `stdexcept`

## How to Run

Clone the repository:

```bash
git clone https://github.com/Tjordanart/airgead-banking-app.git
```

Navigate to the project directory:

```bash
cd airgead-banking-app
```

Compile the program:

```bash
g++ src/main.cpp src/Display.cpp src/Investment.cpp -o airgead
```

Run it:

```bash
./airgead
```

On Windows, you can also open the project files in Visual Studio and build and run the program there.

Enter the requested investment information, review the results, and choose whether to run another calculation.

## What I Practiced

This project provided practice with:

- C++ programming
- Object-oriented programming
- Classes and objects
- Constructors
- Encapsulation
- Getters and setters
- Private member variables
- Header and source files
- `std::vector`
- Loops
- Conditional logic
- Exception handling
- Input validation
- String processing
- Financial calculations
- Compound interest
- Separating program responsibilities
- Named constants
- Formatted console output

## Author

**Tyler Jordan**

[GitHub](https://github.com/Tjordanart)  
[Portfolio](https://www.tjordanart.com)
