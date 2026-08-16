#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000 &&
        1 <= (m) && (m) <= 1000 &&
        0 <= (k) && (k) <= (n) * (m));
    ensures ((\result) == true <==> (((((n))) * (((m)))) - ((k))) % 2 == 0);
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    unsigned int n_i;
    unsigned int m_i;
    unsigned int k_i;
    unsigned int total;
    unsigned int remainder_val;
    bool is_even;
    unsigned int temp;

    n_i = (unsigned int)n;
    m_i = (unsigned int)m;
    k_i = (unsigned int)k;

    //@ assert n_i >= 1 && n_i <= 1000;
    //@ assert m_i >= 1 && m_i <= 1000;
    //@ assert k_i >= 0 && k_i <= n_i * m_i;

    //@ assert n_i * m_i <= 1000000;
    total = n_i * m_i;
    remainder_val = total - k_i;

    is_even = true;
    temp = remainder_val;

    /*@
        loop invariant temp <= remainder_val;
        loop invariant temp % 2 == remainder_val % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp % 2 == remainder_val % 2;
        temp -= 2;
    }

    if (temp != 0)
    {
        is_even = false;
    }

    //@ assert is_even == (remainder_val % 2 == 0);
    return is_even;
}
