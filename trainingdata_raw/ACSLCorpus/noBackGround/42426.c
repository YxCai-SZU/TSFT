#include <stdbool.h>
/*@
    requires (1 <= (N) <= 20 && 1 <= (A) <= 100 && 1 <= (B) <= 2000);
    ensures \result == N * A || \result == B;
    ensures \result <= B;
    assigns \nothing;
*/
int func(int N, int A, int B)
{
    int ans;
    //@ assert (1 <= (N) <= 20 && 1 <= (A) <= 100 && 1 <= (B) <= 2000);
    //@ assert ((N) * (A)) <= 2000;
    
    if (N * A < B) {
        ans = N * A;
    } else {
        ans = B;
    }
    
    //@ assert ans == N * A || ans == B;
    //@ assert ans <= B;
    return ans;
}
