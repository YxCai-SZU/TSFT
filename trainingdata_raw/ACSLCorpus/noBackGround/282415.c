#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 10000) && (0 <= (A) && (A) <= 1000);
    ensures \result == (((N) % 500) <= A);
    assigns \nothing;
*/
bool func(int N, int A)
{
    int N_temp;
    
    N_temp = N;
    
    /*@
        loop invariant (0 <= (N_temp) && (N_temp) <= (N));
        loop invariant N_temp == N - 500 * ((N - N_temp) / 500);
        loop assigns N_temp;
        loop variant N_temp;
    */
    while (N_temp >= 500)
    {
        N_temp -= 500;
    }
    
    //@ assert N_temp == ((N) % 500);
    return N_temp <= A;
}
