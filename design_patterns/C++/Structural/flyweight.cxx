#include <iostream>
#include <map>

// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

// Acts as a factory and saves the tea
class TeaMaker {
  protected:
	std::map<std::string, KarakTea*> availableTea;

  public:
	KarakTea* make(std::string preference) {
		if (!this->availableTea[preference]) {
			this->availableTea[preference] = new KarakTea();
		}
		return this->availableTea[preference];
	}
};

class TeaShop {
  protected:
	std::map<int, KarakTea*> orders;
	TeaMaker* teaMaker = nullptr;

  public:
	TeaShop(TeaMaker* teaMaker) {
		this->teaMaker = teaMaker;
	}

	void takeOrder(std::string teaType, int table) {
		this->orders[table] = this->teaMaker->make(teaType);
	}

	void serve() {
		for (auto order : this->orders) {
			std::cout << "Serving tea to table #" << order.first << std::endl;
		}
	}
};

int main() {
	auto teaMaker = new TeaMaker();
	auto shop = new TeaShop(teaMaker);
	shop->takeOrder("less sugar", 1);
	shop->takeOrder("more milk", 2);
	shop->takeOrder("without sugar", 5);
	shop->serve();
	// =======================
	// Serving tea to table #1
	// Serving tea to table #2
	// Serving tea to table #5
	// =======================
	return 0;
}
