#include <stdbool.h>

/*@ predicate is_even(integer val) = val % 2 == 0; */
/*@ predicate double_relation(integer x, integer y) = y >= 2*x; */


bool func(unsigned int x, unsigned int y) {
    bool result;
    
    //@ assert y % 2 == 0 && y >= 2*x ==> (y % 2 == 0 && y >= 2*x);
    
    result = (y % 2 == 0) && (y >= 2 * x);
    return result;
}
