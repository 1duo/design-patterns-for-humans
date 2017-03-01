class Door:

    def open(self):
        raise NotImplementedError

    def close(self):
        raise NotImplementedError


class LabDoor(Door):

    def open(self):
        print('Opening lab door')

    def close(self):
        print('Closing the lab door')


class Security:

    def __init__(self, door):
        self.door = door

    def open(self, password):
        if self.authenticate(password):
            self.door.open()
        else:
            print('Big NO! It ain\'t possible.')

    def authenticate(self, password):
        return password == '$ecr@t'

    def close(self):
        self.door.close()


if __name__ == '__main__':

    door = Security(LabDoor())
    door.open('invalid')  # Big NO! It ain't possible.
    door.open('$ecr@t')  # Opening lab door
    door.close()  # Closing the lab door
