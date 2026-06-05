#include <bits/stdc++.h>
using namespace std;

class Power
{
private:
    double solveRecursive(double x, long long n)
    {
        if (n == 0)
            return 1.0;

        double half = solveRecursive(x, n / 2);

        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return x * half * half;
        }
    }

public:
    double power_brute(double x, int n)
    {
        // Base Case
        if (n == 0 || x == 1.0)
            return 1.0;

        long long temp = n;

        // Handle negative exponent
        if (temp < 0)
        {
            x = 1.0 / x;
            temp = -temp;
        }

        double ans = 1.0;
        for (long long i = 0; i < temp; i++)
        {
            ans *= x;
        }

        return ans;
    }

    double power_optimized(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;

        if (nn < 0)
            nn = -nn;

        while (nn > 0)
        {
            if (nn % 2 == 1)
            { // Odd power
                ans = ans * x;
                nn = nn - 1;
            }
            else
            { // Even power
                x = x * x;
                nn = nn / 2;
            }
        }

        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }

        return ans;
    }
};

int main() {
    Power p; 

    // Test Case 1: Positive Exponent
    double base1 = 2.0;
    int exp1 = 10;
    cout << "--- Test Case 1: Positive Exponent (" << base1 << "^" << exp1 << ") ---" << endl;
    cout << "Brute Force Result: " << p.power_brute(base1, exp1) << endl;
    cout << "Optimized Result:   " << p.power_optimized(base1, exp1) << endl;
    cout << endl;

    // Test Case 2: Negative Exponent
    double base2 = 2.0;
    int exp2 = -2;
    cout << "--- Test Case 2: Negative Exponent (" << base2 << "^" << exp2 << ") ---" << endl;
    cout << "Brute Force Result: " << p.power_brute(base2, exp2) << endl;
    cout << "Optimized Result:   " << p.power_optimized(base2, exp2) << endl;
    cout << endl;

    // Test Case 3: Zero Exponent
    double base3 = 5.5;
    int exp3 = 0;
    cout << "--- Test Case 3: Zero Exponent (" << base3 << "^" << exp3 << ") ---" << endl;
    cout << "Brute Force Result: " << p.power_brute(base3, exp3) << endl;
    cout << "Optimized Result:   " << p.power_optimized(base3, exp3) << endl;
    cout << endl;

    // Test Case 4: Extreme Edge Case (INT_MIN Overflow Check)
    double base4 = 1.0000000000001; // Base close to 1 to prevent huge double underflow/overflow
    int exp4 = INT_MIN; // -2147483648
    cout << "--- Test Case 4: INT_MIN Exponent ---" << endl;
    cout << "Brute Force Result: " << p.power_brute(base4, exp4) << endl;
    cout << "Optimized Result:   " << p.power_optimized(base4, exp4) << endl;
    cout << endl;

    return 0;
}