#include <stdbool.h>

/*@
    predicate sum_ge_10(integer x, integer y) = x + y >= 10;
*/

/*@
    requires 0 <= x <= 23;
    requires 0 <= y <= 23;
    ensures \result == true <==> x + y >= 10;
    assigns \nothing;
*/
bool func(int x, int y)
{
    int z;
    //@ ghost int proof_sum;
    
    z = x + y;
    
    /*@ ghost
        proof_sum = x + y;
        //@ assert proof_sum < 10 || proof_sum >= 10;
    */
    
    return z >= 10;
}
