#pragma once
#include "utils/Types.hpp"

namespace CurrencyApp {

class Currency {
	string code;
	string name;
	double rate;
	int multiplier;

public:
	Currency(const string& code, const string& name, double rate, int multiplier);
	const string& getCode() const;
	const string& getName() const;
	double getRate() const;
	int getMultiplier() const;

	void setRate(double rate);
	void setMultiplier(int multiplier);

	string toString() const;
};

} // namespace CurrencyApp