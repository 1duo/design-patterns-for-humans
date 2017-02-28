#include <iostream>

class Computer {
  public:
	void getElectricShock() {
		std::cout << "Ouch!" << std::endl;
	}

	void makeSound() {
		std::cout << "Beep beep!" << std::endl;
	}

	void showLoadingScreen() {
		std::cout << "Loading..." << std::endl;
	}

	void bam() {
		std::cout << "Ready to be used!" << std::endl;
	}

	void closeEverything() {
		std::cout << "Bup bup bup buzzzz!" << std::endl;
	}

	void sooth() {
		std::cout << "Zzzzz" << std::endl;
	}

	void pullCurrent() {
		std::cout << "Haaah!" << std::endl;
	}
};

class ComputerFacade {
  protected:
	Computer* computer = nullptr;

  public:
	ComputerFacade(Computer* computer) {
		this->computer = computer;
	}

	void turnOn() {
		this->computer->getElectricShock();
		this->computer->makeSound();
		this->computer->showLoadingScreen();
		this->computer->bam();
	}

	void turnOff() {
		this->computer->closeEverything();
		this->computer->pullCurrent();
		this->computer->sooth();
	}
};

int main() {
	auto computer = new ComputerFacade(new Computer());
	computer->turnOn();
	// =================
	// Ouch!
	// Beep beep!
	// Loading...
	// Ready to be used!
	// =================
	computer->turnOff();
	// ===================
	// Bup bup bup buzzzz!
	// Haaah!
	// Zzzzz
	// ===================
	return 0;
}
