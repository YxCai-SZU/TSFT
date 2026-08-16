#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;

    logic integer half_plus_one(integer i) = (i + 1) / 2;

    lemma half_plus_one_monotonic:
        \forall integer i, j; 0 <= i <= j ==> half_plus_one(i) <= half_plus_one(j);
*/

/*@
    requires valid_range(n);
    ensures \result == half_plus_one(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result = 0;
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant result == half_plus_one(i);
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert i < n;
        
        if (i % 2 == 0)
        {
            result += 1;
        }
        
        i += 1;
        
        //@ assert result == half_plus_one(i);
    }
    
    //@ assert i == n;
    //@ assert result == half_plus_one(n);
    
    return result;
}
