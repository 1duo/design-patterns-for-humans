#include <iostream>
#include <vector>
#include <string>

class Employee {
  public:
	virtual std::string getName() = 0;
	virtual void setSalary(float salary) = 0;
	virtual float getSalary() = 0;
	virtual std::vector<std::string> getRoles() = 0;
};

class Developer: public Employee {
  protected:
	float salary = 0.0;
	std::string name = "";
	std::vector<std::string> roles;

  public:
	Developer(std::string name, float salary) {
		this->name = name;
		this->salary = salary;
	}

	std::string getName() {
		return this->name;
	}

	void setSalary(float salary) {
		this->salary = salary;
	}

	float getSalary() {
		return this->salary;
	}

	std::vector<std::string> getRoles() {
		return this->roles;
	}
};

class Designer: public Employee {
  protected:
	std::string name = "";
	float salary = 0.0;
	std::vector<std::string> roles;

  public:
	Designer(std::string name, float salary) {
		this->name = name;
		this->salary = salary;
	}

	std::string getName() {
		return this->name;
	}

	void setSalary(float salary) {
		this->salary = salary;
	}

	float getSalary() {
		return this->salary;
	}

	std::vector<std::string> getRoles() {
		return this->roles;
	}
};

class Organization {
  protected:
	std::vector<Employee*> employees;

  public:
	void addEmployee(Employee* employee) {
		this->employees.push_back(employee);
	}

	float getNetSalaries() {
		auto netSalaries = 0.0;
		for (auto employee : this->employees) {
			netSalaries += employee->getSalary();
		}
		return netSalaries;
	}
};

int main() {
	auto john = new Developer("John Doe", 12000);
	auto jane = new Designer("Jane Doe", 10000);
	auto organization = new Organization();
	organization->addEmployee(john);
	organization->addEmployee(jane);
	std::cout << "Net salaries: " << organization->getNetSalaries() << std::endl;
	// ===================
	// Net salaries: 22000
	// ===================
	return 0;
}
