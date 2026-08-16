#include <stdint.h>

/*@
    requires 1 <= n && n <= 1000000;
    ensures \result >= 0 && \result <= n;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t count;
    int64_t i;
    int64_t remainder;
    int64_t temp_count;
    
    result = 0;
    count = 0;
    i = 1;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 1000000 &&
        1 <= (i) && (i) <= (n) + 1 &&
        (((count)) >= 0 && ((count)) <= ((i)) - 1 && ((count)) <= 1000000) &&
        (result) >= 0 && (result) <= (n) &&
        ((i) > 1 ==> (count) <= (n)));
        loop assigns i, count, remainder, temp_count;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        remainder = i;
        
        /*@
            loop invariant (1 <= (n) && (n) <= 1000000 &&
        1 <= (i) && (i) <= (n) + 1 &&
        0 <= (remainder) && (remainder) <= (i) &&
        (remainder) <= 1000000);
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= 8)
        {
            remainder -= 8;
        }
        
        if (remainder == 0)
        {
            temp_count = count + 1;
            
            /*@
                loop invariant (1 <= (n) && (n) <= 1000000 &&
        1 <= (i) && (i) <= (n) + 1 &&
        0 <= (temp_count) && (temp_count) <= (count) + 1 &&
        (temp_count) <= 1000000);
                loop assigns temp_count;
                loop variant temp_count;
            */
            while (temp_count >= 8)
            {
                temp_count -= 8;
            }
            
            count = temp_count;
        }
        
        i += 1;
    }
    
    result = count;
    
    //@ assert result >= 0 && result <= n;
    return result;
}
