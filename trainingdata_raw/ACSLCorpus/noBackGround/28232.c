#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == a * 10 + b + c || \result == a + b * 10 + c || \result == a + b + c * 10;
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    int max;
    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    
    if (a > b && a > c)
    {
        max = a;
    }
    else if (b > a && b > c)
    {
        max = b;
    }
    else
    {
        max = c;
    }
    
    //@ assert max == a || max == b || max == c;
    //@ assert max >= 1;
    
    return a * 10 + b + c;
}
