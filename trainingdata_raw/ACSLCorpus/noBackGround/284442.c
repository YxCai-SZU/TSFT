#include <limits.h>

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result == x * y;
    assigns \nothing;
*/
int func(int x, int y, int z) {
    // Declare all variables at the top
    int product;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= x * y <= 10000;

    product = x * y;

    return product;
}

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result == x * y;
    assigns \nothing;
*/
int func2(int x, int y, int z) {
    // Declare all variables at the top
    int product;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= x * y <= 10000;

    product = x * y;

    return product;
}
