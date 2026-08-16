#include <stdint.h>

/*@
    requires (0 <= (l) <= 128 && 0 <= (w) <= 128 && 0 <= (h) <= 128);
    ensures \result == ((l) * (w) * (h));
    assigns \nothing;
*/
int32_t cubed_volume(int32_t l, int32_t w, int32_t h)
{
    //@ assert (0 <= (l) <= 128 && 0 <= (w) <= 128 && 0 <= (h) <= 128);
    //@ assert 0 <= l * w <= 128 * 128;
    //@ assert 0 <= l * w * h <= 128 * 128 * 128;
    return l * w * h;
}

int main()
{
    return 0;
}
