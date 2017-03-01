class EditorMemento:

    def __init__(self, content):
        self.content = content

    def get_content(self):
        return self.content


class Editor:

    def __init__(self):
        self.content = ''

    def type(self, words):
        self.content = self.content + ' ' + words

    def get_content(self):
        return self.content

    def save(self):
        return EditorMemento(self.content)

    def restore(self, memento):
        self.content = memento.get_content()


if __name__ == '__main__':

    editor = Editor()
    editor.type('This is the first sentence.')
    editor.type('This is second.')

    saved = editor.save()
    editor.type('And this is third.')
    assert editor.get_content() == \
        ' This is the first sentence. This is second. And this is third.'

    editor.restore(saved)
    assert editor.get_content() == \
        ' This is the first sentence. This is second.'
