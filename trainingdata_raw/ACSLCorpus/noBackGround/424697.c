#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures ((\result) == true <==> ((x) >= 2000 && (x) <= 200000) || ((x) % 2000 == 0));
    assigns \nothing;
*/
bool func(unsigned int x) {
    bool result;
    unsigned int remainder;

    if (x < 2000) {
        remainder = x;
        /*@
            loop invariant 0 <= remainder <= x;
            loop invariant remainder == ((x) - 2000 * (((x) - (remainder)) / 2000));
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= 2000) {
            //@ assert remainder >= 2000;
            remainder -= 2000;
        }
        result = (remainder == 0);
    } else if (x <= 200000) {
        result = true;
    } else {
        remainder = x;
        /*@
            loop invariant 0 <= remainder <= x;
            loop invariant remainder == ((x) - 2000 * (((x) - (remainder)) / 2000));
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= 2000) {
            //@ assert remainder >= 2000;
            remainder -= 2000;
        }
        result = (remainder == 0);
    }

    //@ assert ((result) == true <==> ((x) >= 2000 && (x) <= 200000) || ((x) % 2000 == 0));
    return result;
}

