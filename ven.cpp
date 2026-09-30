#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <locale>

void printMenu() {
    std::cout << "\n1 - Приветствие\n2 - Таблица умножения\n3 - Анализ строки\n4 - Выход\nВыбор: ";
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
    std::vector<int> results;
    for (int i = 1; i <= 10; ++i) {
        results.push_back(num*i);
    }
    int multiplier = 1;
    for (const int& result : results) {
        std::cout << num << " * " << multiplier << " = " << result << "\n";
        ++multiplier;
    }
}

void analyzeString() {
    std::cout << "Введите строку: ";
    std::string str;
    std::cin >> std::ws;
    std::getline (std::cin, str);

    
    if (str.empty()) {
        std::cout << "Строка пуста!\n";
        return;
    }
    std::cout << "Первый символ: " << str.front() << "\n" << "Последний символ: " << str.back() << "\n";
    
    size_t pos = str.find('a');   
    std::cout << "Размер строки: " << str.size() << "\n";
    if (pos == std::string::npos) {
        std::cout << "Буквы 'a' нет\n";
    } 
    else {
        std::cout << "Буква 'a' найдена на позиции " << pos << "\n";
    }
    if (str.size() <=3){
        std::cout << "Строка слишком мала!\n";
    }
    else {
        std::cout << "Подстрока: '" << str.substr(2, 4) << "'\n";
    }
    int CounterO = 0;
    for (char symbol : str) {
        if (symbol == 'o') {
            CounterO++;
        }
    }
    std::cout << "В строке " << CounterO << " букв 'o'!\n"; 
}

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");

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
            case 3: analyzeString(); break;
            case 4: std::cout << "Пока!\n"; return 0;
            default: std::cout << "Введи число от 1 до 4!\n"; break;
        }
    }
}