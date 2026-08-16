#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (k) <= 1000000);
    ensures \result >= -1;
    ensures \result < 1000000000 + 1;
    assigns \nothing;
*/
int32_t func(size_t k)
{
    // Variable declarations at top of scope
    size_t m7;
    size_t i;
    int32_t result;

    //@ assert (1 <= (k) <= 1000000);
    m7 = 7 % k;
    i = 0;

    /*@
        loop invariant (1 <= (k) <= 1000000);
        loop invariant 0 <= m7 < k;
        loop invariant 0 <= i <= k + 1;
        loop assigns m7, i;
        loop variant k + 1 - i;
    */
    while (i < k + 1)
    {
        if (m7 == 0)
        {
            //@ assert i + 1 >= 0;
            //@ assert (int32_t)(i + 1) < 1000000000 + 1;
            return (int32_t)(i + 1);
        }
        //@ assert 0 <= m7 < k;
        m7 = (m7 * 10 + 7) % k;
        i += 1;
    }
    //@ assert -1 >= -1;
    //@ assert -1 < 1000000000 + 1;
    return -1;
}

int main(void)
{
    return 0;
}
