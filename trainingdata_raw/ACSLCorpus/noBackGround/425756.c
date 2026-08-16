#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100 && 1 <= (w) <= 100);
    ensures \result == (s <= w);
    assigns \nothing;
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at top of scope
    unsigned int l;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    //@ assert w * 2 <= 200;
    l = w * 2 + 1;
    
    //@ assert w * 2 + 1 <= 201;
    //@ assert s <= 100;
    //@ assert w <= 100;
    
    return s <= w;
}
