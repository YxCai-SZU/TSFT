#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (d) <= 20);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n, int d) {
    int result;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (d) <= 20);
    
    if (n > d) {
        //@ assert n > d;
        result = 0;
    } else {
        //@ assert n <= d;
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
