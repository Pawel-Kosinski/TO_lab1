#pragma once
#include "app/menuAction/IHandleMenuAction.hpp"
#include "services/NBPService.hpp"
#include "patterns/iterator/CurrencyIterator.hpp"

namespace CurrencyApp {

class HandleDisplayAvailableCurrencies : public IHandleMenuAction {
public:
	HandleDisplayAvailableCurrencies();
	virtual void handleAction() override;
};

} // namespace CurrencyApp