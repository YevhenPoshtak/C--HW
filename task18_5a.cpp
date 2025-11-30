#include <iostream>
#include <string>

template <typename T>
class Masiv {
private:
    int size;
    T* arr;

public:
    Masiv(int n = 0) : size(n) {
        arr = (size > 0) ? new T[size] : nullptr;
    }

    ~Masiv() {
        delete[] arr;
    }

    T& operator[](int i) {
        return arr[i];
    }

    int getSize() const {
        return size;
    }

    void Swap(T &a, T &b) {
        if (&a == &b) return;
        T temp = a;
        a = b;
        b = temp;
    }

    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    Swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void bubbleSortInplace(T* a, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    T temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Masiv<int> m1(5);
    m1[0] = 5; m1[1] = 1; m1[2] = 4; m1[3] = 2; m1[4] = 8;
    std::cout << "Int before sort: "; m1.print();
    m1.bubbleSort();
    std::cout << "Int after sort: "; m1.print();

    Masiv<float> m2(5);
    m2[0] = 3.2; m2[1] = 1.1; m2[2] = 4.5; m2[3] = 2.8; m2[4] = 0.5;
    std::cout << "Float before sort: "; m2.print();
    m2.bubbleSort();
    std::cout << "Float after sort: "; m2.print();

    Masiv<double> m3(5);
    m3[0] = 3.14; m3[1] = 2.71; m3[2] = 1.41; m3[3] = 0.577; m3[4] = 1.618;
    std::cout << "Double before sort: "; m3.print();
    m3.bubbleSort();
    std::cout << "Double after sort: "; m3.print();

    Masiv<std::string> m4(5);
    m4[0] = "apple"; m4[1] = "orange"; m4[2] = "banana"; m4[3] = "grape"; m4[4] = "kiwi";
    std::cout << "String before sort: "; m4.print();
    m4.bubbleSort();
    std::cout << "String after sort: "; m4.print();

    double a[] = {9.1, 3.2, 6.3, 2.4, 7.5};
    Masiv<double>::bubbleSortInplace(a, 5);
    std::cout << "Static sort: ";
    for (double x : a) std::cout << x << " ";
}
