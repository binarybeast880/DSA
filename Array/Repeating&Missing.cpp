#include <bits/stdc++.h>
using namespace std;
void findNumbers(int arr[], int n)
{
    int sumN = (n * (n + 1)) / 2;
    int sumSqN = (n * (n + 1) * (2 * n + 1)) / 6;
    int sum = 0, sumSq = 0, i;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
        sumSq = sumSq + (pow(arr[i], 2));
    }
    int B = (((sumSq - sumSqN) / (sum - sumN)) + sumN - sum) / 2;
    int A = sum - sumN + B;
    cout << "A = ";
    cout << A << endl;
    cout << "B = ";
    cout << B << endl;
}
// Driver code
