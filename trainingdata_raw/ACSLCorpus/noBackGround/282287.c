#include <stdbool.h>
#include <stdint.h>

/*@
    requires a <= 0xFFFFFFFF && b <= 0xFFFFFFFF;
    requires c <= 0xFFFFFFFF && d <= 0xFFFFFFFF;
    ensures \result == ((a & c) == (b & d));
    assigns \nothing;
 */
bool func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert a <= 0xFFFFFFFF && b <= 0xFFFFFFFF && c <= 0xFFFFFFFF && d <= 0xFFFFFFFF;
    bool result = (a & c) == (b & d);
    //@ assert result == ((a & c) == (b & d));
    return result;
}

int main()
{
    return 0;
}
