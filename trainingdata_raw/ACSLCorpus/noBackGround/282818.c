#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100);
    requires (1 <= (B) <= 100);
    ensures \result == ((A) * (B));
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert ((A) * (B)) <= 10000;
    
    ans = A * B;
    //@ assert ans == ((A) * (B));
    return ans;
}
