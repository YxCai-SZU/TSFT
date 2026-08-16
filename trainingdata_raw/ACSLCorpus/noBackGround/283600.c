#include <stdbool.h>

/*@ requires 1 <= n <= 100 && 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m) {
    bool result;
    //@ assert (((n) == (m)) ? 1 : 0) == ((n == m) ? 1 : 0);
    result = (n == m);
    return result;
}

/*@ requires 1 <= n <= 100 && 0 <= m <= n && m >= 2 && n >= 2;
    ensures \result == true;
    assigns \nothing;
*/
bool func2(unsigned int n, unsigned int m) {
    bool result;
    //@ assert ((2) % 2 == 0);
    //@ assert ((1) % 2 != 0);
    result = true;
    return result;
}

int main() {
    return 0;
}
