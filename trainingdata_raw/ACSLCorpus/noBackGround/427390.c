#include <stdint.h>

/*@
    requires (1 <= (N) <= 100);
    ensures \result == (3 * (N) * (N));
    assigns \nothing;
*/
int32_t func(int32_t N)
{
    //@ assert (1 <= (N) <= 100);
    //@ assert 3 * N * N <= 30000;
    return 3 * N * N;
}

int main(void)
{
    return 0;
}
