#include <limits.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&
        (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);
    ensures \result >= 0;
    ensures \result == b + c || \result == a + c || \result == a + d || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    
    //@ assert ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&         (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);
    
    if (b + c > a + d) {
        result = b + c;
    } else {
        result = a + d;
    }
    
    //@ assert result == b + c || result == a + d;
    
    if (a + c > result) {
        result = a + c;
    }
    
    //@ assert result == b + c || result == a + c || result == a + d;
    
    if (b + d > result) {
        result = b + d;
    }
    
    //@ assert result == b + c || result == a + c || result == a + d || result == b + d;
    
    return result;
}
