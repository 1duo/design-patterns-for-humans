class Lion:

    def roar(self):
        raise NotImplementedError


class AfricanLion(Lion):

    def roar():
        pass


class AsianLion(Lion):

    def roar():
        pass


class Hunter:

    def hunt(self, lion):
        pass


class WildDog:

    def bark(self):
        pass


class WildDogAdapter(Lion):

    def __init__(self, dog):
        self.dog = dog

    def roar(self):
        self.dog.bark()


if __name__ == '__main__':

    wild_dog = WildDog()
    wild_dog_adapter = WildDogAdapter(wild_dog)
    hunter = Hunter()
    hunter.hunt(wild_dog_adapter)
