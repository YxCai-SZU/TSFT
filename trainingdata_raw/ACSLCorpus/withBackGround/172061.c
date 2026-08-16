#include <limits.h>

/*@
    predicate in_range(integer x) = -1290 <= x <= 1290;
    
    logic integer cube(integer x) = x * x * x;
    
    lemma cube_bounds:
        \forall integer x; in_range(x) ==> 
            -1290 * 1290 * 1290 <= cube(x) <= 1290 * 1290 * 1290;
*/

/*@
    requires -1290 <= x <= 1290;
    ensures \result == x * x * x;
    ensures -1290 * 1290 * 1290 <= \result <= 1290 * 1290 * 1290;
*/
int func(int x) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert -1290 <= x <= 1290;
    
    // Calculate x * x * x
    result = x * x * x;
    
    //@ assert result >= -1290 * 1290 * 1290;
    //@ assert result <= 1290 * 1290 * 1290;
    
    return result;
}

int main() {
    return 0;
}
