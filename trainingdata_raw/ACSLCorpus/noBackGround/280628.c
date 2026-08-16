#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= (3 * ((a) + (p)));
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t result;
    size_t remainder;
    size_t pies;

    result = 3 * a + p;
    remainder = result % 2;
    
    //@ assert remainder == 0 || remainder == 1;
    
    if (remainder != 0)
    {
        result += 1;
    }
    
    pies = result / 2;
    
    //@ assert pies >= 0;
    //@ assert pies <= (3 * ((a) + (p)));
    
    return pies;
}
