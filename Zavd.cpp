#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;


double calculateProductOfPositives(const double array[], int size) {
    double product = 1;

    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            product *= array[i];
        }
    }

    return product;
}

int main() {
  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 10;  

    double array[size];
    cout << "Впишіть список елементів" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> array[i];
    }

    double minElement = array[0];
    int indexOfMinElement = 0;

    for (int i = 1; i < size; ++i) {
        if (array[i] < minElement) {
            minElement = array[i];
            indexOfMinElement = i;
        }
    }


    double sumBeforeMinElement = 0;

    for (int i = 0; i < indexOfMinElement; ++i) {
        sumBeforeMinElement += array[i];
    }

    double productOfPositives = calculateProductOfPositives(array, size);


    cout << "Добуток елементів: " << productOfPositives << endl;
    cout << "Сума елементів: " << sumBeforeMinElement << endl;

    sort(array, array + size, [](double a, double b) {
        return ((int)a % 2 == (int)b % 2) ? (a < b) : ((int)a % 2 == 0);
        });


    cout << "Відсортований список елементів: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
