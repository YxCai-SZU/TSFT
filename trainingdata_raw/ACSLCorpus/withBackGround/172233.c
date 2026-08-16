#include <stdbool.h>

/*@ predicate is_ge_30(integer x) = x >= 30; */

/*@
    requires -40 <= x <= 40;
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    int i;
    int target;
    
    if (x >= 30) {
        result = true;
    } else {
        i = 0;
        target = 10000000;
        
        /*@
            loop invariant i <= target;
            loop invariant i >= 0;
            loop assigns i;
            loop variant target - i;
        */
        while (i < target) {
            i = i + 1;
        }
        
        //@ assert i == target;
        result = false;
    }
    
    return result;
}
