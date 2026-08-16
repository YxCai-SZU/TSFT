#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (((a) * (a)) == ((a) * (b)) || 
                       ((b) * (b)) == ((a) * (b)) || 
                       ((a) * (a)) == ((a) * (b)) + ((b) * (b)) || 
                       ((b) * (b)) == ((a) * (b)) + ((b) * (b)));
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top of scope
    unsigned long long aa;
    unsigned long long ab;
    unsigned long long bb;
    bool result;
    
    //@ assert ((a) * (a)) <= 10000;
    //@ assert ((a) * (b)) <= 10000;
    //@ assert ((b) * (b)) <= 10000;
    
    aa = a * a;
    ab = a * b;
    bb = b * b;
    
    if (aa == ab || bb == ab || aa == ab + bb || bb == ab + bb) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
