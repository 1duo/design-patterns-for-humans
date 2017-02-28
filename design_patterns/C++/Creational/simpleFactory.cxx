#include <iostream>

class Door {
  public:
    virtual float getWidth() = 0;
    virtual float getHeight() = 0;
};

class WoodenDoor: public Door {
  protected:
    float width = 0.0, height = 0.0;

  public:
    WoodenDoor(float width, float height) {
        this->width = width;
        this->height = height;
    }

    float getWidth() {
        return this->width;
    }

    float getHeight() {
        return this->height;
    }
};

class DoorFactory {
  public:
    static Door* makeDoor(float width, float height) {
        return new WoodenDoor(width, height);
    }
};

int main() {
    auto door = DoorFactory::makeDoor(100.0, 200.0);
    std::cout << "Width: " << door->getWidth() << std::endl;
    std::cout << "Height: " << door->getHeight() << std::endl;
    // ===========
    // Width: 100
    // Height: 200
    // ===========
    return 0;
}
