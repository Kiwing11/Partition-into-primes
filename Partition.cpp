#include <iostream>
#define VALUE 1

using namespace std;
int arr[2][255];
int lastNumber;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int findPrimes(int k) {
    int counter = 0;
    for (int i = 2; i <= k; i++)
    {
        if (isPrime(i))
        {
            arr[0][counter] = i;
            counter++;
        }
    }
    return counter;
}

void Clear(int quantity) {
    for (int j = 0; j < quantity - 1; j++)
        arr[VALUE][j] = 0;
}

void doPartition(int n, int k, int quantity) {

    int i = n - k;
    int counter = 0;

    while (counter != quantity) {
        if (i > 0) {
            arr[VALUE][0]++;
            i -= arr[0][0];
        }
        if (i == 0) {
            cout << k;
            for (int j = quantity - 1; j >= 0; j--) {
                for (int z = 0; z < arr[VALUE][j]; z++)
                {
                    if (arr[VALUE][j] != 0)
                        cout << "+";
                    cout << arr[0][j];

                }
            }
            cout << endl;
            i--;
        }
        while (i < 0 && counter != quantity) {
            arr[VALUE][0] = 0;
            counter = 0;
            counter++;
            arr[VALUE][counter]++;
            i = n - k;
            for (int y = 1; y < quantity && counter != quantity; y++)
            {
                i -= (arr[VALUE][y] * arr[0][y]);
                if (i == 0)
                    break;
                if (i < 0) {
                    arr[VALUE][counter] = 0;
                    counter++;
                    arr[VALUE][counter]++;
                    i = n - k;
                    y = 1;
                }

            }

        }

    }
    Clear(255);

}

int main() {
    int operations, n, k, quantity;
    cin >> operations;

    for (int i = 0; i < operations; i++)
    {
        cin >> n >> k;

        if (isPrime(k)) {
            if (n - k > k)
                quantity = findPrimes(k);
            else if (n - k == 0)
                quantity = 1;
            else
                quantity = findPrimes(n - k);

            doPartition(n, k, quantity);
        }
    }

    return 0;
}