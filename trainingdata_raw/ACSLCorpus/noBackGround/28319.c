#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 20) && (1 <= (B) && (B) <= 20);
    ensures (A > 9 || B > 9) ==> \result == -1;
    ensures (A <= 9 && B <= 9) ==> \result == A * B;
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    //@ assert A * B <= 400;
    ans = A * B;
    //@ assert (A > 9 || B > 9) || (A <= 9 && B <= 9);
    return (A > 9 || B > 9) ? -1 : ans;
}
