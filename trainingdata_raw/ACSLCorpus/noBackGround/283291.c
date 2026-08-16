#include <stdbool.h>

/*@
    requires \valid(x + (0..3));
    requires ((4) >= 4 &&
        1 <= (x)[0] <= 10000 &&
        1 <= (x)[1] <= 10000 &&
        1 <= (x)[2] <= 10000 &&
        1 <= (x)[3] <= 10000);
    ensures \result == x[0] * x[1] || \result == x[2] * x[3];
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int* x) {
    int product1;
    int product2;
    int result;

    //@ assert 1 <= x[0] && x[0] <= 10000;
    //@ assert 1 <= x[1] && x[1] <= 10000;
    //@ assert ((x[0]) * (x[1])) <= 100000000;
    
    product1 = x[0] * x[1];
    
    //@ assert 1 <= x[2] && x[2] <= 10000;
    //@ assert 1 <= x[3] && x[3] <= 10000;
    //@ assert ((x[2]) * (x[3])) <= 100000000;
    
    product2 = x[2] * x[3];
    
    if (product1 > product2) {
        //@ assert ((x[0]) * (x[1])) >= 1;
        result = product1;
    } else {
        //@ assert ((x[2]) * (x[3])) >= 1;
        result = product2;
    }
    
    return result;
}
