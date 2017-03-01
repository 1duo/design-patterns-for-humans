import copy


class Sheep:

    def __init__(self, name, category='Mountain Sheep'):
        self.name = name
        self.category = category

    def set_name(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def set_category(self, category):
        self.category = category

    def get_category(self):
        return self.category


if __name__ == '__main__':

    original = Sheep('Jolly')
    assert original.get_name() == 'Jolly'
    assert original.get_category() == 'Mountain Sheep'

    cloned = copy.deepcopy(original)
    cloned.set_name('Dolly')
    assert cloned.get_name() == 'Dolly'
    assert cloned.get_category() == 'Mountain Sheep'
