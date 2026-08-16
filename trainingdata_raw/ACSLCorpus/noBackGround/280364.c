#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> (n % 3 == 0 || k % 3 == 0 || k * 2 > n);
*/
bool func(unsigned long n, unsigned long k)
{
    bool is_n_divisible_by_3 = false;
    bool is_k_divisible_by_3 = false;
    bool is_k_times_2_greater_than_n;
    unsigned long temp_n;
    unsigned long temp_k;

    // Implementing the condition n % 3 == 0
    temp_n = n;
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 3 == n % 3;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
    }
    if (temp_n == 0)
    {
        is_n_divisible_by_3 = true;
    }

    // Implementing the condition k % 3 == 0
    temp_k = k;
    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant temp_k % 3 == k % 3;
        loop assigns temp_k;
        loop variant temp_k;
    */
    while (temp_k >= 3)
    {
        temp_k -= 3;
    }
    if (temp_k == 0)
    {
        is_k_divisible_by_3 = true;
    }

    // Implementing the condition k * 2 > n
    is_k_times_2_greater_than_n = (k * 2 > n);

    //@ assert is_n_divisible_by_3 == (n % 3 == 0);
    //@ assert is_k_divisible_by_3 == (k % 3 == 0);
    //@ assert is_k_times_2_greater_than_n == (k * 2 > n);

    // Combining the conditions
    if (is_n_divisible_by_3 || is_k_divisible_by_3 || is_k_times_2_greater_than_n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
