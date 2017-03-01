class Bulb:
    # Receiver

    def turn_on(self):
        print('Bulb has been lit')

    def turn_off(self):
        print('Darkness!')


class Command:

    def execute(self):
        raise NotImplementedError

    def undo(self):
        raise NotImplementedError

    def redo(self):
        raise NotImplementedError


class TurnOn(Command):

    def __init__(self, bulb):
        self.bulb = bulb

    def execute(self):
        self.bulb.turn_on()

    def undo(self):
        self.bulb.turn_off()

    def redo(self):
        self.execute()


class TurnOff(Command):

    def __init__(self, bulb):
        self.bulb = bulb

    def execute(self):
        self.bulb.turn_off()

    def undo(self):
        self.bulb.turn_on()

    def rebo(self):
        self.execute


class RemoteControl:
        # Invoker

    def submit(self, command):
        command.execute()


if __name__ == '__main__':

    bulb = Bulb()
    turn_on = TurnOn(bulb)
    turn_off = TurnOff(bulb)

    remote = RemoteControl()
    remote.submit(turn_on)
    remote.submit(turn_off)
    # Bulb has been lit
    # Darkness!
