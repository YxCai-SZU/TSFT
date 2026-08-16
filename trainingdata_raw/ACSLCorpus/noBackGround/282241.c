#include <stdint.h>
/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t res;
    //@ assert (1 <= (k) <= (n) <= 50);
    res = n - k + 1;
    //@ assert res == ((n) - (k) + 1);
    return res;
}

/*@
    assigns \nothing;
    ensures \result == 0;
*/
int64_t read_vec(void)
{
    return 0;
}

int main(void)
{
    return 0;
}
