#include <iostream>

class President {
  private:
    static President* instance;
    President() {}
    President(President const&);
    void operator=(President const&);

  public:
    static President* getInstance() {
        if (!instance) {
            instance = new President();
        }
        return instance;
    }
};

// instance will be initialized on demand
President* President::instance = 0;

int main() {
    auto president1 = President::getInstance();
    auto president2 = President::getInstance();
    // the addresses will be the same
    std::cout << president1 << std::endl;
    std::cout << president2 << std::endl;
    // ==============
    // 0x7f8be7c02910
    // 0x7f8be7c02910
    // ==============
    return 0;
}
