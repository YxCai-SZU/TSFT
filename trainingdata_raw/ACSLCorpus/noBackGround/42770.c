#include <stdbool.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (K) <= 100);
    ensures \result == (K <= (((N) + 1) / 2));
*/
bool func(int N, int K)
{
    int N_plus_1;
    int N_plus_1_div_2;
    int count;

    N_plus_1 = N + 1;
    N_plus_1_div_2 = 0;
    count = 0;

    /*@
        loop invariant 0 <= N_plus_1 <= N + 1;
        loop invariant 0 <= count <= (((N) + 1) / 2);
        loop invariant N_plus_1 == N + 1 - 2 * count;
        loop invariant N_plus_1_div_2 == 0;
        loop assigns N_plus_1, count;
    */
    while (N_plus_1 > 1)
    {
        //@ assert N_plus_1 >= 2;
        N_plus_1 = N_plus_1 - 2;
        count = count + 1;
    }

    N_plus_1_div_2 = count;
    //@ assert N_plus_1_div_2 == (((N) + 1) / 2);
    
    return K <= N_plus_1_div_2;
}
