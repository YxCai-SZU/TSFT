#include <stddef.h>

/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (((n) + 1) / 2);
    ensures \result <= 500000;
*/
size_t func(size_t n)
{
    size_t ans;
    
    //@ assert (1 <= (n) <= 1000000);
    
    if (n % 2 == 0) {
        ans = n / 2;
    } else {
        ans = (n + 1) / 2;
    }
    
    //@ assert n / 2 <= ans;
    //@ assert ans <= (n + 1) / 2;
    //@ assert ans == (((n) + 1) / 2);
    //@ assert ans <= 500000;
    
    return ans;
}
