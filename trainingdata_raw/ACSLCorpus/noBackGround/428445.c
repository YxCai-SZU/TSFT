#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 1000000000000000);
    ensures \result >= 0;
    ensures \result <= (2 * ((x) / 11) + 2);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t div = 11;
    int64_t rem = 0;
    int64_t final_result = 0;
    
    //@ assert (1 <= (x) && (x) <= 1000000000000000);
    
    /*@
        loop invariant 0 <= temp_x && temp_x <= x;
        loop invariant result >= 0;
        loop invariant result <= (x - temp_x) / div;
        loop invariant x == temp_x + result * div;
        loop assigns temp_x, result;
        loop variant temp_x;
    */
    while (temp_x >= div)
    {
        //@ assert temp_x >= div;
        temp_x -= div;
        result += 1;
        //@ assert x == temp_x + result * div;
    }
    
    rem = temp_x;
    
    if (rem == 0)
    {
        final_result = result * 2;
    }
    else if (rem <= 6)
    {
        final_result = result * 2 + 1;
    }
    else
    {
        final_result = result * 2 + 2;
    }
    
    //@ assert final_result >= 0;
    //@ assert final_result <= (2 * ((x) / 11) + 2);
    
    return final_result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
