#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>
#include <stdexcept>
using namespace std;

// Macros
#define PI 3.14159
#define SQUARE(x) ((x) * (x))

// Namespace
namespace MathUtils {
    inline int add(int a, int b) { return a + b; } // Inline function
    inline int multiply(int a, int b) { return a * b; } // Additional inline function
}

// Enumeration
enum Color { RED, GREEN, BLUE };

// Structure with methods
struct Point {
    int x, y;

    // Constructor
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    // Method to display point
    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    // Operator Overloading
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
};

// Class demonstrating encapsulation and abstraction
class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void draw() = 0; // Pure virtual function (abstract class)
    virtual ~Shape() {} // Virtual destructor

    string getName() const { return name; } // Getter function
};

// Derived class with inheritance and polymorphism
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    void draw() override { cout << "Drawing Circle with radius: " << radius << endl; }
    double area() const { return PI * radius * radius; }
};

// Operator Overloading
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& c) { // Overloaded '+' operator
        return Complex(real + c.real, imag + c.imag);
    }
    void display() { cout << real << " + " << imag << "i" << endl; }
};

// Template Function
template <typename T>
T square(T num) {
    return num * num;
}

// Template Class
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
    void setValue(T v) { value = v; }
};

// Friend function
class FriendExample {
private:
    int secret;
public:
    FriendExample(int s) : secret(s) {}
    friend void showSecret(const FriendExample& fe);
};
void showSecret(const FriendExample& fe) {
    cout << "Secret: " << fe.secret << endl;
}

int main() {
    // Arrays
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[][2] = {{1, 2}, {3, 4}};

    // Demonstrating array operations
    cout << "Array elements: ";
    for (int i = 0; i < 5; ++i) cout << arr1[i] << " ";
    cout << endl;

    // Strings
    string str = "Hello";
    cout << "Length: " << str.length() << ", Substring: " << str.substr(1, 3) << endl;
    str.append(" World");
    cout << "Appended String: " << str << endl;

    // Call by value and reference
    auto addValue = [](int a) { return a + 10; };
    auto addRef = [](int &a) { a += 10; };
    int x = 5;
    cout << "Call by value: " << addValue(x) << endl;
    addRef(x);
    cout << "Call by reference: " << x << endl;

    // Dynamic memory allocation
    int* ptr = new int(10);
    cout << "Dynamically allocated value: " << *ptr << endl;
    delete ptr;

    // Vectors
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    vec.insert(vec.begin() + 1, 10); // Insert
    vec.erase(vec.begin() + 2);     // Erase
    sort(vec.begin(), vec.end());   // Sort
    cout << "Vector elements: ";
    for (int v : vec) cout << v << " ";
    cout << endl;

    // Maps
    map<string, int> mp;
    mp["one"] = 1;
    mp["two"] = 2;
    cout << "Map value: " << mp["two"] << endl;
    cout << "Keys in map: ";
    for (auto& p : mp) cout << p.first << " ";
    cout << endl;

    // Remove element from map
    mp.erase("one"); // Removes key "one"
    cout << "After erasing 'one', map size: " << mp.size() << endl;

    // Sets
    set<int> st = {1, 2, 3};
    st.insert(4);
    cout << "Set contains 3? " << (st.count(3) ? "Yes" : "No") << endl;

    // Queue and Stack
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << "Queue front: " << q.front() << endl;
    q.pop();

    stack<int> s;
    s.push(100);
    s.push(200);
    cout << "Stack top: " << s.top() << endl;
    s.pop();

    // Exception Handling
    try {
        throw runtime_error("An error occurred!");
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Operator Overloading
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;
    c3.display();

    // Templates
    cout << "Square of 5: " << square(5) << endl;
    Box<string> b("Template Box");
    cout << b.getValue() << endl;

    // Lambda Expressions
    auto multiply = [](int a, int b) { return a * b; };
    cout << "Lambda: " << multiply(3, 4) << endl;

    // Demonstrating inheritance
    Circle cir(5);
    cir.draw();
    cout << "Area: " << cir.area() << endl;

    // Friend function
    FriendExample fe(42);
    showSecret(fe);

    return 0;
}
