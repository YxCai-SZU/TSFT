#include <stdint.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == ((a) == 1 ? 6 - (b) :
        (a) == 2 ? 1 - (b) :
        6 - 1 - (b));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;

    if (a == 1)
    {
        //@ assert a == 1 && b != 1;
        result = 6 - (int32_t)b;
        //@ assert result == ((a) == 1 ? 6 - (b) :         (a) == 2 ? 1 - (b) :         6 - 1 - (b));
        return result;
    }
    else if (a == 2)
    {
        //@ assert a == 2 && b != 2;
        result = 1 - (int32_t)b;
        //@ assert result == ((a) == 1 ? 6 - (b) :         (a) == 2 ? 1 - (b) :         6 - 1 - (b));
        return result;
    }
    else
    {
        //@ assert a == 3 && b != 3;
        result = 6 - 1 - (int32_t)b;
        //@ assert result == ((a) == 1 ? 6 - (b) :         (a) == 2 ? 1 - (b) :         6 - 1 - (b));
        return result;
    }
}
