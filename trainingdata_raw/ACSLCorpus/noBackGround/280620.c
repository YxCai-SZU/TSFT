#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid_read(vec + (0 .. len-1));
    requires 0 <= x && x < len;
    ensures \result == *(vec + x);
    assigns \nothing;
*/
int case_fn(int *vec, size_t len, size_t x)
{
    //@ assert 0 <= x && x < len;
    return vec[x];
}

int main()
{
    return 0;
}
