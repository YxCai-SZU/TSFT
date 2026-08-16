#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(uint64_t r)
{
    // Variable declarations at top of scope
    int64_t result = 0;
    uint64_t i = 0;
    int64_t pi = 3;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert 0 <= i <= r;
    //@ assert result >= 0;
    //@ assert result <= (6 * (i));
    
    /*@
        loop invariant 0 <= i <= r;
        loop invariant result >= 0;
        loop invariant result <= (6 * (i));
        loop assigns i, result;
        loop variant r - i;
    */
    while (i < r)
    {
        //@ assert result >= 0;
        //@ assert result <= (6 * (i));
        
        result += 6;
        i += 1;
        
        //@ assert result >= 0;
        //@ assert result <= (6 * (i));
    }
    
    //@ assert result >= 0;
    return result;
}
