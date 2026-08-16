#include <stdbool.h>

/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c) {
    int state = 0;
    
    //@ assert state == 0;
    
    if (a < b) {
        state += 1;
        //@ assert state == 1;
    }
    
    if (b < c) {
        state += 1;
        //@ assert state == 1 || state == 2;
    }
    
    if (state == 2) {
        //@ assert ((a) < (b) && (b) < (c));
        return true;
    } else {
        //@ assert !((a) < (b) && (b) < (c));
        return false;
    }
}
