#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    Employee(const string& name, const string& position)
        : name(name), position(position) {}

    string getName() const {
        return name;
    }

    string getPosition() const {
        return position;
    }

private:
    string name;
    string position;
};

class ServiceShop {
public:
    void addEmployee(const string& name, const string& position) {
        employees.push_back(Employee(name, position));
    }

    vector<Employee> getEmployeesByPosition(const string& position) const {
        vector<Employee> foundEmployees;
        for (const Employee& employee : employees) {
            if (employee.getPosition() == position) {
                foundEmployees.push_back(employee);
            }
        }
        return foundEmployees;
    }

private:
    vector<Employee> employees;
};

int main() {
    
    ServiceShop shop;

    
    shop.addEmployee("Иванов Иван", "Менеджер");
    shop.addEmployee("Петров Петр", "Техник");
    shop.addEmployee("Сидорова Анна", "Консультант");
    shop.addEmployee("Смирнов Сергей", "Менеджер");
    shop.addEmployee("Козлова Ольга", "Консультант");

   
    string positionToFind = "Менеджер";
    vector<Employee> managers = shop.getEmployeesByPosition(positionToFind);

    if (!managers.empty()) {
        cout << "Сотрудники с должностью '" << positionToFind << "':" << endl;
        for (const Employee& manager : managers) {
            cout << "- " << manager.getName() << endl;
        }
    }
    else {
        cout << "Нет сотрудников с должностью '" << positionToFind << "'." << endl;
    }

    return 0;
}
