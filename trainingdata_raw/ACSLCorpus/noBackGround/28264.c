#include <limits.h>

/*@
    requires ((a) >= 1 && (a) <= 10000) && ((b) >= 1 && (b) <= 10000) &&
             ((c) >= 1 && (c) <= 10000) && ((d) >= 1 && (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int product1;
    int product2;
    int result;

    //@ assert ((a) * (b)) >= 1 && ((a) * (b)) <= 10000 * 10000;
    product1 = a * b;

    //@ assert ((c) * (d)) >= 1 && ((c) * (d)) <= 10000 * 10000;
    product2 = c * d;

    //@ assert product1 >= 1;
    //@ assert product2 >= 1;

    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }

    //@ assert result >= 1;
    return result;
}
