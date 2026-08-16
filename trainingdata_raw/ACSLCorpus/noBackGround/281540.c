#include <stddef.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a + b + 1;
    ensures \result >= 0;
    ensures \result == a + b || \result == a + b + 1;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t result;
    
    result = a + b;
    
    //@ assert result == a + b;
    
    if (result % 2 == 1)
    {
        result += 1;
        //@ assert result == a + b + 1;
    }
    
    //@ assert result == a + b || result == a + b + 1;
    //@ assert result >= 0;
    //@ assert result <= a + b + 1;
    
    return result;
}
