#include <iostream>
#include <windows.h>
#include <string>

void printMenu() {
    std::cout << "\n1 - Приветствие\n2 - Таблица умножения\n3 - Выход\nВыбор: ";
}

void sayHello() {
    std::string name;
    int age;
    
    std::cout << "Введите имя и фамилию: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Введите возраст: ";
    std::cin >> age;

    if (age>=18) std::cout << "Привет, " << name << ", доступ разрешен!\n";
    else if (18 - age == 1) std::cout << "Возвращайся через год!\n";
    else if (2<=(18 - age) and (18-age)<=4) std::cout << "Возвращайся через " << (18-age) << " года!\n";
    else std::cout << "Возвращайся через " << 18-age << " лет!\n";
}

void printMultiplicationTable() {
    int num;
    
    std::cout << "Введи число: ";
    std::cin >> num;

    for (int i = 1; i <= 10; i++)
        std::cout << num << " * " << i << " = " << num*i << "\n";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Введи число!\n";
            continue;
        }

        if (choice == 3) break;
        else if (choice == 1) sayHello();
        else if (choice == 2) printMultiplicationTable();
        else std::cout << "Неверный выбор\n";
    }
}