#include <stddef.h>

/*@
    requires (1 <= (s) && (s) <= 100);
    ensures \result == ((s) * (s));
    assigns \nothing;
*/
size_t func(size_t s)
{
    // Variable declarations at top of scope
    size_t res;
    
    //@ assert (1 <= (s) && (s) <= 100);
    //@ assert ((s) * (s)) <= 10000;
    
    res = s * s;
    return res;
}

int main(void)
{
    return 0;
}
