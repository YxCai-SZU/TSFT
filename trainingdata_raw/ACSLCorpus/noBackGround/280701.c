#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result <= a * n;
    ensures \result <= b;
    ensures \result == a * n || \result == b;
    assigns \nothing;
*/
size_t func(size_t n, size_t a, size_t b)
{
    size_t result;
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    //@ assert a * n <= 1000;
    
    if (a * n < b)
    {
        result = a * n;
    }
    else
    {
        result = b;
    }
    
    //@ assert result <= a * n;
    //@ assert result <= b;
    //@ assert result == a * n || result == b;
    return result;
}
