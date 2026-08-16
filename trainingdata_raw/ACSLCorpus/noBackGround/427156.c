#include <stdint.h>
#include <stdbool.h>

/*@
    requires (0 <= (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t is_triangular(uint32_t n)
{
    //@ assert (0 <= (n) <= 65535);
    //@ assert ((n) * ((n) + 1) / 2) == n * (n + 1) / 2;
    return n * (n + 1) / 2;
}

/*@
    requires (0 <= (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular(uint32_t n)
{
    uint32_t ret;
    ret = is_triangular(n);
    //@ assert ret == ((n) * ((n) + 1) / 2);
    return ret;
}

#ifdef TEST
#include <assert.h>
int main()
{
    uint32_t n = 10;
    uint32_t result = find_triangular(n);
    assert(result == 55);
    return 0;
}
#endif
