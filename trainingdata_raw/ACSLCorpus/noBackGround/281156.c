#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (c) <= 20) && (1 <= (d) <= 20);
    ensures \result == ((a) - (c)) || \result == ((b) - (d)) || 
            \result == ((a) - (d)) || \result == ((b) - (c));
    ensures -20 <= \result <= 20;
*/
int func(int a, int b, int c, int d)
{
    int x1;
    int x2;
    int x3;
    int x4;
    int max_value;

    x1 = a - c;
    x2 = b - d;
    x3 = a - d;
    x4 = b - c;

    max_value = x1;
    //@ assert max_value == ((a) - (c));
    
    if (x2 > max_value)
    {
        max_value = x2;
    }
    //@ assert max_value == ((a) - (c)) || max_value == ((b) - (d));
    
    if (x3 > max_value)
    {
        max_value = x3;
    }
    //@ assert max_value == ((a) - (c)) || max_value == ((b) - (d)) || max_value == ((a) - (d));
    
    if (x4 > max_value)
    {
        max_value = x4;
    }
    //@ assert max_value == ((a) - (c)) || max_value == ((b) - (d)) || max_value == ((a) - (d)) || max_value == ((b) - (c));
    
    return max_value;
}
