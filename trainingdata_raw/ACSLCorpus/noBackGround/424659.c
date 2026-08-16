#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result == ((a) + (b)) || \result == ((a) * (b)) || \result == ((a) - (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int product;
    int difference;
    int max_val;

    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    sum = a + b;
    //@ assert ((a) * (b)) >= 1 && ((a) * (b)) <= 400;
    product = a * b;
    difference = a - b;

    max_val = sum;
    if (product > max_val) {
        max_val = product;
    }
    if (difference > max_val) {
        max_val = difference;
    }

    //@ assert max_val == ((a) + (b)) || max_val == ((a) * (b)) || max_val == ((a) - (b));
    return max_val;
}
