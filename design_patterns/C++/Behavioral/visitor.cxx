#include <iostream>

class Monkey;
class Lion;
class Dolphin;

// Visitor
class AnimalOperation {
  public:
	virtual void visitMonkey(Monkey* monkey) = 0;
	virtual void visitLion(Lion* lion) = 0;
	virtual void visitDolphin(Dolphin* dolphin) = 0;
};

// Visitee
class Animal {
  public:
	virtual void accept(AnimalOperation* operation) = 0;
};

class Monkey: public Animal {
  public:
	void shout() {
		std::cout << "Ooh oo aa aa!" << std::endl;
	}

	void accept(AnimalOperation* operation) {
		operation->visitMonkey(this);
	}
};

class Lion: public Animal {
  public:
	void roar() {
		std::cout << "Roaaar!" << std::endl;
	}

	void accept(AnimalOperation* operation) {
		operation->visitLion(this);
	}
};

class Dolphin: public Animal {
  public:
	void speak() {
		std::cout << "Tuut tuttu tuutt!" << std::endl;
	}

	void accept(AnimalOperation* operation) {
		operation->visitDolphin(this);
	}
};

class Speak: public AnimalOperation {
  public:
	void visitMonkey(Monkey* monkey) {
		monkey->shout();
	}

	void visitLion(Lion* lion) {
		lion->roar();
	}

	void visitDolphin(Dolphin* dolphin) {
		dolphin->speak();
	}
};

class Jump: public AnimalOperation {
  public:
	void visitMonkey(Monkey* monkey) {
		std::cout << "Jumped 20 feet high! on to the tree!" << std::endl;
	}

	void visitLion(Lion* lion) {
		std::cout << "Jumped 7 feet! Back on the ground!" << std::endl;
	}

	void visitDolphin(Dolphin* dolphin) {
		std::cout << "Walked on water a little and disappeared" << std::endl;
	}
};

int main() {
	auto monkey = new Monkey();
	auto lion = new Lion();
	auto dolphin = new Dolphin();
	auto speak = new Speak();
	auto jump = new Jump();
	monkey->accept(speak);
	lion->accept(speak);
	dolphin->accept(speak);
	// =================
	// Ooh oo aa aa!
	// Roaaar!
	// Tuut tuttu tuutt!
	// =================
	monkey->accept(jump);
	lion->accept(jump);
	dolphin->accept(jump);
	// ========================================
	// Jumped 20 feet high! on to the tree!
	// Jumped 7 feet! Back on the ground!
	// Walked on water a little and disappeared
	// ========================================
	return 0;
}
