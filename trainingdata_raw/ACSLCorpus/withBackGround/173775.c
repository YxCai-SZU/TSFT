#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    ensures \result == (x * 2 <= y);
*/
bool func(int x, int y) {
    int i;
    int product;
    
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    
    i = 1;
    product = 0;
    
    /*@
        loop invariant 1 <= i <= x + 1;
        loop invariant product == (i - 1) * 2;
        loop invariant i > 1 ==> product <= 200;
        loop assigns i, product;
    */
    while (i <= x) {
        product += 2;
        i += 1;
        
        //@ assert product == (i - 1) * 2;
    }
    
    //@ assert product == x * 2;
    return product <= y;
}
