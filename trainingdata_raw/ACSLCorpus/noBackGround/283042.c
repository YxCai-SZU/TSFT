#include <stdbool.h>

/*@
    requires ((1) <= (a) && (a) <= (500));
    requires ((1) <= (b) && (b) <= (500));
    requires ((1) <= (c) && (c) <= (1000));
    ensures \result == (c <= a + b);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int d;
    
    //@ assert ((1) <= (a) && (a) <= (500));
    //@ assert ((1) <= (b) && (b) <= (500));
    //@ assert ((1) <= (c) && (c) <= (1000));
    
    if (a + b < c) {
        d = a + b;
        //@ assert d == a + b;
    } else {
        d = c;
        //@ assert d == c;
    }
    
    //@ assert d == a + b || d == c;
    
    return d == c;
}
