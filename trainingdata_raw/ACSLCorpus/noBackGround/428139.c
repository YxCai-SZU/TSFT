#include <stddef.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at top
    size_t res;

    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    
    res = r * r;
    
    //@ assert res == ((r) * (r));
    return res;
}

/*@
    assigns \nothing;
*/
void test_func(void)
{
    //@ assert ((1) * (1)) == 1;
    //@ assert ((2) * (2)) == 4;
    //@ assert ((100) * (100)) == 10000;
}
