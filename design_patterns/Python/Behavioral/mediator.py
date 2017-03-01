from datetime import datetime


class ChatRoomMediator:
    pass


class ChatRoom(ChatRoomMediator):

    def show_message(self, user, message):
        time = datetime.now()
        sender = user.get_name()
        print('[{}] {}: {}'.format(time, sender, message))


class User:

    def __init__(self, name, chat_room_mediator):
        self.name = name
        self.chat_room_mediator = chat_room_mediator

    def get_name(self):
        return self.name

    def send(self, message):
        self.chat_room_mediator.show_message(self, message)


if __name__ == '__main__':

    mediator = ChatRoom()
    john = User('John Doe', mediator)
    jane = User('Jane Doe', mediator)
    john.send('Hi there!')
    jane.send('Hey!')
    # Output:
    # [2017-02-24 10:31:07.474657] John Doe: Hi there!
    # [2017-02-24 10:31:07.475182] Jane Doe: Hey!
