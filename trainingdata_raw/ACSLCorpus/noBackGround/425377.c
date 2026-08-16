#include <stdbool.h>

/*@
    requires (0 <= (a) <= 20) && (0 <= (b) <= 20) && (0 <= (c) <= 20);
    ensures \result == (a * b <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool res;
    unsigned int prod;
    
    //@ assert 0 <= a <= 20;
    //@ assert 0 <= b <= 20;
    //@ assert 0 <= c <= 20;
    
    // Apply the lemma to establish product bounds
    //@ ghost product_range: 0 <= a * b <= 400;
    
    prod = a * b;
    
    //@ assert 0 <= prod <= 400;
    
    res = (prod <= c);
    
    //@ assert res == (a * b <= c);
    
    return res;
}
