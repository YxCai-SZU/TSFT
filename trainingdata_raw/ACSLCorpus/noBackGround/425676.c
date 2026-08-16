#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a + c || \result == b + c || \result == a + d || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int max1;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    
    if (a > b) {
        x = a;
    } else {
        x = b;
    }
    
    if (c > d) {
        y = c;
    } else {
        y = d;
    }
    
    //@ assert x == (((a) > (b)) ? (a) : (b));
    //@ assert y == (((c) > (d)) ? (c) : (d));
    
    //@ assert INT_MIN <= x + y <= INT_MAX;
    max1 = x + y;
    
    //@ assert max1 == (((a) > (b)) ? (a) : (b)) + (((c) > (d)) ? (c) : (d));
    
    return max1;
}
