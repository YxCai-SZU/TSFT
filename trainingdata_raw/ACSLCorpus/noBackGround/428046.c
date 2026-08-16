#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (((n) - 1) / 2);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t temp;
    int64_t count;
    
    result = 0;
    temp = n - 1;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 1000000;
        loop invariant temp >= 0;
        loop invariant temp == n - 1 - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= (((n) - 1) / 2);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        int64_t old_temp = temp;
        int64_t old_count = count;
        
        //@ assert temp >= 2;
        temp -= 2;
        //@ assert temp == old_temp - 2;
        count += 1;
        //@ assert count == old_count + 1;
    }
    
    result = count;
    //@ assert result == (((n) - 1) / 2);
    return result;
}
