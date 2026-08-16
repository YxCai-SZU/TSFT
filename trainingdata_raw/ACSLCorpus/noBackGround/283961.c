#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert a * b >= 1 && a * b <= 10000 * 10000;
    //@ assert c * d >= 1 && c * d <= 10000 * 10000;
    
    int result;
    
    if (a * b > c * d) {
        result = a * b;
    } else {
        result = c * d;
    }
    
    //@ assert result == a * b || result == c * d;
    //@ assert result >= 1;
    
    return result;
}
