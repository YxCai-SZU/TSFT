#include <stdint.h>

/*@
    requires ((l) > 0 && (w) > 0 && (h) > 0 &&
        (l) <= UINT32_MAX / (w) &&
        (l) * (w) <= UINT32_MAX / (h));
    ensures \result == l * w * h;
    assigns \nothing;
*/
uint32_t volume_rect_prism(uint32_t l, uint32_t w, uint32_t h)
{
    //@ assert l * w <= UINT32_MAX / h;
    //@ assert l * w * h <= UINT32_MAX;
    return l * w * h;
}

int main()
{
    return 0;
}
