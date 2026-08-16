#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int product1;
    int product2;
    int max_value;

    //@ assert ((a) * (b)) >= 1 && ((a) * (b)) <= 10000;
    product1 = a * b;

    //@ assert ((c) * (d)) >= 1 && ((c) * (d)) <= 10000;
    product2 = c * d;

    //@ assert product1 >= 1 && product2 >= 1;
    max_value = (product1 > product2) ? product1 : product2;

    //@ assert max_value == product1 || max_value == product2;
    return max_value;
}
