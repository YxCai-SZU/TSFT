#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 1000000000);
    ensures \result == (((input) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t input)
{
    uint64_t n;
    uint64_t result;
    uint64_t count;
    
    n = input;
    result = n - 1;
    count = 0;
    
    /*@
        loop invariant 1 <= n && n <= 1000000000;
        loop invariant 0 <= count && count <= (n - 1) / 2;
        loop invariant result == n - 1 - 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        //@ assert result >= 2;
        result -= 2;
        count += 1;
        //@ assert result == n - 1 - 2 * count;
    }
    
    //@ assert count == (n - 1) / 2;
    return count;
}
