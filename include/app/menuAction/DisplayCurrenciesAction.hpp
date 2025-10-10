#pragma once
#include "app/menuAction/IMenuAction.hpp"


namespace CurrencyApp {

class DisplayCurrenciesAction : public IMenuAction {
public:
	explicit DisplayCurrenciesAction();
	void execute() override;
};

} // namespace CurrencyApp