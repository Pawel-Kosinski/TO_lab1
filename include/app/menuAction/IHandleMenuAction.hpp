#pragma once

namespace CurrencyApp {

class IHandleMenuAction {
public:
	virtual ~IHandleMenuAction() = default;
	virtual void handleAction() = 0;
};

} // namespace CurrencyApp