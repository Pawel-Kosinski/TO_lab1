#pragma once
#include "app/menuAction/IHandleMenuAction.hpp"
#include "services/NBPService.hpp"
#include "patterns/iterator/CurrencyIterator.hpp"

namespace CurrencyApp {

class HandleConversion : public IHandleMenuAction {
public:
	HandleConversion();
	virtual void handleAction() override;
};

} // namespace CurrencyApp