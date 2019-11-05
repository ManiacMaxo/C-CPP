#include <iostream>
using namespace std;

class Point {
    double x;
    double y;

   public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double getX() const {
        return this->x;
    }
    double getY() const {
        return this->y;
    }
    void setX(double x) {
        this->x = x;
    }
    void setY(double y) {
        this->y = y;
    }
    Point& add(const Point p) {
        x += p.getX();
        y += p.getY();
        return *this;
    }
    Point& sub(const Point p) {
        x -= p.getX();
        y -= p.getY();
        return *this;
    }
    Point& mul(const Point p) {
        x *= p.getX();
        y *= p.getY();
        return *this;
    }
    Point operator+(const Point p) {
        Point result = Point(x + p.getX(), y + p.getY());
        return result;
    }
};

Point operator-(const Point p) {
    Point result = Point(-p.getX(), -p.getY());
    return result;
}

Point operator-(const Point p1, const Point p2) {
    Point result = Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    return result;
}

void print_point(Point p) {
    cout << "point(" << p.getX() << "," << p.getY() << ")" << endl;
}

int main() {
}
