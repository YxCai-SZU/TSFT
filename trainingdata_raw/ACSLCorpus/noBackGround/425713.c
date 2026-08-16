#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) * (m) - ((n) - 1) - (m) + 1);
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;

    //@ assert n > 0 && n <= 100;
    //@ assert m > 0 && m <= 100;
    //@ assert n * m <= 10000;
    //@ assert n * m - (n - 1) - m + 1 <= 10000;

    result = n * m - (n - 1) - m + 1;
    return result;
}
