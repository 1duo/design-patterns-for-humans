#include <iostream>
#include <string>
#include <ctime>

class User;

class ChatRoomMediator {
  public:
	virtual void showMessage(User* user, std::string message) = 0;
};

class ChatRoom: public ChatRoomMediator {
  public:
	void showMessage(User* user, std::string message);
};

class User {
  protected:
	std::string name = "";
	ChatRoomMediator* chatMediator;

  public:
	User(std::string name, ChatRoomMediator* chatMediator) {
		this->name = name;
		this->chatMediator = chatMediator;
	}

	std::string getName() {
		return this->name;
	}

	void send(std::string message) {
		this->chatMediator->showMessage(this, message);
	}
};

void ChatRoom::showMessage(User* user, std::string message) {
	auto t = time(nullptr);
	auto charTime = ctime(&t);
	auto sender = user->getName();
	std::cout << charTime << "[" << sender << "]: " << message << std::endl;
}

int main() {
	auto mediator = new ChatRoom();
	auto john = new User("John Doe", mediator);
	auto jane = new User("Jane Doe", mediator);
	john->send("Hi there!");
	jane->send("Hey!");
	// ========================
	// Tue Feb 28 15:31:01 2017
	// [John Doe]: Hi there!
	// Tue Feb 28 15:31:01 2017
	// [Jane Doe]: Hey!
	// ========================
	return 0;
}
