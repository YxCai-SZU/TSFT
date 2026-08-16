#include <stdint.h>

/*@
    predicate valid_dimensions(integer l, integer w, integer h) =
        0 <= l <= 1000 &&
        0 <= w <= 1000 &&
        0 <= h <= 1000 &&
        l * w * h <= 1000 * 1000 * 1000;

    logic integer volume(integer l, integer w, integer h) = l * w * h;

    lemma intermediate_bound:
        \forall integer l, w;
        0 <= l <= 1000 && 0 <= w <= 1000 ==> l * w <= 1000 * 1000;

    lemma final_bound:
        \forall integer l, w, h;
        valid_dimensions(l, w, h) ==> l * w * h <= 1000 * 1000 * 1000;
*/

/*@
    requires valid_dimensions(l, w, h);
    ensures \result == volume(l, w, h);
    assigns \nothing;
*/
int32_t cuboid_volume(int32_t l, int32_t w, int32_t h)
{
    // Variable declarations at scope top
    int32_t volume;

    //@ assert 0 <= l <= 1000;
    //@ assert 0 <= w <= 1000;
    //@ assert 0 <= h <= 1000;
    //@ assert l * w <= 1000 * 1000;
    //@ assert l * w * h <= 1000 * 1000 * 1000;

    volume = l * w * h;
    return volume;
}

int main()
{
    return 0;
}
