#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    char *name;
    int salary;
    Employee *manager;

    void _clearName()
    {
        delete[] this->name;
        this->name = nullptr;
    }

    void _clearManager()
    {
        cout << "Deleting manager for" << this->name << endl;
        delete this->manager;
        this->manager = nullptr;
    }

    void _clear()
    {
        _clearManager();
        _clearName();
    }

    void _copyName(const char *_name)
    {
        if(name != nullptr)
        {
            _clear();
        }

        if(_name != nullptr)
        {
            int l = strlen(_name);
            if(l > 0)
            {
                name = new char[l + 1];
                strcpy(name, _name);
            }
        }
    }

    void _copyManager(Employee *_manager)
    {
        if(this->manager != nullptr)
        {
            delete this->manager;
            this->manager = nullptr;
        }

        if(_manager != nullptr)
        {
            this->manager = new Employee(_manager->name, _manager->salary);
            this->manager->_copyManager(_manager->getManager());
        }
    }

    public:

    // 4 constructors - default, with 1,2,3 parameters
    Employee(const char* _name = nullptr, int _salary = 0, Employee *_manager = nullptr) : 
    name(nullptr), salary(_salary), manager(_manager)
    {
        _copyName(_name);
    }

    Employee(const Employee &other) : name(nullptr), salary(other.salary), manager(other.manager)
    {
        _copyName(other.name);
        _copyManager(other.manager);
    }

    Employee &operator = (const Employee &other)
    {
        // prevent problems : x = x 
        if(this != &other)
        {
            this->salary = other.salary;
            this->name = other.name;
            this->manager = other.manager;
            _copyName(other.name);
            _copyManager(other.manager);
        }

        //deference the object
        return *this;
    }

    Employee &operator += (Employee *other)
    {
        Employee *boss = findBoss(this);
        boss->manager = other;
    }

    ~Employee()
    {
        _clear();
    }

    char *getName()
    {
        return name;
    }

    int getSalary()
    {
        return salary;
    }

    Employee *getManager()
    {
        return manager;
    }

    bool hasManager()
    {
        return manager != nullptr;
    }
};

Employee *findBossRec(Employee *begin)
{
    if(begin == nullptr || !begin->hasManager())
    {
        return begin;
    }

    return findBossRec(begin->getManager());
}

Employee *findBoss(Employee *begin)
{
    while(begin != nullptr && begin->hasManager())
    {
        begin = begin->getManager();
    }

    return begin;
}

int main()
{

    Employee cashier ("cashier Spas", 13, new Employee("manager Tosho", 4000, new Employee("bai Ivan", 10000, nullptr)));
    
    Employee cashier2 = cashier;    
    
    //dinamichna promenliva se trie, destruktora ne se griji za neq
    //delete cashier;
    
    //cout << findBoss(cashier)->getName() << endl;
    cashier += new Employee("bai petar", 3);
    cout << findBoss(&cashier)->getName() << endl;

    return 0;
}