#include <stdbool.h>

/*@ requires
        \valid(v+(0..3)) &&
        v[0] >= 1 && v[0] <= 10000 &&
        v[1] >= 1 && v[1] <= 10000 &&
        v[2] >= 1 && v[2] <= 10000 &&
        v[3] >= 1 && v[3] <= 10000;
    ensures
        (\result == v[0] * v[1] || \result == v[2] * v[3]) &&
        \result >= 1;
*/
int func(int v[4])
{
    int a;
    int b;
    int c;
    int d;
    int product1;
    int product2;
    int max_value;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert ((a) >= 1 && (a) <= 10000 &&         (b) >= 1 && (b) <= 10000 &&         (c) >= 1 && (c) <= 10000 &&         (d) >= 1 && (d) <= 10000);

    product1 = a * b;
    product2 = c * d;

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    //@ assert max_value >= 1;

    return max_value;
}
