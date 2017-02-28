#include <iostream>

// Receiver
class Bulb {
  public:
	void turnOn() {
		std::cout << "Bulb has been lit" << std::endl;
	}

	void turnOff() {
		std::cout << "Darkness!" << std::endl;
	}
};

class Command {
  public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
};

// Command
class TurnOn: public Command {
  protected:
	Bulb* bulb = nullptr;

  public:
	TurnOn(Bulb* bulb) {
		this->bulb = bulb;
	}

	void execute() {
		this->bulb->turnOn();
	}

	void undo() {
		this->bulb->turnOff();
	}

	void redo() {
		this->execute();
	}
};

class TurnOff: public Command {
  protected:
	Bulb* bulb = nullptr;

  public:
	TurnOff(Bulb* bulb) {
		this->bulb = bulb;
	}

	void execute() {
		this->bulb->turnOff();
	}

	void undo() {
		this->bulb->turnOn();
	}

	void redo() {
		this->execute();
	}
};

// Invoker
class RemoteControl {
  public:
	void submit(Command* command) {
		command->execute();
	}
};

int main() {
	auto bulb = new Bulb();
	auto turnOn = new TurnOn(bulb);
	auto turnOff = new TurnOff(bulb);
	auto remote = new RemoteControl();
	remote->submit(turnOn);
	remote->submit(turnOff);
	// =================
	// Bulb has been lit
	// Darkness!
	// =================
	return 0;
}
