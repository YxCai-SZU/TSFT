#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures
        ((1 <= (a) <= 9) && (1 <= (b) <= 9) ==> \result == a * b) &&
        (((1 <= (a) <= 9) && !(1 <= (b) <= 9)) || (!(1 <= (a) <= 9) && (1 <= (b) <= 9)) || (!(1 <= (a) <= 9) && !(1 <= (b) <= 9)) ==> \result == -1);
    assigns \nothing;
*/
long func(long a, long b) {
    long result = -1;

    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    
    if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert a * b <= 81;
        result = a * b;
    }
    
    return result;
}
