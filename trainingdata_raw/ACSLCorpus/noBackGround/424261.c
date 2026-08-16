#include <stdbool.h>

/*@
    requires ((-100 <= ((a)) <= 100) && (-100 <= ((b)) <= 100) && (-100 <= ((c)) <= 100) && (a) <= (b));
    ensures ((\result) == ((c) >= (a) && (c) <= (b)));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool left_inclusive;
    bool right_exclusive;
    bool result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    //@ assert a <= b;

    left_inclusive = (c >= a);
    right_exclusive = (c <= b);

    //@ assert left_inclusive == (c >= a);
    //@ assert right_exclusive == (c <= b);

    result = left_inclusive && right_exclusive;
    //@ assert result == (c >= a && c <= b);
    return result;
}
