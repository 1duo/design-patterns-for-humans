class Door:

    def get_width(self):
        raise NotImplementedError

    def get_height(self):
        raise NotImplementedError


class WoodenDoor(Door):

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def get_width(self):
        return self.width

    def get_height(self):
        return self.height


class DoorFactory:

    @staticmethod
    def make_door(width, height):
        return WoodenDoor(width, height)


if __name__ == '__main__':

    door = DoorFactory().make_door(100, 200)

    assert door.get_width() == 100
    assert door.get_height() == 200
