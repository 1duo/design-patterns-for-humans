class Burger:

    def __init__(self, builder):
        self.size = builder.size
        self.cheese = builder.cheese
        self.pepperoni = builder.pepperoni
        self.lettuce = builder.lettuce
        self.tomato = builder.tomato


class BurgerBuilder:

    def __init__(self, size):
        self.size = size
        self.cheese = False
        self.pepperoni = False
        self.lettuce = False
        self.tomato = False

    def add_cheese(self):
        self.cheese = True

    def add_pepperoni(self):
        self.pepperoni = True

    def add_lettuce(self):
        self.lettuce = True

    def add_tomato(self):
        self.tomato = True

    def build(self):
        return Burger(self)


if __name__ == '__main__':

    burger = BurgerBuilder(6)
    burger.add_cheese()
    burger.add_lettuce()
    burger.build()
