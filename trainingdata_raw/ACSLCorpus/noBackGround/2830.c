#include <limits.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures (n > 9 || m > 9) ==> \result == -1;
    ensures (n <= 9 && m <= 9) ==> \result == n * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) <= 20) && (1 <= (m) <= 20);
    
    if (n > 9 || m > 9) {
        //@ assert n > 9 || m > 9;
        result = -1;
    } else {
        //@ assert n <= 9 && m <= 9;
        //@ assert (1 <= (n) <= 9) && (1 <= (m) <= 9);
        //@ assert 1 * 1 <= n * m <= 9 * 9;
        result = n * m;
    }
    
    return result;
}
