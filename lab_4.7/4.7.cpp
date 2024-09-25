#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double xp, xk, x, dx, eps, term, S;
    int n;

    cout << "xp = "; cin >> xp;  
    cout << "xk = "; cin >> xk;  
    cout << "dx = "; cin >> dx;  
    cout << "eps = "; cin >> eps; 

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "ln(x)" << " |"
         << setw(10) << "S" << " |"
         << setw(5) << "n" << " |"
         << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        n = 0;
        term = (x - 1) / (x * 1);  
        S = term;

        do {
            n++;
            term *= (x - 1) / (x * (n + 1)); 
            S += term; 
        } while (fabs(term) >= eps); 

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(10) << setprecision(5) << log(x) << " |"
             << setw(10) << setprecision(5) << S << " |"
             << setw(5) << n << " |" << endl;

        x += dx;  
    }

    cout << "-------------------------------------------------" << endl;
    return 0;
}
