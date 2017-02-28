#include <iostream>

class Account {
  protected:
	Account* successor = nullptr;
	float balance = 0.0;

  public:
	void setNext(Account* account) {
		this->successor = account;
	}

	void pay(float amountToPay) {
		if (this->canPay(amountToPay)) {
			std::cout << "Paid " << amountToPay << " using "
			          << typeid(*this).name() << "!" << std::endl;
		} else if (this->successor) {
			std::cout << "Cannot pay using " << typeid(*this).name()
			          << ". Proceeding..." << std::endl;
			this->successor->pay(amountToPay);
		} else {
			std::cout << "None of the accounts have enough balance" << std::endl;
		}
	}

	virtual bool canPay(float amountToPay) = 0;
};

class Bank: public Account {
  protected:
	float balance = 0.0;

  public:
	Bank(float balance) {
		this->balance = balance;
	}

	bool canPay(float amountToPay) {
		return this->balance >= amountToPay;
	}
};

class PayPal: public Account {
  protected:
	float balance = 0.0;

  public:
	PayPal(float balance) {
		this->balance = balance;
	}

	bool canPay(float amountToPay) {
		return this->balance >= amountToPay;
	}
};

class Bitcoin: public Account {
  protected:
	float balance = 0.0;

  public:
	Bitcoin(float balance) {
		this->balance = balance;
	}

	bool canPay(float amountToPay) {
		return this->balance >= amountToPay;
	}
};

int main() {
	// Let's prepare a chain like below
	//      $bank->$paypal->$bitcoin
	//
	// First priority bank
	//      If bank can't pay then paypal
	//      If paypal can't pay then bit coin
	auto bank = new Bank(100);
	auto paypal = new PayPal(200);
	auto bitcoin = new Bitcoin(300);
	bank->setNext(paypal);
	paypal->setNext(bitcoin);
	// Let's try to pay using the first priority i.e. bank
	bank->pay(259);
	// =======================================
	// Cannot pay using 4Bank. Proceeding...
	// Cannot pay using 6PayPal. Proceeding...
	// Paid 259 using 7Bitcoin!
	// =======================================
	return 0;
}
