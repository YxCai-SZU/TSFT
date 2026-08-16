#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 &&
        1 <= (m) <= 1000 &&
        0 <= (k) <= (n) * (m));
    ensures \result == true <==> (k % 2 == n % 2 && k % 3 == m % 3);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    unsigned int k_mod_2;
    unsigned int k_mod_3;
    unsigned int n_mod_2;
    unsigned int m_mod_3;
    bool result;

    //@ assert (1 <= (n) <= 1000 &&         1 <= (m) <= 1000 &&         0 <= (k) <= (n) * (m));

    k_mod_2 = k;
    /*@
        loop invariant 0 <= k_mod_2 <= k;
        loop invariant k_mod_2 <= n * m;
        loop invariant k_mod_2 % 2 == k % 2;
        loop assigns k_mod_2;
        loop variant k_mod_2;
    */
    while (k_mod_2 >= 2)
    {
        //@ assert k_mod_2 % 2 == k % 2;
        k_mod_2 -= 2;
    }
    n_mod_2 = n % 2;

    k_mod_3 = k;
    /*@
        loop invariant 0 <= k_mod_3 <= k;
        loop invariant k_mod_3 <= n * m;
        loop invariant k_mod_3 % 3 == k % 3;
        loop assigns k_mod_3;
        loop variant k_mod_3;
    */
    while (k_mod_3 >= 3)
    {
        //@ assert k_mod_3 % 3 == k % 3;
        k_mod_3 -= 3;
    }
    m_mod_3 = m % 3;

    //@ assert k_mod_2 == n_mod_2 && k_mod_3 == m_mod_3 <==> k % 2 == n % 2 && k % 3 == m % 3;
    result = (k_mod_2 == n_mod_2 && k_mod_3 == m_mod_3);
    return result;
}
