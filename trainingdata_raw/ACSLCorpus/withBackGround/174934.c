#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer rgb_value(integer r, integer g, integer b) = 
        r * 100 + g * 10 + b;

    lemma remainder_preserved:
        \forall integer abs_rgb, remainder;
        0 <= remainder <= abs_rgb && remainder % 4 == abs_rgb % 4 ==>
        (remainder >= 4 ==> (remainder - 4) % 4 == abs_rgb % 4);
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (rgb_value(r, g, b) % 4 == 0);
*/
int func(int r, int g, int b) {
    int rgb;
    int is_divisible;
    int abs_rgb;
    int remainder;

    rgb = r * 100 + g * 10 + b;
    is_divisible = 0;
    abs_rgb = rgb;

    //@ assert rgb == rgb_value(r, g, b);

    if (rgb < 0) {
        abs_rgb = -rgb;
    }

    //@ assert 0 <= abs_rgb;

    remainder = abs_rgb;

    /*@
        loop invariant 0 <= remainder <= abs_rgb;
        loop invariant remainder % 4 == abs_rgb % 4;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 4) {
        remainder -= 4;
    }

    if (remainder == 0) {
        is_divisible = 1;
    }

    //@ assert is_divisible == (abs_rgb % 4 == 0);
    //@ assert abs_rgb % 4 == rgb % 4;

    return is_divisible;
}
