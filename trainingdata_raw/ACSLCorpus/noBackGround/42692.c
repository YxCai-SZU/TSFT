#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == ((n) * (a) < (b) ? (n) * (a) : (b));
    ensures \result <= b;
    assigns \nothing;
*/
size_t func(size_t n, size_t a, size_t b)
{
    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 50 &&         1 <= (b) && (b) <= 50);
    
    size_t product;
    size_t result;
    
    product = n * a;
    
    //@ assert product <= 20 * 50;
    
    if (product < b)
    {
        result = product;
    }
    else
    {
        result = b;
    }
    
    //@ assert result == ((n) * (a) < (b) ? (n) * (a) : (b));
    //@ assert result <= b;
    
    return result;
}
