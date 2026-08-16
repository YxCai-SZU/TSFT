#include <stddef.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
*/
size_t func(size_t a, size_t b)
{
    //@ assert 2 * 2 <= a * b <= 100 * 100;
    //@ assert a * b >= a + b;
    
    size_t ans = a * b - a - b + 1;
    //@ assert ans == ((a) * (b) - (a) - (b) + 1);
    //@ assert ans > 0;
    
    return ans;
}
