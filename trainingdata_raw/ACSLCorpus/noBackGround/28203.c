#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a + b || \result == 2*a - 1 || \result == 2*b - 1;
    ensures \result >= 0;
*/
int func(int a, int b) {
    int result;
    
    //@ assert (3 <= (a) && (a) <= 20);
    //@ assert (3 <= (b) && (b) <= 20);
    
    if (a >= b + 1) {
        //@ assert a >= 3;
        //@ assert b + 1 <= 20;
        //@ assert a >= b + 1;
        //@ assert 2*a - 1 >= 0;
        result = a * 2 - 1;
    } else if (b >= a + 1) {
        //@ assert b >= 3;
        //@ assert a + 1 <= 20;
        //@ assert b >= a + 1;
        //@ assert 2*b - 1 >= 0;
        result = b * 2 - 1;
    } else {
        //@ assert a >= 3;
        //@ assert b >= 3;
        //@ assert a + b >= 0;
        result = a + b;
    }
    
    return result;
}
