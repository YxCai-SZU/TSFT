#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (((a) < 10 && (b) < 10) ==> \result == a * b) && 
            (((a) >= 10 || (b) >= 10) ==> \result == -1);
    assigns \nothing;
*/
int func(int a, int b) {
    int result;
    
    if (a < 10 && b < 10) {
        //@ assert 1 <= a <= 9;
        //@ assert 1 <= b <= 9;
        //@ assert a * b <= 81;
        result = a * b;
    } else {
        result = -1;
    }
    
    return result;
}
