#include <stdbool.h>

/*@
    predicate is_even(integer y) = y % 2 == 0;
    predicate within_range(integer x, integer y) = 
        x * 2 <= y && y <= x * 4 && is_even(y);
*/

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result <==> (x * 2 <= y && y <= x * 4 && y % 2 == 0);
*/
bool func(unsigned int x, unsigned int y) {
    bool even;
    bool within_range;
    
    even = (y % 2 == 0);
    within_range = false;
    
    if (even) {
        within_range = (y >= x * 2) && (y <= x * 4);
    }
    
    //@ assert within_range <==> (x * 2 <= y && y <= x * 4 && y % 2 == 0);
    
    return within_range;
}
