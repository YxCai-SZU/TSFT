#include <stddef.h>


size_t func(size_t n, size_t k)
{
    size_t ans;

    //@ assert k - 1 >= 1;
    //@ assert k - 1 <= 99999;
    //@ assert n - 1 >= 1;
    //@ assert n - 1 <= 99999;
    //@ assert n - 1 + (k - 1 - 1) >= k - 1;
    //@ assert n - 1 + (k - 1 - 1) <= 199998;

    ans = (n - 1 + (k - 1 - 1)) / (k - 1);

    return ans;
}
