#include <iostream>
#include <locale>
#include <random>

class randomNum {
public:
    randomNum () {
        std::random_device rd;              
        std::mt19937 gen(rd());             
        std::uniform_int_distribution<int> dist(1, 100);

        num = dist(gen);
    }

    int getNum() const {return num;}

private:
    int num;
};


int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    randomNum rn1;
    int a = rn1.getNum();
    int b = 0;
    std::cout << a;
    while (a != b)
    {
        std::cout << "Введи число: ";
        if (!(std::cin >> b)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (a == b) {
            std::cout << "Угадал -- число " << a << "!\n";
            break;
        }
        else if (a>b) {
            std::cout << "Больше!\n";
        }
        else {
            std::cout << "Меньше!\n";
        }
    }
    


} //main