#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 &&
        1 <= (a) <= 100 &&
        1 <= (b) <= 2000);
    ensures \result == ((a) * (n)) || \result == b;
    ensures \result <= ((a) * (n));
    ensures \result <= b;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int product;
    int result;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert ((a) * (n)) <= 2000;

    product = a * n;
    
    if (product < b) {
        result = product;
    } else {
        result = b;
    }

    //@ assert result == ((a) * (n)) || result == b;
    return result;
}
