#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000);
    ensures \result == true <==> (((a) < (c) && (b) > (c)) ? 1 : (((a) > (c) && (b) < (c)) ? 1 : 0)) == 1;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Declare all variables at the top
    bool result;

    if (a < c && b > c) {
        //@ assert a < c && b > c;
        result = true;
    } else if (a > c && b < c) {
        //@ assert a > c && b < c;
        result = true;
    } else {
        //@ assert !(a < c && b > c) && !(a > c && b < c);
        result = false;
    }

    return result;
}
