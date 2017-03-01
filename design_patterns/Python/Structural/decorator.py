class Coffee:

    def get_cost(self):
        raise NotImplementedError

    def get_description(self):
        raise NotImplementedError


class SimpleCoffee(Coffee):

    def get_cost(self):
        return 10

    def get_description(self):
        return 'Simple coffee'


class MilkCoffee(Coffee):

    def __init__(self, coffee):
        self.coffee = coffee

    def get_cost(self):
        return self.coffee.get_cost() + 2

    def get_description(self):
        return self.coffee.get_description() + ', milk'


class WhipCoffee(Coffee):

    def __init__(self, coffee):
        self.coffee = coffee

    def get_cost(self):
        return self.coffee.get_cost() + 5

    def get_description(self):
        return self.coffee.get_description() + ', whip'


class VanillaCoffee(Coffee):

    def __init__(self, coffee):
        self.coffee = coffee

    def get_cost(self):
        return self.coffee.get_cost() + 3

    def get_description(self):
        return self.coffee.get_description() + ', vanilla'


if __name__ == '__main__':

    coffee = SimpleCoffee()
    assert coffee.get_cost() == 10
    assert coffee.get_description() == 'Simple coffee'

    coffee = MilkCoffee(coffee)
    assert coffee.get_cost() == 12
    assert coffee.get_description() == 'Simple coffee, milk'

    coffee = WhipCoffee(coffee)
    assert coffee.get_cost() == 17
    assert coffee.get_description() == 'Simple coffee, milk, whip'

    coffee = VanillaCoffee(coffee)
    assert coffee.get_cost() == 20
    assert coffee.get_description() == 'Simple coffee, milk, whip, vanilla'
