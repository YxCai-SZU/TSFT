#include <limits.h>

/*@
    requires (1 <= (A) <= 20) && (1 <= (B) <= 20);
    ensures \result == A * B || \result == -1;
    ensures \result != A * B ==> (A * B > 20 || A * B < -20);
*/
int func(int A, int B)
{
    // Variable declarations at top of scope
    int ans;
    int result;
    
    //@ assert (1 <= (A) <= 20);
    //@ assert (1 <= (B) <= 20);
    
    //@ assert A * B <= 400;
    
    ans = A * B;
    
    if (ans > 20 || ans < -20) {
        result = -1;
    } else {
        result = ans;
    }
    
    return result;
}
