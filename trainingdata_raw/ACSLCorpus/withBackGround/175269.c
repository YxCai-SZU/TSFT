#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 50;

    // Logical function for conditional expression
    logic integer cond_minus_one(integer a) =
        a > 1 ? a - 1 : 0;

    // Logical function for final conditional
    logic integer final_cond(integer a_temp, integer c_temp) =
        a_temp + 1 < c_temp ? a_temp + 1 : c_temp;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result >= 0;
    ensures \result <= a + b + c;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result = 0;
    
    //@ assert 0 <= a <= 50;
    //@ assert 0 <= b <= 50;
    //@ assert 0 <= c <= 50;
    
    if (c > 0)
    {
        if (b < c)
        {
            //@ assert b * 2 <= 100;
            //@ assert b * 2 + 1 <= 101;
            result += b * 2 + 1;
            
            int64_t c_temp = c - (b + 1);
            int64_t a_temp = (a > 1) ? (a - 1) : 0;
            
            //@ assert a_temp >= 0;
            //@ assert c_temp >= 0;
            
            //@ assert a_temp == cond_minus_one(a);
            //@ assert c_temp == c - (b + 1);
            
            int64_t add_value = (a_temp + 1 < c_temp) ? (a_temp + 1) : c_temp;
            //@ assert add_value == final_cond(a_temp, c_temp);
            
            result += add_value;
        }
        else
        {
            //@ assert c * 2 <= 100;
            result += c * 2;
        }
    }
    else
    {
        result = b;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a + b + c;
    
    return result;
}
