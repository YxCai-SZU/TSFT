#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_bounds(integer x) = x >= 0 && x <= 46340;
    predicate area_correct(integer s, integer a) = a == s * s;
*/

/*@
    requires within_bounds(side_length);
    ensures area_correct(side_length, \result);
    ensures non_negative(\result);
*/
int32_t square_area(int32_t side_length) {
    int32_t ret;
    
    //@ assert non_negative(side_length);
    //@ assert side_length <= 46340;
    
    ret = side_length * side_length;
    
    //@ assert area_correct(side_length, ret);
    //@ assert non_negative(ret);
    
    return ret;
}
