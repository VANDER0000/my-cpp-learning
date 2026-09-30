#include <iostream>


class Point {
public:
    Point(int x, int y) : x(x), y(y){
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << "\n";
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() const {return x;}
    int getY() const {return y;}


private:
    int x; 
    int y;
};

int main() {
    Point p1(3, 5);
    p1.print();
    p1.move(2, 2);
    p1.print();
} //main