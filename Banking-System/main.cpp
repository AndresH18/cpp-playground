#include <iostream>
#include <memory>

#include "data/user.h"

#include <QApplication>

#include "ui/main_window.h"
// #include <QPushButton>

void some_temp_examples();

void relearning_somethings_about_pointers();

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    // QPushButton button("Hello world!", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();

    ui::main_window m;

    m.show();

    return QApplication::exec();
    // window.show();

    return 0;
} // banking

void relearning_somethings_about_pointers() {
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);

    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        ++it;
        // this is the same as *it++, since ++ has higher precedenec than *.
        // This means that the curernt value of it is return and then incremented, and the returned value is dereferenced
    }

    int* i = new int(12);
    cout << "*i=" << *i << endl;
    shared_ptr<int> i_shared = std::make_shared<int>(*i);
    cout << "*i_shared=" << *i_shared << endl;
    *i = 222;
    cout << "*i=" << *i << endl;
    cout << "*i_shared=" << *i_shared << endl;

    delete i;
}

void some_temp_examples() {
    class user {
    private:
        unique_ptr<int> i_ptr;
        std::string name_;
        int age;

    public:
        user(int i) : i_ptr{
            std::make_unique<int>(i)
        } {
        }

        user(const std::string& name, int age) : name_{name}, age{age} {
            std::cout << "created new user, with name '" << name << "' and age '" << age << "'" << std::endl;
        }

        const string& name() const {
            return name_;
        }

        void name(const std::string& n_name) {
            name_ = n_name;
        }

        int& get_ptr_value() const {
            return *i_ptr;
        }

        void increment() {
            *i_ptr *= 2;
        }

        [[nodiscard]] const int& get_age() const {
            return age;
        }

        void set_age(int age) {
            this->age = age;
        }
    };
    std::unique_ptr<int> i_ptr = std::make_unique<int>(2);

    std::cout << "*i_ptr=" << *i_ptr << std::endl;
    *i_ptr = 10;
    std::cout << "*i_ptr=" << *i_ptr << std::endl;

    user u = user(*i_ptr);

    const auto& v = u.get_ptr_value();

    std::cout << "v=" << v << std::endl;
    u.increment();

    std::cout << "v=" << v << std::endl;


    string name = "andres";
    user u2 = user(name, 24);

    const string& u2_name = u2.name();
    auto age = u2.get_age();
    auto& r_age = u2.get_age();


    cout << "name=" << name << endl;
    cout << "u.name=" << u2.name() << endl;
    cout << "u_name=" << u2_name << endl;

    u2.name("david");

    cout << "name=" << name << endl;
    cout << "u.name=" << u2.name() << endl;
    cout << "u_name=" << u2_name << endl;

    cout << "AGE" << endl;

    cout << "u.age=" << u2.get_age() << endl;
    cout << "age=" << age << endl;
    u2.set_age(34);
    cout << "r_age=" << u2.get_age() << endl;
    cout << "age=" << age << endl;
    cout << "r_age=" << r_age << endl;
}
