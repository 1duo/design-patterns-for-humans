from collections import defaultdict


class KarakTea:
    # Anything that will be cached is flyweight
    # Types of tea here will be flyweights
    pass


class TeaMaker:
    # Acts as a factory and saves the tea

    def __init__(self):
        self.availible_tea = defaultdict(list)

    def make(self, preference):
        if len(self.availible_tea[preference]) == 0:
            self.availible_tea[preference] = KarakTea()
        return self.availible_tea[preference]


class TeaShop:

    def __init__(self, tea_maker):
        self.tea_maker = tea_maker
        self.orders = dict()

    def take_order(self, tea_type, table):
        self.orders[table] = self.tea_maker.make(tea_type)

    def serve(self):
        for table in self.orders.keys():
            print('Serving tea to table #' + str(table))


if __name__ == '__main__':

    tea_maker = TeaMaker()
    shop = TeaShop(tea_maker)
    shop.take_order('less suger', 1)
    shop.take_order('more milk', 2)
    shop.take_order('without suger', 5)
    shop.serve()
    # Serving tea to table #1
    # Serving tea to table #2
    # Serving tea to table #5
