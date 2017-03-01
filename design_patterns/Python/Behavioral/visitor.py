class Animal:
    # visitee

    def accept(operation):
        raise NotImplementedError


class AnimalOperation:
    # visitor

    def visit_monkey(monkey):
        raise NotImplementedError

    def visit_lion(lion):
        raise NotImplementedError

    def visit_dolphin(dolphin):
        raise NotImplementedError


class Monkey(Animal):

    def shout(self):
        print('Ooh oo aa aa!')

    def accept(self, operation):
        operation.visit_monkey(self)


class Lion(Animal):

    def roar(self):
        print('Roaaar!')

    def accept(self, operation):
        operation.visit_lion(self)


class Dolphin(Animal):

    def speak(self):
        print('Tuut tuttu tuutt!')

    def accept(self, operation):
        operation.visit_dolphin(self)


class Speak(AnimalOperation):

    def visit_monkey(self, monkey):
        monkey.shout()

    def visit_lion(self, lion):
        lion.roar()

    def visit_dolphin(self, dolphin):
        dolphin.speak()


class Jump(AnimalOperation):

    def visit_monkey(self, monkey):
        print('Jumped 20 feet high! on to the tree!')

    def visit_lion(self, lion):
        print('Jumped 7 feet! Back on the ground!')

    def visit_dolphin(self, dolphin):
        print('Walked on water a little and disappeared.')


if __name__ == '__main__':

    monkey = Monkey()
    lion = Lion()
    dolphin = Dolphin()

    speak = Speak()
    jump = Jump()

    monkey.accept(speak)  # Ooh oo aa aa!
    monkey.accept(jump)  # Jumped 20 feet high! on to the tree!

    lion.accept(speak)  # Roaaar!
    lion.accept(jump)  # Jumped 7 feet! Back on the ground!

    dolphin.accept(speak)  # Tuut tuttu tuutt!
    dolphin.accept(jump)  # Walked on water a little and disappeared.
