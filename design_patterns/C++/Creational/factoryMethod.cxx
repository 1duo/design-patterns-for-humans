#include <iostream>

class Interviewer {
  public:
    virtual void askQuestions() = 0;
};

class Developer: public Interviewer {
  public:
    void askQuestions() {
        std::cout << "Asking about design patterns!" << std::endl;
    }
};

class CommunityExecutive: public Interviewer {
  public:
    void askQuestions() {
        std::cout << "Asking about community building!" << std::endl;
    }
};

class HiringManager {
  public:
    virtual Interviewer* makeInterviewer() = 0;  // factory method

    void takeInterview() {
        Interviewer* interviewer = this->makeInterviewer();
        interviewer->askQuestions();
    }
};

class DevelopmentManager: public HiringManager {
  public:
    Interviewer* makeInterviewer() {
        return new Developer();
    }
};

class MarketingManager: public HiringManager {
  public:
    Interviewer* makeInterviewer() {
        return new CommunityExecutive();
    }
};

int main() {
    auto devManager = new DevelopmentManager();
    auto marketingManager = new MarketingManager();
    devManager->takeInterview();
    marketingManager->takeInterview();
    // ================================
    // Asking about design patterns!
    // Asking about community building!
    // ================================
    return 0;
}
