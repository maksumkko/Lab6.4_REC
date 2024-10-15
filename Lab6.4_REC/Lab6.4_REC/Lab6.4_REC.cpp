#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateA(int a[], int n, int min, int max);
void printA(int a[], int n);
void productARecursive(int a[], int n, int index, int& product);
int sumBetweenZeros(int a[], int n);
int findFirstZero(int a[], int n, int index);
int findLastZero(int a[], int index);
int sumBetweenZerosRecursive(int a[], int firstZero, int lastZero);
void rearrangeArrayRecursive(int a[], int n);
void copyPositiveRecursive(int a[], int n, int index, int*& temp, int& tempIndex);
void copyNegativeRecursive(int a[], int n, int index, int*& temp, int& tempIndex);

int main()
{
    int n;
    cout << "Input N: ";
    cin >> n;

    int* a = new int[n];
    int product = 1;

    generateA(a, n, -10, 20);
    cout << "a=";
    printA(a, n);

    productARecursive(a, n, 0, product);
    cout << "Product of elements at even indices: " << product << endl;

    int sum = sumBetweenZeros(a, n);
    if (sum != -1) {
        cout << "Sum between first and last zeros: " << sum << endl;
    }
    else {
        cout << "There are not enough zeros to calculate the sum." << endl;
    }

    rearrangeArrayRecursive(a, n);
    cout << "Rearranged array: ";
    printA(a, n);

    delete[] a;
    return 0;
}

void generateA(int a[], int n, int min, int max)
{
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i)
    {
        a[i] = std::rand() % (max - min + 1) + min;
    }
}

void printA(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << std::setw(4) << a[i];
    }
    cout << endl;
}

void productARecursive(int a[], int n, int index, int& product)
{
    if (index >= n)
        return;

    if (index % 2 == 0)
        product *= a[index];

    productARecursive(a, n, index + 1, product);
}

int findFirstZero(int a[], int n, int index)
{
    if (index >= n)
        return -1;

    if (a[index] == 0)
        return index;

    return findFirstZero(a, n, index + 1);
}

int findLastZero(int a[], int index)
{
    if (index < 0)
        return -1;

    if (a[index] == 0)
        return index;

    return findLastZero(a, index - 1);
}

int sumBetweenZerosRecursive(int a[], int firstZero, int lastZero)
{
    if (firstZero + 1 >= lastZero)
        return 0;

    return a[firstZero + 1] + sumBetweenZerosRecursive(a, firstZero + 1, lastZero);
}

int sumBetweenZeros(int a[], int n)
{
    int firstZero = findFirstZero(a, n, 0);
    int lastZero = findLastZero(a, n - 1);

    if (firstZero == -1 || lastZero == -1 || firstZero == lastZero)
        return -1;

    return sumBetweenZerosRecursive(a, firstZero, lastZero);
}

void copyPositiveRecursive(int a[], int n, int index, int*& temp, int& tempIndex)
{
    if (index >= n)
        return;

    if (a[index] >= 0)
        temp[tempIndex++] = a[index];

    copyPositiveRecursive(a, n, index + 1, temp, tempIndex);
}

void copyNegativeRecursive(int a[], int n, int index, int*& temp, int& tempIndex)
{
    if (index >= n)
        return; 

    if (a[index] < 0)
        temp[tempIndex++] = a[index];

    copyNegativeRecursive(a, n, index + 1, temp, tempIndex);
}

void rearrangeArrayRecursive(int a[], int n)
{
    int* temp = new int[n];
    int tempIndex = 0;

    copyPositiveRecursive(a, n, 0, temp, tempIndex);
    copyNegativeRecursive(a, n, 0, temp, tempIndex);

    for (int i = 0; i < n; ++i)
    {
        a[i] = temp[i];
    }

    delete[] temp; 
}