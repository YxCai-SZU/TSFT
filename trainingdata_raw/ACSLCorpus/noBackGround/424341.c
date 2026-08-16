#include <stdint.h>

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == (a - 1) * (b - 1);
*/
int32_t func(int32_t a, int32_t b)
{
    uint32_t a_unsigned;
    uint32_t b_unsigned;
    uint32_t result_unsigned;
    int32_t result;
    
    //@ assert (2 <= (a) && (a) <= 100);
    //@ assert (2 <= (b) && (b) <= 100);
    
    if (a < 0)
    {
        a_unsigned = (uint32_t)(-a);
    }
    else
    {
        a_unsigned = (uint32_t)a;
    }
    
    if (b < 0)
    {
        b_unsigned = (uint32_t)(-b);
    }
    else
    {
        b_unsigned = (uint32_t)b;
    }
    
    //@ assert a_unsigned == ((a) < 0 ? -(a) : (a));
    //@ assert b_unsigned == ((b) < 0 ? -(b) : (b));
    
    //@ assert a_unsigned > 0 && a_unsigned <= 100;
    //@ assert b_unsigned > 0 && b_unsigned <= 100;
    
    //@ assert a_unsigned - 1 >= 0;
    //@ assert b_unsigned - 1 >= 0;
    //@ assert (a_unsigned - 1) * (b_unsigned - 1) <= 99 * 99;
    
    //@ assert a - 1 >= 0;
    //@ assert b - 1 >= 0;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    result_unsigned = (a_unsigned - 1) * (b_unsigned - 1);
    
    if ((a < 0 && b < 0) || (a > 0 && b > 0))
    {
        result = (int32_t)result_unsigned;
    }
    else
    {
        result = -(int32_t)result_unsigned;
    }
    
    //@ assert result == (a - 1) * (b - 1);
    return result;
}
