#include <iostream>
#include <cmath>

// Base class for geometric shapes
class Shape {
public:
    virtual void display() const = 0; // Virtual function to display shape information
    virtual double area() const = 0;   // Virtual function to calculate area
    virtual double perimeter() const = 0; // Virtual function to calculate perimeter
};

// Derived class for 2D shapes
class TwoDimensionalShape : public Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Derived class for 3D shapes
class ThreeDimensionalShape : public Shape {
public:
    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;
};

// Classes for specific shapes
class Circle : public TwoDimensionalShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void display() const override {
        std::cout << "Circle with radius: " << radius << std::endl;
    }
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Square : public TwoDimensionalShape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void display() const override {
        std::cout << "Square with side: " << side << std::endl;
    }
    double area() const override {
        return side * side;
    }
    double perimeter() const override {
        return 4 * side;
    }
};

class Sphere : public ThreeDimensionalShape {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {}
    void display() const override {
        std::cout << "Sphere with radius: " << radius << std::endl;
    }
    double surfaceArea() const override {
        return 4 * M_PI * radius * radius;
    }
    double volume() const override {
        return (4.0 / 3) * M_PI * radius * radius * radius;
    }
};

class Cube : public ThreeDimensionalShape {
private:
    double side;
public:
    Cube(double s) : side(s) {}
    void display() const override {
        std::cout << "Cube with side: " << side << std::endl;
    }
    double surfaceArea() const override {
        return 6 * side * side;
    }
    double volume() const override {
        return side * side * side;
    }
};

// Function to display menu and perform actions
void displayMenu() {
    std::cout << "Choose a shape:" << std::endl;
    std::cout << "1. Circle" << std::endl;
    std::cout << "2. Square" << std::endl;
    std::cout << "3. Sphere" << std::endl;
    std::cout << "4. Cube" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double radius;
                std::cout << "Enter radius of the circle: ";
                std::cin >> radius;
                Circle circle(radius);
                circle.display();
                std::cout << "Area: " << circle.area() << std::endl;
                std::cout << "Perimeter: " << circle.perimeter() << std::endl;
                break;
            }
            case 2: {
                double side;
                std::cout << "Enter side of the square: ";
                std::cin >> side;
                Square square(side);
                square.display();
                std::cout << "Area: " << square.area() << std::endl;
                std::cout << "Perimeter: " << square.perimeter() << std::endl;
                break;
            }
            case 3: {
                double radius;
                std::cout << "Enter radius of the sphere: ";
                std::cin >> radius;
                Sphere sphere(radius);
                sphere.display();
                std::cout << "Surface Area: " << sphere.surfaceArea() << std::endl;
                std::cout << "Volume: " << sphere.volume() << std::endl;
                break;
            }
            case 4: {
                double side;
                std::cout << "Enter side of the cube: ";
                std::cin >> side;
                Cube cube(side);
                cube.display();
                std::cout << "Surface Area: " << cube.surfaceArea() << std::endl;
                std::cout << "Volume: " << cube.volume() << std::endl;
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
