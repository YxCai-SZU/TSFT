#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 &&
        1 <= (a) <= 50 &&
        1 <= (b) <= 50);
    ensures \result >= 0;
    ensures \result == ((n) * (a)) || \result == b;
    ensures \result == b || \result == ((n) * (a));
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int product;
    int min_value;

    //@ assert (1 <= (n) <= 20 &&         1 <= (a) <= 50 &&         1 <= (b) <= 50);
    //@ assert ((n) * (a)) <= 1000;

    product = n * a;

    if (product < b) {
        min_value = product;
    } else {
        min_value = b;
    }

    //@ assert min_value == ((n) * (a)) || min_value == b;
    //@ assert min_value == b || min_value == ((n) * (a));

    return min_value;
}
