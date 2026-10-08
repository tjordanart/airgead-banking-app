#ifndef AIRGEAD_INVESTMENT_H_
#define AIRGEAD_INVESTMENT_H_

#include <vector>

// Struct used to bundle one year's results into a single row
struct YearlyResult
{
	int year;
	double yearEndBalance;
	double yearEndInterest;
};

// Stores the user's investment values and does the math
class Investment
{
public:
	// Sets all values to zero
	Investment();

	// Setters: each one throws an error if the value is not positive
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterest(double t_annualInterest);
	void setNumberOfYears(int t_numberOfYears);

	// Getters: used to show the values back to the user
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getAnnualInterest() const;
	int getNumberOfYears() const;

	// Builds one row per year, with or without monthly deposits
	std::vector<YearlyResult> calculateYearlyResults(bool t_includeDeposits) const;

private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numberOfYears;
};

#endif // AIRGEAD_INVESTMENT_H_