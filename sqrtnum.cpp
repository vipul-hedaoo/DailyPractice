#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N = 12;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    double x = N;
    double eps = 1e-6;
    double root;

    for (int i = 0; i < 50; i++) {   // iteration limit (important)
        root = 0.5 * (x + N / x);

        if (fabs(root - x) < eps)
            break;

        x = root;
    }

    cout << (int)root;   // or use round(root)
}