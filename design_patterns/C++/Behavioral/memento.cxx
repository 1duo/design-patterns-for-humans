#include <iostream>
#include <string>

class EditorMemento {
  protected:
	std::string content = "";

  public:
	EditorMemento(std::string content) {
		this->content = content;
	}

	std::string getContent() {
		return this->content;
	}
};

class Editor {
  protected:
	std::string content = "";

  public:
	void type(std::string words) {
		this->content = this->content + " " + words;
	}

	std::string getContent() {
		return this->content;
	}

	EditorMemento* save() {
		return new EditorMemento(this->content);
	}

	void restore(EditorMemento* memento) {
		this->content = memento->getContent();
	}
};

int main() {
	auto editor = new Editor();
	editor->type("This is the first sentence.");
	editor->type("This is second.");
	auto saved = editor->save();
	editor->type("And this is third.");
	std::cout << editor->getContent() << std::endl;
	// ==============================================================
	// This is the first sentence. This is second. And this is third.
	// ==============================================================
	editor->restore(saved);
	std::cout << editor->getContent() << std::endl;
	// ===========================================
	// This is the first sentence. This is second.
	// ===========================================
	return 0;
}
