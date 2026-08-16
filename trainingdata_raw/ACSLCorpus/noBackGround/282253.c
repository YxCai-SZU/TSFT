#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int product1;
    int product2;
    int max_value;

    //@ assert 1 <= ((a) * (b)) <= 10000;
    //@ assert 1 <= ((c) * (d)) <= 10000;

    product1 = a * b;
    product2 = c * d;

    //@ assert 1 <= product1 + product2 <= 20000;

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    //@ assert max_value == product1 || max_value == product2;
    //@ assert max_value >= product1 && max_value >= product2;

    return max_value;
}
