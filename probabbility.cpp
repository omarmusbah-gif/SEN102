#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void mean();
void var();
void quartile();
void median(); // ✅ fix

int main() {
    int choice = -1;

    while (choice != 0) {
        cout << "Please Enter:\n";
        cout << "1 to calculate mean\n";
        cout << "2 to calculate variance\n";
        cout << "3 to calculate quartiles\n"; // ✅ fix
        cout << "4 to calculate median\n";    // ✅ fix
        cout << "0 to exit\n";

        cin >> choice;

        if (choice == 1) {
            mean();
        }
        else if (choice == 2) {
            var();
        }
        else if (choice == 3) {
            quartile();
        }
        else if (choice == 4) {
            median();
        }
    }

    return 0;
}

// calculat the mean
void mean() {
    int n;
    cout << "Enter sample size: ";
    cin >> n;

    double sum = 0, number;

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> number;
        sum += number;
    }

    double result = sum / n;
    cout << "Mean = " << result << endl;
}

// calculate variance
void var() {
    int n;
    cout << "Enter sample size: ";
    cin >> n;

    double arr[100], sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double mean = sum / n;
    double variance = 0;

    for (int i = 0; i < n; i++) {
        variance += pow(arr[i] - mean, 2);
    }

    variance /= n;
    double std_dev = sqrt(variance);

    cout << "Variance = " << variance << endl;
    cout << "Standard Deviation = " << std_dev << endl;
}

// calculate quartile
void quartile() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[100];

    cout << "Enter numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int q1 = (n + 1) / 4 - 1;
    int q3 = 3 * (n + 1) / 4 - 1;

    cout << "Q1 = " << arr[q1] << endl;
    cout << "Q3 = " << arr[q3] << endl;
}

// calculate median
void median() {
    int n;
    cout << "please enter number of elements: ";
    cin >> n;

    double arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    if (n % 2 == 0) {
        double med = (arr[n/2 - 1] + arr[n/2]) / 2;
        cout << "Median = " << med << endl;
    } else {
        cout << "Median = " << arr[n/2] << endl;
    }
}
