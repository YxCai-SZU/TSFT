#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer div_by_2(integer x) = (x + 1) / 2;
    
    lemma division_property:
        \forall integer x; valid_range(x) ==> div_by_2(x) >= 0;
*/

/*@
    requires valid_range(x);
    ensures \result == div_by_2(x);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result;
    int64_t temp;
    int64_t count;
    
    result = 0;
    temp = x + 1;
    count = 0;
    
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant temp >= 0;
        loop invariant temp == x + 1 - 2 * count;
        loop invariant 0 <= count <= div_by_2(x);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == div_by_2(x);
    return result;
}
