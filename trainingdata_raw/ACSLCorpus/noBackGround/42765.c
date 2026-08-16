#include <stdbool.h>
#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100) && (\result) == (a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int res;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert 1 <= a * b && a * b <= 10000;
    
    res = a * b;
    //@ assert ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100) && (res) == (a) * (b));
    return res;
}
