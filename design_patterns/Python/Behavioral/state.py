class WritingState:

    def write(self, words):
        raise NotImplementedError


class UpperCase(WritingState):

    def write(self, words):
        print(words.upper())


class LowerCase(WritingState):

    def write(self, words):
        print(words.lower())


class Default(WritingState):

    def write(self, words):
        print(words)


class TextEditor:

    def __init__(self, state):
        self.state = state

    def set_state(self, state):
        self.state = state

    def type(self, words):
        self.state.write(words)


if __name__ == '__main__':

    editor = TextEditor(Default())
    editor.type('First line')

    editor.set_state(UpperCase())
    editor.type('Second line')
    editor.type('Third line')

    editor.set_state(LowerCase())
    editor.type('Fourth line')
    editor.type('Fifth line')

    # First line
    # SECOND LINE
    # THIRD LINE
    # fourth line
    # fifth line
