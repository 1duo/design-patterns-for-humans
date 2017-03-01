class Employee:

    def get_name(self):
        raise NotImplementedError

    def set_salary(self, salary):
        raise NotImplementedError

    def get_salary(self):
        raise NotImplementedError

    def get_roles(self):
        raise NotImplementedError


class Developer(Employee):

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    def get_name(self):
        return self.name

    def set_salary(self, salary):
        self.salary = salary

    def get_salary(self):
        return self.salary

    def get_roles(self):
        return self.roles


class Designer(Employee):

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    def get_name(self):
        return self.name

    def set_salary(self, salary):
        self.salary = salary

    def get_salary(self):
        return self.salary

    def get_roles(self):
        return self.roles


class Organization:

    def __init__(self):
        self.employees = []

    def add_employee(self, employee):
        self.employees.append(employee)

    def get_net_salaries(self):
        net_salary = 0
        for employee in self.employees:
            net_salary += employee.get_salary()
        return net_salary


if __name__ == '__main__':

    john = Developer('John Doe', 12000)
    jane = Designer('Jane Doe', 10000)
    organization = Organization()
    organization.add_employee(john)
    organization.add_employee(jane)
    assert organization.get_net_salaries() == 22000
