#include <limits.h>

/*@
    requires (1 <= (N) <= 20) && (1 <= (M) <= 20);
    ensures \result == (((N) == 1 && (M) == 1) ? 1000000 : ((N) - 1) * ((M) - 1));
    assigns \nothing;
*/
int func(int N, int M)
{
    int result;

    //@ assert (1 <= (N) <= 20) && (1 <= (M) <= 20);
    
    if (N == 1 && M == 1)
    {
        //@ assert N == 1 && M == 1;
        result = 1000000;
    }
    else
    {
        //@ assert N != 1 || M != 1;
        //@ assert 0 <= N - 1 <= 19;
        //@ assert 0 <= M - 1 <= 19;
        //@ assert (N - 1) * (M - 1) <= 19 * 19;
        result = (N - 1) * (M - 1);
    }
    
    //@ assert result == (((N) == 1 && (M) == 1) ? 1000000 : ((N) - 1) * ((M) - 1));
    return result;
}
