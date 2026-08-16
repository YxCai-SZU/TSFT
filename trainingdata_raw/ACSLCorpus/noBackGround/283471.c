#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a) + (b)) || \result == ((b) + (c)) || \result == ((c) + (a));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    max = a + b;
    
    //@ assert max == ((a) + (b));
    
    if (b + c > max)
    {
        max = b + c;
        //@ assert max == ((b) + (c));
    }
    
    if (c + a > max)
    {
        max = c + a;
        //@ assert max == ((c) + (a));
    }
    
    //@ assert max == ((a) + (b)) || max == ((b) + (c)) || max == ((c) + (a));
    //@ assert max >= 0;
    
    return max;
}
