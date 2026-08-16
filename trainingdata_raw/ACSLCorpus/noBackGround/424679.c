#include <stdbool.h>
/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result == ((b) / (c)) ||
            \result == ((a) / (d)) ||
            \result == ((a) / (c)) ||
            \result == ((b) / (d));
*/
unsigned int func(unsigned int a, unsigned int b,
                  unsigned int c, unsigned int d)
{
    unsigned int x;

    //@ assert ((b) / (c)) <= 100;
    //@ assert ((a) / (d)) <= 100;
    //@ assert ((a) / (c)) <= 100;
    //@ assert ((b) / (d)) <= 100;

    if (a > b) {
        if (b / c > a / d) {
            x = b / c;
        } else {
            x = a / d;
        }
    } else {
        if (a / c > b / d) {
            x = a / c;
        } else {
            x = b / d;
        }
    }

    //@ assert x == ((b) / (c)) || x == ((a) / (d)) || x == ((a) / (c)) || x == ((b) / (d));
    return x;
}
