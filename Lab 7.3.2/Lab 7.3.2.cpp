#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High, int row, int col);
void Print(int** a, const int n);
void FindSameRowAndColumn(int** a, const int n, int i);
int SumRowsWithNegativeElementsRec(int** a, const int n, int i, int rowSum);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -3;
    int High = 3;
    int n;

    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High, 0, 0);
    Print(a, n);

    FindSameRowAndColumn(a, n, 0);

    int sum = SumRowsWithNegativeElementsRec(a, n, 0, 0);
    cout << "Sum of rows with negative elements: " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High, int row, int col)
{
    if (row == n)
        return;

    if (col == n)
    {
        Create(a, n, Low, High, row + 1, 0);
        return;
    }

    a[row][col] = Low + rand() % (High - Low + 1);
    Create(a, n, Low, High, row, col + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void FindSameRowAndColumn(int** a, const int n, int i)
{
    if (i >= n)
        return;

    bool found = true;
    for (int j = 0; j < n; j++) {
        if (a[i][j] != a[j][i]) {
            found = false;
            break;
        }
    }

    if (found) {
        cout << "Row " << i << " and Column " << i << endl;
    }

    FindSameRowAndColumn(a, n, i + 1);
}

int SumRowsWithNegativeElementsRec(int** a, const int n, int i, int rowSum) {
    if (i == n) {
        return rowSum; 
    }

    bool hasNegative = false; 
    for (int j = 0; j < n; j++) {
        if (a[i][j] < 0) {
            hasNegative = true;
            break;
        }
    }

    if (hasNegative) {
      
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        rowSum += sum;
    }

    return SumRowsWithNegativeElementsRec(a, n, i + 1, rowSum);
}

