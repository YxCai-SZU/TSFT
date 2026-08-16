#include <limits.h>

/*@
    requires ((2 <= ((a)) <= 100) && (2 <= ((b)) <= 100));
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
    assigns \nothing;
*/
int func(int a, int b) {
    int result;
    
    //@ assert (2 <= (a) <= 100);
    //@ assert (2 <= (b) <= 100);
    //@ assert a * b >= 4 && a * b <= 10000;
    //@ assert a * b - a >= 4 - 100;
    //@ assert a * b - a - b >= 4 - 100 - 100;
    //@ assert a * b - a - b + 1 >= 4 - 100 - 100 + 1;
    
    result = a * b - a - b + 1;
    return result;
}
