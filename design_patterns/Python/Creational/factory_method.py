class Interviewer:

    @staticmethod
    def ask_questions():
        raise NotImplementedError


class Developer(Interviewer):

    def ask_questions(self):
        print('Asking about design patterns!')


class CommunityExecutive(Interviewer):

    def ask_questions(self):
        print('Asking about community building')


class HiringManager:

    def make_interviewer(self):
        raise NotImplementedError

    def take_interview(self):
        interviewer = self.make_interviewer()
        interviewer.ask_questions()


class DevelopmentManager(HiringManager):

    def make_interviewer(self):
        return Developer()


class MarketingManager(HiringManager):

    def make_interviewer(self):
        return CommunityExecutive()


if __name__ == '__main__':

    dev_manager = DevelopmentManager()
    dev_manager.take_interview()
    # Output: Asking about design patterns!

    mkt_manager = MarketingManager()
    mkt_manager.take_interview()
    # Output: Asking about community building
