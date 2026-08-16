#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(x + (0..2));
    requires ((3) >= 3 &&
    1 <= (x)[0] && (x)[0] <= 100 &&
    1 <= (x)[1] && (x)[1] <= 20 &&
    1 <= (x)[2] && (x)[2] <= 2000);
    assigns \nothing;
    ensures \result == ((x[0]) * (x[1])) || \result == x[2] || \result == 0;
    ensures \result >= 0;
*/
int64_t func(int64_t* x) {
    // Variable declarations at scope top
    int64_t product;
    
    //@ assert 1 <= x[0] && x[0] <= 100;
    //@ assert 1 <= x[1] && x[1] <= 20;
    //@ assert ((x[0]) * (x[1])) <= 2000;
    
    product = x[0] * x[1];
    
    if (product < x[2]) {
        //@ assert product == ((x[0]) * (x[1])) || product == x[2] || product == 0;
        return product;
    } else {
        //@ assert x[2] == ((x[0]) * (x[1])) || x[2] == x[2] || x[2] == 0;
        return x[2];
    }
}
