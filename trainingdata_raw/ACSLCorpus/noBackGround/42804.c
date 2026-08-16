#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == c + a;
*/
int func(int a, int b, int c)
{
    int min_ab;
    int min_bc;
    int min_ca;
    int min;
    
    //@ assert a + b >= 2 && a + b <= 200;
    //@ assert b + c >= 2 && b + c <= 200;
    //@ assert c + a >= 2 && c + a <= 200;
    
    if (a + b < b + c) {
        min_ab = a + b;
    } else {
        min_ab = b + c;
    }
    
    if (b + c < a + c) {
        min_bc = b + c;
    } else {
        min_bc = a + c;
    }
    
    if (c + a < a + b) {
        min_ca = c + a;
    } else {
        min_ca = a + b;
    }
    
    if (min_ab < min_bc) {
        min = min_ab;
    } else {
        min = min_bc;
    }
    
    if (min < min_ca) {
        //@ assert min == a + b || min == b + c || min == c + a;
        return min;
    } else {
        //@ assert min_ca == a + b || min_ca == b + c || min_ca == c + a;
        return min_ca;
    }
}
