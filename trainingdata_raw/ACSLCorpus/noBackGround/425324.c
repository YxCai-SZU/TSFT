#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures \result == ((((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert (1 <= (a) && (a) <= 9 &&         1 <= (b) && (b) <= 9 &&         1 <= (c) && (c) <= 9);

    if (a == b && a == c) {
        result = false;
        //@ assert result == false;
    } else if (a == b && a != c) {
        result = true;
        //@ assert result == true;
    } else if (a == c && a != b) {
        result = true;
        //@ assert result == true;
    } else if (b == c && a != b) {
        result = true;
        //@ assert result == true;
    } else {
        //@ assert a != b && a != c && b != c;
        result = false;
        //@ assert result == false;
    }

    return result;
}
