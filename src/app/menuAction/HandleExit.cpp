#include "app/menuAction/HandleExit.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

HandleExit::HandleExit() = default;

bool HandleExit::handleAction(bool& running)
{
	running = false;
	std::cout << "\nDziekujemy za skorzystanie z kalkulatora walut!" << std::endl;
	return running;
}

} // namespace CurrencyApp