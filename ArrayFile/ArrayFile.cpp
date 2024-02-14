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
int main()
{
    int task;
    cout << "Input task number (1, 2, 3): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    default:
        cout << "Wrong task number." << endl;
    }
	return 0;
}
