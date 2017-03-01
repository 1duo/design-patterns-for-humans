class Computer:

    def get_electric_shock(self):
        print('Ouch!')

    def make_sound(self):
        print('Beep beep!')

    def show_loading_screen(self):
        print('Loading...')

    def bam(self):
        print('Ready to be used!')

    def close_everything(self):
        print('Bup bup bup buzzzz!')

    def sooth(self):
        print('Zzz...')

    def pull_current(self):
        print('Haaaah!')


class ComputerFacade:

    def __init__(self, computer):
        self.computer = computer

    def turn_on(self):
        self.computer.get_electric_shock()
        self.computer.make_sound()
        self.computer.show_loading_screen()
        self.computer.bam()

    def turn_off(self):
        self.computer.close_everything()
        self.computer.pull_current()
        self.computer.sooth()


if __name__ == '__main__':

    computer = ComputerFacade(Computer())

    computer.turn_on()
    # Ouch!
    # Beep beep!
    # Loading...
    # Ready to be used!

    computer.turn_off()
    # Bup bup bup buzzzz!
    # Haaaah!
    # Zzz...
