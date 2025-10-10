#pragma once
#include "app/menuAction/IHandleMenuAction.hpp"

namespace CurrencyApp {

class HandleExit : public IHandleMenuAction {
public:
	HandleExit();
	virtual void handleAction() override;
};

} // namespace CurrencyApp