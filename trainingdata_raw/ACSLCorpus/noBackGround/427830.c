#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) * (n) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    uint32_t count;
    uint32_t temp_result;
    
    // Precondition verification
    //@ assert 1 <= n && n <= 100;
    
    // Arithmetic safety checks
    //@ assert n * n <= 10000;
    //@ assert n * n + 1 <= 10001;
    
    result = n * n + 1;
    count = 0;
    temp_result = result;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant temp_result >= 0;
        loop invariant result == n * n + 1;
        loop invariant count * 2 + temp_result == n * n + 1;
        loop invariant count <= (n * n + 1) / 2;
        loop assigns temp_result, count;
        loop variant temp_result;
    */
    while (temp_result >= 2)
    {
        //@ assert temp_result >= 2;
        temp_result -= 2;
        count += 1;
        //@ assert count * 2 + temp_result == n * n + 1;
    }
    
    result = count;
    
    // Postcondition verification
    //@ assert result == (n * n + 1) / 2;
    
    return result;
}

int main(void)
{
    return 0;
}
