#include <stdint.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    // Variable declarations at top of scope
    int64_t res;
    
    //@ assert (0 <= (x) <= 1);
    
    //@ assert (1 - (x)) == 0 || (1 - (x)) == 1;
    
    res = 1 - x;
    
    //@ assert res == (1 - (x));
    
    return res;
}

int main()
{
    return 0;
}
