#include <limits.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == n * n - m * m;
    assigns \nothing;
*/
int find_difference_of_squares(int n, int m) {
    // Variable declarations at top of scope
    int difference;

    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    //@ assert 1 <= n * n <= 10000;
    //@ assert 1 <= m * m <= 10000;
    //@ assert n * n - m * m == ((n) * (n)) - ((m) * (m));

    difference = n * n - m * m;
    return difference;
}
