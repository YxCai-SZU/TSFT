#include <stdbool.h>
#include <stdint.h>

/*@
    requires (0 <= (h1) <= 0x7FFFFFFF) && (0 <= (h2) <= 0x7FFFFFFF);
    ensures \result == (h1 == h2);
    assigns \nothing;
*/
bool func(uint32_t h1, uint32_t h2)
{
    //@ assert (0 <= (h1) <= 0x7FFFFFFF);
    //@ assert (0 <= (h2) <= 0x7FFFFFFF);
    return h1 == h2;
}

int main()
{
    return 0;
}
