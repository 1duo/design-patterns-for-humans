class BurgerBuilder;

class Burger {
  protected:
    int size = 0;
    bool cheese = false;
    bool pepperoni = false;
    bool lettuce = false;
    bool tomato = false;

  public:
    Burger(BurgerBuilder* builder);
};

class BurgerBuilder {
  public:
    int size = 0;
    bool cheese = false;
    bool pepperoni = false;
    bool lettuce = false;
    bool tomato = false;

    BurgerBuilder(int size) {
        this->size = size;
    }

    BurgerBuilder* addPepperoni() {
        this->pepperoni = true;
        return this;
    }

    BurgerBuilder* addCheese() {
        this->cheese = true;
        return this;
    }

    BurgerBuilder* addLettuce() {
        this->lettuce = true;
        return this;
    }

    BurgerBuilder* addTomato() {
        this->tomato = true;
        return this;
    }

    Burger* build() {
        return new Burger(this);
    }
};

Burger::Burger(BurgerBuilder* builder) {
    this->size = builder->size;
    this->cheese = builder->cheese;
    this->pepperoni = builder->pepperoni;
    this->lettuce = builder->lettuce;
    this->tomato = builder->tomato;
}

int main() {
    auto burger = (new BurgerBuilder(6))
                  ->addPepperoni()
                  ->addLettuce()
                  ->addTomato()
                  ->build();
    return 0;
}
