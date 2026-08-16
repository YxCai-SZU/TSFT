#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((n) * (m) - ((n) - 1) - ((m) - 1)) || \result == ((n) * (m) - ((n) - 1) - ((m) - 1)) + 1;
    assigns \nothing;
*/
int func(int n, int m) {
    // Declare all variables at the top
    int result;
    int ret_val;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    //@ assert n * m <= 400;
    //@ assert ((n) * (m) - ((n) - 1) - ((m) - 1)) >= 0;

    result = n * m - (n - 1) - (m - 1);

    if (result == 0) {
        //@ assert ((n) * (m) - ((n) - 1) - ((m) - 1)) == 0;
        ret_val = 1;
        //@ assert ret_val == ((n) * (m) - ((n) - 1) - ((m) - 1)) + 1;
    } else {
        //@ assert result == ((n) * (m) - ((n) - 1) - ((m) - 1));
        ret_val = result;
        //@ assert ret_val == ((n) * (m) - ((n) - 1) - ((m) - 1));
    }
    
    return ret_val;
}
