#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        (N) <= (M) && (M) <= (N) * 2);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> ((N) * 2) == M;
    ensures \result == 0 ==> ((N) * 2) != M;
    assigns \nothing;
*/
int32_t func(uint32_t N, uint32_t M)
{
    //@ assert 1 <= N && N <= 100;
    //@ assert N <= M && M <= N * 2;
    
    //@ assert 2 <= N * 2 <= 200;
    
    if (N * 2 == M)
    {
        //@ assert N * 2 == M;
        return 1;
    }
    else
    {
        //@ assert N * 2 != M;
        return 0;
    }
}
