#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        0 <= (R) && (R) <= 4111);
    ensures \result == ((N) >= 10 ? (R) : (R) + 100 * (10 - (N)));
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t R)
{
    int64_t ans;
    //@ assert 1 <= N && N <= 100;
    //@ assert 0 <= R && R <= 4111;
    
    if (N >= 10) {
        ans = R;
        //@ assert ans == R;
    } else {
        //@ assert N < 10;
        //@ assert 10 - N > 0;
        //@ assert 100 * (10 - N) >= 0;
        //@ assert 100 * (10 - N) <= 100 * 9;
        //@ assert R + 100 * (10 - N) >= 0;
        //@ assert R + 100 * (10 - N) <= 4111 + 100 * 9;
        ans = R + 100 * (10 - N);
        //@ assert ans == R + 100 * (10 - N);
    }
    
    //@ assert ans == ((N) >= 10 ? (R) : (R) + 100 * (10 - (N)));
    return ans;
}
