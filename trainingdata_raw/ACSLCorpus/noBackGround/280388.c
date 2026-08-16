#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 10000) && (0 <= (A) && (A) <= 1000);
    ensures ((\result) == ((N) % 500 <= (A)));
    assigns \nothing;
*/
bool func(int N, int A)
{
    int n_mod_500;
    n_mod_500 = N;
    
    /*@
        loop invariant 0 <= n_mod_500 <= N;
        loop invariant N % 500 == n_mod_500 % 500;
        loop assigns n_mod_500;
        loop variant n_mod_500;
    */
    while (n_mod_500 >= 500)
    {
        n_mod_500 -= 500;
    }
    
    //@ assert n_mod_500 == N % 500;
    
    return n_mod_500 <= A;
}

int main(void)
{
    return 0;
}
