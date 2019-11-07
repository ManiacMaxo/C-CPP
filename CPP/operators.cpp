#include <iostream>
using namespace std;

class Rectangle {
    double width, height;
    int x, y;

   public:
    Rectangle(int x, int y, double width, double height);
    int getX() const {
        return this->x;
    }
    int getY() const {
        return this->y;
    }
    double getWidth() const {
        return this->width;
    }
    double getHeight() const {
        return this->height;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setWidth(double w) {
        this->width = w;
    }
    void setHeight(double h) {
        this->height = h;
    }
};

Rectangle::Rectangle(int x, int y, double width, double height) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
}

Rectangle operator+(const Rectangle rect, int num) {
    Rectangle n_rect(rect.getX(), rect.getY(), rect.getWidth() + num, rect.getHeight() + num);
    return n_rect;
}

Rectangle operator+(Rectangle r1, Rectangle r2) {  // needs error checking
    Rectangle n_rect(r1.getX(), r1.getY(), r1.getWidth() + r2.getWidth(), r1.getHeight() + r2.getHeight());
    return n_rect;
}

Rectangle operator+=(Rectangle rect, int num) {
    rect.setWidth(rect.getWidth() + num);
    rect.setHeight(rect.getHeight() + num);
    return rect;
}

Rectangle operator+=(Rectangle r1, Rectangle r2) {
    r1.setWidth(r1.getWidth() + r2.getWidth());
    r1.setHeight(r1.getHeight() + r2.getHeight());
    return r1;
}

Rectangle operator++(Rectangle rect) {
    rect.setWidth(rect.getWidth() + 1);
    rect.setHeight(rect.getHeight() + 1);
    return rect;
}

int main() {
}
