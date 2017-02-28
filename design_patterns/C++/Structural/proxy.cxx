#include <iostream>
#include <string>

class Door {
  public:
	virtual void open() = 0;
	virtual void close() = 0;
};

class LabDoor: public Door {
  public:
	void open() {
		std::cout << "Openning lab door" << std::endl;
	}

	void close() {
		std::cout << "Closing the lab door" << std::endl;
	}
};

class Security {
  protected:
	Door* door = nullptr;

  public:
	Security(Door* door) {
		this->door = door;
	}

	void open(std::string password) {
		if (this->authenticate(password)) {
			this->door->open();
		} else {
			std::cout << "Big NO! It ain't possible." << std::endl;
		}
	}

	bool authenticate(std::string password) {
		return password == "$ecr@t";
	}

	void close() {
		this->door->close();
	}
};

int main() {
	auto door = new Security(new LabDoor());
	door->open("invalid");
	// ==========================
	// Big NO! It ain't possible.
	// ==========================
	door->open("$ecr@t");
	door->close();
	// ====================
	// Openning lab door
	// Closing the lab door
	// ====================
	return 0;
}
