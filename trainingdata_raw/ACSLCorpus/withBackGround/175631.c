#include <stdint.h>

/*@
    predicate condition_holds(integer a, integer b) =
        a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0;

    predicate condition_fails(integer a, integer b) =
        a % 3 != 0 && b % 3 != 0 && (a + b) % 3 != 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures condition_holds(a, b) ==> \result == 1;
    ensures condition_holds(a, b) ==> \result != 0;
    ensures condition_fails(a, b) ==> \result == 0;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    result = 0;

    if (a % 3 == 0 || b % 3 == 0)
    {
        result = 1;
    }
    else if ((a + b) % 3 == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    if ((a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) && result != 1)
    {
        //@ assert condition_holds(a, b);
        return 1;
    }
    else if ((a % 3 != 0 && b % 3 != 0 && (a + b) % 3 != 0) && result != 0)
    {
        //@ assert condition_fails(a, b);
        return 0;
    }
    else
    {
        //@ assert condition_holds(a, b) ==> result == 1;
        //@ assert condition_fails(a, b) ==> result == 0;
        //@ assert result == 1 || result == 0;
        return result;
    }
}
