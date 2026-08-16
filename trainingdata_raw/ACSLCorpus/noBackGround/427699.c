#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures \result >= 1 && \result <= N;
    ensures \result == N - (i - 1);
*/
int64_t func(int64_t N, int64_t i)
{
    int64_t answer;
    //@ assert (1 <= (N) <= 100 && 1 <= (i) <= (N));
    answer = N - (i - 1);
    
    if (answer == 0)
    {
        //@ assert N >= 1 && N <= 100;
        return N;
    }
    else
    {
        //@ assert answer >= 1 && answer <= N;
        //@ assert answer == N - (i - 1);
        return answer;
    }
}
