#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    unsigned int rgb;
    unsigned int temp_rgb;

    //@ assert r * 100 <= 900;
    rgb = r * 100 + g * 10 + b;

    temp_rgb = rgb;
    /*@
        loop invariant 0 <= temp_rgb <= rgb;
        loop invariant temp_rgb % 4 == rgb % 4;
        loop assigns temp_rgb;
    */
    while (temp_rgb >= 4)
    {
        temp_rgb -= 4;
    }

    return temp_rgb == 0;
}
