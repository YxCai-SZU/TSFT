#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 179;
    
    logic integer manual_div2(integer x, integer count) = x - 2 * count;
    
    logic integer result_value(integer x) = (x / 2) + (x % 2);
*/

/*@
    requires valid_range(x);
    ensures \result >= 1 && \result <= 360;
    ensures \result == result_value(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int temp_x;
    int count;
    
    result = 0;
    temp_x = x;
    count = 0;
    
    //@ assert valid_range(x);
    //@ assert 0 <= temp_x <= x;
    //@ assert temp_x == manual_div2(x, count);
    //@ assert 0 <= count <= x / 2;
    
    /*@
        loop invariant 1 <= x <= 179;
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x == manual_div2(x, count);
        loop invariant 0 <= count <= x / 2;
        loop invariant temp_x >= 0;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        //@ assert temp_x >= 2;
        temp_x = temp_x - 2;
        count = count + 1;
        //@ assert temp_x == manual_div2(x, count);
    }
    
    //@ assert temp_x == 0 || temp_x == 1;
    
    if (temp_x == 1)
    {
        result = count + 1;
    }
    else
    {
        result = count;
    }
    
    //@ assert result == result_value(x);
    //@ assert result >= 1 && result <= 360;
    
    return result;
}

/*@
    lemma result_bounds: \forall integer x; valid_range(x) ==> result_value(x) >= 1 && result_value(x) <= 360;
*/
