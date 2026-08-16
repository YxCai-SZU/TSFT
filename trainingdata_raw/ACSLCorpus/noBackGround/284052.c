#include <limits.h>

/*@
    requires ((a) > INT_MIN && (a) < INT_MAX);
    requires ((b) > INT_MIN && (b) < INT_MAX);
    requires ((c) > INT_MIN && (c) < INT_MAX);
    ensures \result == 1 <==> (a < b && b < c);
*/
int func(int a, int b, int c) {
    int state;
    int i;
    
    state = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant state == a || state == b || state == c || state == 0;
        loop assigns i, state;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 0 <= i <= 2;
        
        if (i == 0) {
            state = a;
        } else if (i == 1) {
            state = b;
        } else if (i == 2) {
            state = c;
        }
        
        i = i + 1;
    }
    
    if (a < b && b < c) {
        return 1;
    } else {
        return 0;
    }
}
