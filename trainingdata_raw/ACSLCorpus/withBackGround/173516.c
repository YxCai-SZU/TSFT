#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer rgb_value(integer r, integer g, integer b) = r * 100 + g * 10 + b;

    lemma mod_preserved:
        \forall integer rgb, temp;
        0 <= temp <= rgb && temp % 4 == rgb % 4 ==>
        (temp == 0) ==> (rgb % 4 == 0);
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (rgb_value(r, g, b) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b) {
    int rgb;
    int temp_rgb;

    rgb = r * 100 + g * 10 + b;
    temp_rgb = rgb;

    /*@
        loop invariant 0 <= temp_rgb <= rgb;
        loop invariant temp_rgb % 4 == rgb % 4;
        loop assigns temp_rgb;
    */
    while (temp_rgb >= 4) {
        //@ assert temp_rgb % 4 == rgb % 4;
        temp_rgb -= 4;
    }

    //@ assert (temp_rgb == 0) ==> (rgb % 4 == 0);
    return temp_rgb == 0;
}
