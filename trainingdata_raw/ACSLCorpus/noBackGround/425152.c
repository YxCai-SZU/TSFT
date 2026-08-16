#include <stdbool.h>

/*@
    requires \valid_read(v + (0..3));
    requires v[0] >= -10000 && v[0] <= 10000;
    requires v[1] >= -10000 && v[1] <= 10000;
    requires v[2] >= -10000 && v[2] <= 10000;
    requires v[3] >= -10000 && v[3] <= 10000;
    ensures \result == v[0] * v[2] || \result == v[1] * v[3] || 
            \result == v[0] * v[3] || \result == v[1] * v[2];
*/
int func(const int v[4]) {
    int product1;
    int product2;
    int product3;
    int product4;
    int max_val;

    //@ assert v[0] >= -10000 && v[0] <= 10000;
    //@ assert v[2] >= -10000 && v[2] <= 10000;
    product1 = v[0] * v[2];
    //@ assert product1 >= -1000000000 && product1 <= 1000000000;

    //@ assert v[1] >= -10000 && v[1] <= 10000;
    //@ assert v[3] >= -10000 && v[3] <= 10000;
    product2 = v[1] * v[3];
    //@ assert product2 >= -1000000000 && product2 <= 1000000000;

    //@ assert v[0] * v[3] >= -1000000000 && v[0] * v[3] <= 1000000000;
    product3 = v[0] * v[3];
    //@ assert product3 >= -1000000000 && product3 <= 1000000000;

    //@ assert v[1] * v[2] >= -1000000000 && v[1] * v[2] <= 1000000000;
    product4 = v[1] * v[2];
    //@ assert product4 >= -1000000000 && product4 <= 1000000000;

    max_val = product1;
    if (product2 > max_val) {
        max_val = product2;
    }
    if (product3 > max_val) {
        max_val = product3;
    }
    if (product4 > max_val) {
        max_val = product4;
    }

    return max_val;
}
