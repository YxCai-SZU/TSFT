#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 20) && (1 <= (m) && (m) <= 20);
    ensures (n <= 9 && m <= 9 ==> \result == n * m) && 
            (n > 9 || m > 9 ==> \result == -1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    //@ assert (1 <= (n) && (n) <= 20) && (1 <= (m) && (m) <= 20);
    
    if (n <= 9 && m <= 9) {
        //@ assert (1 <= (n) && (n) <= 9) && (1 <= (m) && (m) <= 9);
        //@ assert 1 <= n * m && n * m <= 81;
        result = n * m;
    } else {
        //@ assert n > 9 || m > 9;
        result = -1;
    }
    
    return result;
}
