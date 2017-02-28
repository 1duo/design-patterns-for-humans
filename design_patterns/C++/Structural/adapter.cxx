#include <iostream>

class Lion {
  public:
    virtual void roar() = 0;
};

class AfricanLion: public Lion {
  public:
    virtual void roar() = 0;
};

class AsianLion: public Lion {
  public:
    void roar() {}
};

class Hunter {
  public:
    void hunt(Lion* lion) {}
};

class WildDog {
  public:
    void bark() {}
};

class WildDogAdapter: public Lion {
  protected:
    WildDog* dog = nullptr;

  public:
    WildDogAdapter(WildDog* dog) {
        this->dog = dog;
    }

    void roar() {
        this->dog->bark();
    }
};

int main() {
    auto wildDog = new WildDog();
    auto wildDogAdapter = new WildDogAdapter(wildDog);
    auto hunter = new Hunter();
    hunter->hunt(wildDogAdapter);
    return 0;
}
