#include <iostream>

class Number {
private:
    int* data;
public:
    Number(int value) {
        data = new int(value);
    }
    Number(const Number& other) {
        data = new int(*other.data);
    }
    Number& operator=(const Number& other) {
        if (this == &other) {
            return *this;
        }
        delete data;
        data = new int(*other.data);
        return *this;
    }

    void print() {
        std::cout << *data << "\n";
    }

    void setData(int newValue) {
        *data = newValue;
    }

    ~Number () {
        delete data;
    }
};


int main() {
    Number n(10);
    Number b = n;
    b.setData(50);
    n.print();
    b.print();
    n = b;
    n.print();
    b.print();
    return 0;
}