#include <iostream>
#include <string>
#include <algorithm>

class WritingState {
  public:
	virtual void write(std::string words) = 0;
};

class UpperCase: public WritingState {
  public:
	void write(std::string words) {
		std::transform(words.begin(), words.end(), words.begin(), ::toupper);
		std::cout << words << std::endl;
	}
};

class LowerCase: public WritingState {
  public:
	void write(std::string words) {
		std::transform(words.begin(), words.end(), words.begin(), ::tolower);
		std::cout << words << std::endl;
	}
};

class Default: public WritingState {
  public:
	void write(std::string words) {
		std::cout << words << std::endl;
	}
};

class TextEditor {
  protected:
	WritingState* state = nullptr;
  public:
	TextEditor(WritingState* state) {
		this->state = state;
	}

	void setState(WritingState* state) {
		this->state = state;
	}

	void type(std::string words) {
		this->state->write(words);
	}
};

int main() {
	auto editor = new TextEditor(new Default());
	editor->type("First line");
	editor->setState(new UpperCase());
	editor->type("Second line");
	editor->type("Third line");
	editor->setState(new LowerCase());
	editor->type("Fourth line");
	editor->type("Fifth line");
	// ===========
	// First line
	// SECOND LINE
	// THIRD LINE
	// fourth line
	// fifth line
	// ===========
	return 0;
}
