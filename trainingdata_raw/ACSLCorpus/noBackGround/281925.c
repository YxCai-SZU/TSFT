#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int y;
    int z;
    int max1;
    int max2;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    
    x = a + b;
    y = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    
    z = a * b;
    
    if (x > y)
        max1 = x;
    else
        max1 = y;
    
    if (max1 > z)
        max2 = max1;
    else
        max2 = z;
    
    //@ assert max2 == ((a) + (b)) || max2 == ((a) - (b)) || max2 == ((a) * (b));
    //@ assert max2 >= ((a) + (b));
    //@ assert max2 >= ((a) - (b));
    //@ assert max2 >= ((a) * (b));
    
    return max2;
}
