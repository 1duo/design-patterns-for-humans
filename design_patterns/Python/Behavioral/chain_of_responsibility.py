class Account:

    def __init__(self):
        self.successor = None
        self.balance = 0

    def set_next(self, account):
        self.successor = account

    def pay(self, amount_to_pay):
        if self.can_pay(amount_to_pay):
            print('Paid {} using {}'.format(
                amount_to_pay, self.__class__.__name__))
        elif self.successor:
            print('Cannot pay using {}, Proceeding...'.format(
                self.__class__.__name__))
            self.successor.pay(amount_to_pay)
        else:
            raise Exception('None of the accounts have enough balance')

    def can_pay(self, amount):
        return self.balance >= amount


class Bank(Account):

    def __init__(self, balance):
        self.balance = balance


class PayPal(Account):

    def __init__(self, balance):
        self.balance = balance


class Bitcoin(Account):

    def __init__(self, balance):
        self.balance = balance


if __name__ == '__main__':

    # Let's prepare a chain like below
    #     bank->paypal->bitcoin
    # First priority bank
    # If bank can't pay then paypal
    # If paypal can't pay then bit coin
    bank = Bank(100)
    paypal = PayPal(200)
    bitcoin = Bitcoin(300)
    bank.set_next(paypal)
    paypal.set_next(bitcoin)

    bank.pay(259)
    # Cannot pay using Bank, Proceeding...
    # Cannot pay using PayPal, Proceeding...
    # Paid 259 using Bitcoin
