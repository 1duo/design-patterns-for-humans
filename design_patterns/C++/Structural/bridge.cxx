#include <iostream>
#include <string>

class Theme {
  public:
	virtual std::string getColor() = 0;
};

class DarkTheme: public Theme {
  public:
	std::string getColor() {
		return "Dark Black";
	}
};

class LightTheme: public Theme {
  public:
	std::string getColor() {
		return "Light White";
	}
};

class AquaTheme: public Theme {
  public:
	std::string getColor() {
		return "Light Blue";
	}
};

class WebPage {
  public:
	virtual std::string getContent() = 0;
};

class About: public WebPage {
  protected:
	Theme* theme = nullptr;

  public:
	About(Theme* theme) {
		this->theme = theme;
	}

	std::string getContent() {
		return "About page in " + this->theme->getColor();
	}
};

class Careers: public WebPage {
  protected:
	Theme* theme = nullptr;

  public:
	Careers(Theme* theme) {
		this->theme = theme;
	}

	std::string getContent() {
		return "Careers page in " + this->theme->getColor();
	}
};

int main() {
	auto darkTheme = new DarkTheme();
	auto about = new About(darkTheme);
	auto careers = new Careers(darkTheme);
	std::cout << about->getContent() << std::endl;
	std::cout << careers->getContent() << std::endl;
	// ==========================
	// About page in Dark Black
	// Careers page in Dark Black
	// ==========================
	return 0;
}
