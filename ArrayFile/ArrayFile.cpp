#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <locale>
#include <conio.h>

using namespace std;

//
// Задача 1
// 
void task1() {
    int N;
    cout << "Input size of array N: ";
    cin >> N;
    int A[100];
    cout << "Input elements of array A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    int dodCounter = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] <= 0) {                    //лишає 0 та мінусові
            A[dodCounter++] = A[i];
        }
    }
    cout << "Array A after removing negative elements:" << endl;
    for (int i = 0; i < dodCounter; ++i) {
        cout << "A[" << i << "]: " << A[i] << endl;
    }
    _getch();
}

//
// Задача 2
//
void task2() {
    int n;
    cout << "Input size of array: ";
    cin >> n;
    vector<int> a(n);
    // ввід
    for (int i = 0; i < n; i++) {
        cout << "Input " << i + 1 << " element of array: ";
        cin >> a[i];
    }
    int min_idx = -1;
    //  першого парного 
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            min_idx = i;

            break;

        }
    }
    if (min_idx == -1) {
        cout << "There are no even elements in the array." << endl;
        _getch();
        return;
    }
    int min_value = INT_MAX;
    //  мін знач
    for (int i = min_idx + 1; i < n; i++) {
        if (a[i] > 0 && a[i] < min_value) {
            min_value = a[i];
        }
    }
    //вивед
    if (min_value == INT_MAX) {
        cout << "There are no positive numbers in the array to the right of the first even element." << endl;
        _getch();
    }
    else {
        cout << "Min value of the positive elements located to the right of the first even element: " << min_value << endl;
        _getch();
    }
}

//
// Задача 3(дод)     макс знач серед мін парних , що скл з ел заданого масиву
//
void task3() {
    int n;
    cout << "Input size of array: ";
    cin >> n;

    vector<int> a(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cout << "Input " << i + 1 << "element of array: ";
        cin >> a[i];
    }

    vector<int> min_even(n + 1, INT_MAX);

    for (int i = 0; i < 2 * n; i++) {
        if (a[i] % 2 == 0) {
            min_even[i / 2] = min(min_even[i / 2], a[i]);
        }
    }

    int max_value = INT_MIN;

    for (int i = 0; i < n; i++) {
        max_value = max(max_value, min_even[i]);
    }

    cout << "Max value from min even numbers: " << max_value << endl;
    _getch();
}

int main()
{
    int task;
    cout << "Input task number (1, 2, 3): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        cout << "Wrong task number." << endl;
    }
	return 0;
}
