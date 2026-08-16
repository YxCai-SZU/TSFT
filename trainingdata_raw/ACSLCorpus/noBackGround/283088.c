#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a == b) {
        if (b == c) {
            //@ assert a == c;
            result = 1;
        } else {
            //@ assert a != c;
            result = 2;
        }
    } else if (b == c) {
        //@ assert a != b;
        result = 2;
    } else if (a == c) {
        //@ assert a != b;
        result = 2;
    } else {
        //@ assert a != b && b != c && a != c;
        result = 3;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}
