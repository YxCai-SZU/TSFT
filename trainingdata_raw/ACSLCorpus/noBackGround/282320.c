#include <limits.h>

/*@
    requires x >= -1000 && x <= 1000;
    ensures \result >= 0;
    ensures \result == ((x) < 0 ? -(x) : (x));
    assigns \nothing;
*/
int func(int x) {
    int abs_x;
    int result;
    int i;
    
    //@ assert x >= -1000 && x <= 1000;
    
    if (x < 0) {
        abs_x = -x;
    } else {
        abs_x = x;
    }
    
    //@ assert (((x) < 0 ==> (abs_x) == -(x)) && ((x) >= 0 ==> (abs_x) == (x)));
    //@ assert abs_x >= 0;
    
    result = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i && i <= abs_x;
        loop invariant result == i;
        loop invariant abs_x >= 0;
        loop invariant x >= -1000 && x <= 1000;
        loop invariant (((x) < 0 ==> (abs_x) == -(x)) && ((x) >= 0 ==> (abs_x) == (x)));
        loop assigns i, result;
        loop variant abs_x - i;
    */
    while (i < abs_x) {
        //@ assert i < abs_x;
        result += 1;
        i += 1;
        //@ assert result == i;
    }
    
    //@ assert i == abs_x;
    //@ assert result == abs_x;
    //@ assert result >= 0;
    
    return result;
}
