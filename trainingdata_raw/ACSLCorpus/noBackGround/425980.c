#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    requires 0 <= m && m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m) {
    bool result;
    int i;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;

    if (n == m) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (n == m);

    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant result == (n == m);
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= m <= n;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10) {
        i = i + 1;
    }

    //@ assert result == (n == m);
    return result;
}
