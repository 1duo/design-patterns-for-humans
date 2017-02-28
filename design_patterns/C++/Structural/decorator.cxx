#include <iostream>
#include <string>

class Coffee {
  public:
	virtual int getCost() = 0;
	virtual std::string getDescription() = 0;
};

class SimpleCoffee: public Coffee {
  public:
	int getCost() {
		return 10;
	}

	std::string getDescription() {
		return "Simple coffee";
	}
};

class MilkCoffee: public Coffee {
  protected:
	Coffee* coffee = nullptr;

  public:
	MilkCoffee(Coffee* coffee) {
		this->coffee = coffee;
	}

	int getCost() {
		return this->coffee->getCost() + 2;
	}

	std::string getDescription() {
		return this->coffee->getDescription() + ", milk";
	}
};

class WhipCoffee: public Coffee {
  protected:
	Coffee* coffee = nullptr;

  public:
	WhipCoffee(Coffee* coffee) {
		this->coffee = coffee;
	}

	int getCost() {
		return this->coffee->getCost() + 2;
	}

	std::string getDescription() {
		return this->coffee->getDescription() + ", wilp";
	}
};

class VanillaCoffee: public Coffee {
  protected:
	Coffee* coffee = nullptr;

  public:
	VanillaCoffee(Coffee* coffee) {
		this->coffee = coffee;
	}

	int getCost() {
		return this->coffee->getCost() + 2;
	}

	std::string getDescription() {
		return this->coffee->getDescription() + ", milk";
	}
};

int main() {
	auto someCoffee1 = new SimpleCoffee();
	std::cout << someCoffee1->getCost() << std::endl;
	std::cout << someCoffee1->getDescription() << std::endl;
	// =============
	// 10
	// Simple coffee
	// =============
	auto someCoffee2 = new MilkCoffee(someCoffee1);
	std::cout << someCoffee2->getCost() << std::endl;
	std::cout << someCoffee2->getDescription() << std::endl;
	// ===================
	// 12
	// Simple coffee, milk
	// ===================
	auto someCoffee3 = new WhipCoffee(someCoffee2);
	std::cout << someCoffee3->getCost() << std::endl;
	std::cout << someCoffee3->getDescription() << std::endl;
	// =========================
	// 14
	// Simple coffee, milk, wilp
	// =========================
	auto someCoffee4 = new VanillaCoffee(someCoffee3);
	std::cout << someCoffee4->getCost() << std::endl;
	std::cout << someCoffee4->getDescription() << std::endl;
	// ===============================
	// 16
	// Simple coffee, milk, wilp, milk
	// ===============================
	return 0;
}
