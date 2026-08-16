#include <stdbool.h>

/*@
    requires (-1000 <= (s) <= 1000);
    ensures \result == (s >= 0);
    assigns \nothing;
*/
bool func(long s)
{
    //@ assert -1000 <= s <= 1000;
    return s >= 0;
}

/*@
    requires (-1000 <= (s) <= 1000);
    ensures \result == (s >= 0);
    assigns \nothing;
*/
bool func2(long s)
{
    //@ assert -1000 <= s <= 1000;
    return s >= 0;
}

/*@
    requires (-1000 <= (s) <= 1000);
    ensures \result == (s >= 0);
    assigns \nothing;
*/
bool func3(long s)
{
    //@ assert -1000 <= s <= 1000;
    return s >= 0;
}

/*@
    requires (-1000 <= (s) <= 1000);
    ensures \result == (s >= 0);
    assigns \nothing;
*/
bool func4(long s)
{
    //@ assert -1000 <= s <= 1000;
    return s >= 0;
}

/*@
    requires (-1000 <= (s) <= 1000);
    ensures \result == (s >= 0);
    assigns \nothing;
*/
bool func5(long s)
{
    //@ assert -1000 <= s <= 1000;
    return s >= 0;
}

/*@
    requires (-1000 <= (s) <= 1000);
    ensures \result == (s >= 0);
    assigns \nothing;
*/
bool func6(long s)
{
    //@ assert -1000 <= s <= 1000;
    return s >= 0;
}
