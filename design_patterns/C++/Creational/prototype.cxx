#include <iostream>
#include <string>

class Sheep {
  protected:
    std::string name = "";
    std::string category = "";

  public:
    Sheep(std::string name, std::string category = "Mountain Sheep") {
        this->name = name;
        this->category = category;
    }

    Sheep(Sheep const& object) {}

    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() {
        return this->name;
    }

    void setCategory(std::string category) {
        this->category = category;
    }

    std::string getCategory() {
        return this->category;
    }
};

int main() {
    auto original = new Sheep("Jolly");
    std::cout << original->getName() << std::endl;
    std::cout << original->getCategory() << std::endl;
    // ==============
    // Jolly
    // Mountain Sheep
    // ==============
    auto cloned = original;
    cloned->setName("Dolly");
    std::cout << cloned->getName() << std::endl;
    std::cout << cloned->getCategory() << std::endl;
    // ==============
    // Dolly
    // Mountain Sheep
    // ==============
    return 0;
}
