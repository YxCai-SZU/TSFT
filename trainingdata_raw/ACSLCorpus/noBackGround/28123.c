#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= (a + b + c) * 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ab;
    int bc;
    int ca;
    int max;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a > b) {
        ab = a - b;
    } else {
        ab = b - a;
    }
    //@ assert ab >= 0;
    
    if (b > c) {
        bc = b - c;
    } else {
        bc = c - b;
    }
    //@ assert bc >= 0;
    
    if (c > a) {
        ca = c - a;
    } else {
        ca = a - c;
    }
    //@ assert ca >= 0;
    
    max = ab + bc;
    //@ assert max >= 0;
    
    if (ca + bc > max) {
        max = ca + bc;
    }
    //@ assert max >= 0;
    
    if (ab + ca > max) {
        max = ab + ca;
    }
    //@ assert max >= 0;
    
    //@ assert max <= (a + b + c) * 3;
    return max;
}
