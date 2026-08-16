#include <stdbool.h>

/*@
    requires (1 <= (a) <= 7) && (1 <= (b) <= 7) && (1 <= (c) <= 7) && (1 <= (k) <= 7);
    ensures \result == ((((a) > (b) && (b) > (c)) ||
        ((a) <= (b) && (b) <= (c) && (k) > (a)) ||
        ((a) >= (b) && (b) >= (c) && (k) > (b)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int k)
{
    bool result;

    //@ assert (1 <= (a) <= 7);
    //@ assert (1 <= (b) <= 7);
    //@ assert (1 <= (c) <= 7);
    //@ assert (1 <= (k) <= 7);

    if (a > b && b > c) {
        result = true;
    } else if (a <= b && b <= c && k > a) {
        result = true;
    } else if (a >= b && b >= c && k > b) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == ((((a) > (b) && (b) > (c)) ||         ((a) <= (b) && (b) <= (c) && (k) > (a)) ||         ((a) >= (b) && (b) >= (c) && (k) > (b)) ? 1 : 0) == 1);
    return result;
}
