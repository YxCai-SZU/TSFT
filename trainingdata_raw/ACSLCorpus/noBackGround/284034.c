#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a) * 10 + (b) + (c)) || \result == ((a) + (b) * 10 + (c)) || \result == ((a) + (b) + (c) * 10);
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    //@ assert ((a) * 10 + (b) + (c)) >= 12;
    //@ assert ((a) + (b) * 10 + (c)) >= 12;
    //@ assert ((a) + (b) + (c) * 10) >= 12;
    
    int max1;
    int max2;
    
    if (a * 10 + b + c > a + b * 10 + c) {
        max1 = a * 10 + b + c;
    } else {
        max1 = a + b * 10 + c;
    }
    
    //@ assert max1 == ((a) * 10 + (b) + (c)) || max1 == ((a) + (b) * 10 + (c));
    
    if (max1 > a + b + c * 10) {
        max2 = max1;
    } else {
        max2 = a + b + c * 10;
    }
    
    //@ assert max2 == ((a) * 10 + (b) + (c)) || max2 == ((a) + (b) * 10 + (c)) || max2 == ((a) + (b) + (c) * 10);
    //@ assert max2 >= 12;
    
    return max2;
}
