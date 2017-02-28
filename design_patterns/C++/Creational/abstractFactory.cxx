#include <iostream>

class Door {
  public:
	virtual void getDescription() = 0;
};

class WoodenDoor: public Door {
  public:
	void getDescription() {
		std::cout << "I am a wooden door" << std::endl;
	}
};

class IronDoor: public Door {
  public:
	void getDescription() {
		std::cout << "I am an iron door" << std::endl;
	}
};

// fitting experts for each door type
class DoorFittingExpert {
  public:
	virtual void getDescription() = 0;
};

class Carpenter: public DoorFittingExpert {
  public:
	void getDescription() {
		std::cout << "I can only fit wooden doors" << std::endl;
	}
};

class Welder: public DoorFittingExpert {
  public:
	void getDescription() {
		std::cout << "I can only fit iron doors" << std::endl;
	}
};

// abstract factory
class DoorFactory {
  public:
	virtual Door* makeDoor() = 0;
	virtual DoorFittingExpert* makeFittingExpert() = 0;
};

// Wooden factory to return carpenter and wooden door
class WoodenDoorFactory: public DoorFactory {
  public:
	Door* makeDoor() {
		return new WoodenDoor();
	}

	DoorFittingExpert* makeFittingExpert() {
		return new Carpenter();
	}
};

// Iron door factory to get iron door and the relevant fitting expert
class IronDoorFactory: public DoorFactory {
  public:
	Door* makeDoor() {
		return new IronDoor();
	}

	DoorFittingExpert* makeFittingExpert() {
		return new Welder();
	}
};

int main() {
	auto woodenFactory = new WoodenDoorFactory();
	auto door1 = woodenFactory->makeDoor();
	auto expert1 = woodenFactory->makeFittingExpert();
	door1->getDescription();
	expert1->getDescription();
	// ===========================
	// I am a wooden door
	// I can only fit wooden doors
	// ===========================
	auto ironFactory = new IronDoorFactory();
	auto door2 = ironFactory->makeDoor();
	auto expert2 = ironFactory->makeFittingExpert();
	door2->getDescription();
	expert2->getDescription();
	// =========================
	// I am an iron door
	// I can only fit iron doors
	// =========================
	return 0;
}
