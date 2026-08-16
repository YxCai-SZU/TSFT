#include <stdint.h>

/*@
    requires (2 <= (N) && (N) <= 1000000000000000000 &&
        1 <= (A) && (A) < (B) && (B) <= (N));
    ensures 0 <= \result && \result <= N;
    ensures \result == ((N) == (B) - (A) ? 0 :
        (N) > (B) - (A) ? ((B) - (A) - 1) :
        ((B) - (A) - 1) - ((N) - 1));
*/
uint64_t func(uint64_t N, uint64_t A, uint64_t B)
{
    uint64_t ans;
    uint64_t diff;

    //@ assert (2 <= (N) && (N) <= 1000000000000000000 &&         1 <= (A) && (A) < (B) && (B) <= (N));
    
    diff = B - A;
    
    if (N == diff)
    {
        ans = 0;
    }
    else if (N > diff)
    {
        //@ assert diff - 1 >= 0;
        ans = diff - 1;
    }
    else
    {
        //@ assert diff - 1 >= N - 1;
        ans = (diff - 1) - (N - 1);
    }

    //@ assert 0 <= ans && ans <= N;
    return ans;
}
