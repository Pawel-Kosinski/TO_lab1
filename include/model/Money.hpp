#pragma once
#include "Currency.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

class Money {
private:
	double amount;
	shared_ptr<Currency> currency;

public:
	Money(double amount, shared_ptr<Currency> currency);

	double getAmount() const;
	shared_ptr<Currency> getCurrency() const;
	const Currency& getCurrencyRef() const;

	string toString() const;

	Money(const Money&) = default;
	Money& operator=(const Money&) = default;
	Money(Money&&) noexcept = default;
	Money& operator=(Money&&) noexcept = default;
	~Money() = default;
};

} // namespace CurrencyApp