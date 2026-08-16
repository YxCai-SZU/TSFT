#include <stdbool.h>

/*@
    predicate bounds(integer x, integer y, integer z) =
        x <= 100 && y <= 100 && z <= 100;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound: \forall integer x, y; 
        (1 <= x <= 100 && 1 <= y <= 100) ==> product(x, y) <= 10000;
*/

/*@
    requires x <= 100 && y <= 100 && z <= 100;
    ensures \result == (x * y >= z);
    assigns \nothing;
*/
bool test_nonlinear_arith(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x <= 100;
    //@ assert y <= 100;
    //@ assert x * y <= 10000;
    return x * y >= z;
}

/*@
    requires 1 <= x <= 100 && 1 <= y <= 100;
    ensures \result >= 0;
    ensures \result == x * y || \result == x + y;
    assigns \nothing;
*/
int func(int x, int y) {
    int product;
    int sum;
    int ret;
    
    //@ assert x * y <= 10000;
    
    product = x * y;
    sum = x + y;
    
    if (product > sum) {
        ret = product;
    } else {
        ret = sum;
    }
    
    return ret;
}
