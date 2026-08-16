#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 == 1;
    
    logic integer half(integer n) = n / 2;
    logic integer mod_two(integer n) = n % 2;
    
    lemma half_mod_property:
        \forall integer n; n >= 0 ==> n == 2 * half(n) + mod_two(n);
*/

/*@
    requires 1 <= N <= 100;
    requires 1 <= K <= 100;
    ensures \result == (N % 2 == 0 && N / 2 >= K) || (N % 2 == 1 && N / 2 + 1 >= K);
*/
bool func(unsigned int N, unsigned int K)
{
    bool ans = false;
    unsigned int n = N;
    unsigned int k = K;
    unsigned int n_div_2 = 0;
    unsigned int temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= n_div_2 <= n / 2;
        loop invariant temp_n == n - 2 * n_div_2;
        loop invariant 1 <= N <= 100;
        loop invariant 1 <= K <= 100;
        loop assigns temp_n, n_div_2;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        n_div_2 += 1;
    }
    
    unsigned int n_mod_2 = (temp_n == 1) ? 1 : 0;
    
    if (n_mod_2 == 0)
    {
        //@ assert n_mod_2 == 0;
        if (n_div_2 >= k)
        {
            ans = true;
        }
    }
    else
    {
        //@ assert n_mod_2 == 1;
        if (n_div_2 + 1 >= k)
        {
            ans = true;
        }
    }
    
    //@ assert n_div_2 == N / 2;
    //@ assert n_mod_2 == N % 2;
    
    return ans;
}
