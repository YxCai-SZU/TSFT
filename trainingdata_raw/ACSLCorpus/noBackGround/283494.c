#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * (3));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t res;

    pi = 3;
    //@ assert pi == 3;
    res = r * 2 * pi;
    return res;
}

int main()
{
    return 0;
}
