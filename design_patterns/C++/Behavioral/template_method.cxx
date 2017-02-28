#include <iostream>

class Builder {
  public:
	// template method
	void build() {
		this->test();
		this->lint();
		this->assemble();
		this->deploy();
	}

	virtual void test() = 0;
	virtual void lint() = 0;
	virtual void assemble() = 0;
	virtual void deploy() = 0;
};

class AndroidBuilder: public Builder {
  public:
	void test() {
		std::cout << "Running Android tests" << std::endl;
	}

	void lint() {
		std::cout << "Linting the Android code" << std::endl;
	}

	void assemble() {
		std::cout << "Assembling the Android build" << std::endl;
	}

	void deploy() {
		std::cout << "Deploying Android build to server" << std::endl;
	}
};

class IosBuilder: public Builder {
  public:
	void test() {
		std::cout << "Running iOS tests" << std::endl;
	}

	void lint() {
		std::cout << "Linting the iOS code" << std::endl;
	}

	void assemble() {
		std::cout << "Assembling the iOS build" << std::endl;
	}

	void deploy() {
		std::cout << "Deploying iOS build to server" << std::endl;
	}
};

int main() {
	auto androidBuilder = new AndroidBuilder();
	androidBuilder->build();
	// =================================
	// Running Android tests
	// Linting the Android code
	// Assembling the Android build
	// Deploying Android build to server
	// =================================
	auto iosBuilder = new IosBuilder();
	iosBuilder->build();
	// =============================
	// Running iOS tests
	// Linting the iOS code
	// Assembling the iOS build
	// Deploying iOS build to server
	// =============================
	return 0;
}
