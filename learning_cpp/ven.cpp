#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    std::string name;
    int choice, age, num;

    while (true) {
        std::cout << "\n1 - Приветствие\n2 - Таблица умножения\n3 - Выход\nВыбор: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Введи число!\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::cout << "Введи имя и фамилию: ";
                std::cin.ignore();
                std::getline(std::cin, name);

                std::cout << "Введи возраст: ";
                std::cin >> age;

                if (age >= 18)
                    std::cout << "Привет, " << name << ", доступ разрешён!\n";
                else
                    std::cout << "Доступ запрещён!\n";
                break;
            }
            case 2: {
                std::cout << "Введи число: ";
                std::cin >> num;
                for (int i = 1; i <= 10; ++i)
                    std::cout << num << " x " << i << " = " << num * i << "\n";
                break;
            }
            case 3:
                std::cout << "Пока!\n";
                return 0;
            default:
                std::cout << "Неверный выбор\n";
        }
    }
}