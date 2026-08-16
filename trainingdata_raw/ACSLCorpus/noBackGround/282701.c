#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
    ensures ((\result) == ((s) <= (w)));
*/
bool func(unsigned int s, unsigned int w) {
    unsigned int i;
    unsigned int j;
    bool result;

    i = 0;
    /*@
        loop invariant 0 <= i <= s;
        loop invariant (1 <= (s) <= 100) && (1 <= (w) <= 100);
        loop assigns i;
        loop variant s - i;
    */
    while (i < s) {
        i++;
    }

    j = 0;
    /*@
        loop invariant 0 <= j <= w;
        loop invariant (1 <= (s) <= 100) && (1 <= (w) <= 100);
        loop assigns j;
        loop variant w - j;
    */
    while (j < w) {
        j++;
    }

    //@ assert i == s && j == w;
    result = (s <= w);
    return result;
}
