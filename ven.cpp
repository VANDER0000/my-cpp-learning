#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

void printMenu() {
    std::cout << "\n1 - Приветствие\n2 - Таблица умножения\n3 - Выход\nВыбор: ";
}

bool readNumber(int& num) {
    if (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

bool readPerson(std::string& name, int& age) {
    std::cout << "Напиши имя и фамилию: ";
    std::cin >> std::ws;
    std::getline(std::cin, name);

    std::cout << "Напиши возраст: ";
    if (!readNumber(age)) {
        std::cout << "Это не число!\n";
        return false;
    }
    return true;
}

void printGreeting(const std::string& name, int age) {
    if (age >= 18) {
        std::cout << "Привет, " << name << ", регистрация пройдена!\n";
        return;
    }

    int years = 18 - age;
    if (years == 1) {
        std::cout << "Подожди 1 год!\n";
    } else if (years >= 2 && years <= 4) {
        std::cout << "Подожди " << years << " года!\n";
    } else {
        std::cout << "Подожди " << years << " лет!\n";
    }
}

void sayHello() {
    std::string name;
    int age;
    if (readPerson(name, age)) {
        printGreeting(name, age);
    }
}

void printMultiplicationTable() {
    int num;
    std::cout << "Введи число: ";
    while (!readNumber(num)) {
        std::cout << "Введи число! ";
    }
    for (int i = 1; i <= 10; ++i) {
        std::cout << num << " * " << i << " = " << num * i << "\n";
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    while (true) {
        printMenu();
        if (!readNumber(choice)) {
            std::cout << "Введи число!\n";
            continue;
        }

        switch (choice) {
            case 1: sayHello(); break;
            case 2: printMultiplicationTable(); break;
            case 3: std::cout << "Пока!\n"; return 0;
            default: std::cout << "Введи число от 1 до 3!\n"; break;
        }
    }
}