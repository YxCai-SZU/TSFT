#include <stdbool.h>

/*@ requires (1 <= (n) <= 1000 &&
      1 <= (m) <= 1000 &&
      0 <= (k) <= (n) * (m));
    ensures \result == true <==> n * m == k;
    assigns \nothing;
*/
bool func(int n, int m, int k) {
    int a;
    int b;
    bool result;

    //@ assert 1 <= n && n <= 1000;
    //@ assert 1 <= m && m <= 1000;
    //@ assert 0 <= k && k <= n * m;

    //@ assert 1 <= n * m <= 1000000;
    a = n * m;
    //@ assert a == n * m;
    b = k;

    if (a == b) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
