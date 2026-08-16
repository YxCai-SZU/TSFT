#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= 400;
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    // Variable declarations at scope top
    size_t sum = 0;
    size_t pies = 0;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= p && p <= 100;
    
    //@ assert 3 * a <= 300;
    sum = 3 * a + p;
    
    //@ assert sum <= 400;
    pies = sum / 2;
    
    //@ assert pies >= 0;
    //@ assert pies <= 400;
    return pies;
}
