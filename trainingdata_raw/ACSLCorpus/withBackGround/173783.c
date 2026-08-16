#include <stdbool.h>

/*@
    predicate condition_holds(integer k, integer x) =
        k * 500 >= x;
*/

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == true <==> condition_holds(k, x);
*/
bool func(int k, int x) {
    int product;
    bool result;

    product = k * 500;
    
    if (product >= x) {
        //@ assert condition_holds(k, x);
        result = true;
    } else {
        //@ assert !condition_holds(k, x);
        result = false;
    }
    
    return result;
}
