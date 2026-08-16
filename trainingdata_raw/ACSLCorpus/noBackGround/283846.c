#include <stdbool.h>

/*@
    requires 1 <= X <= 9;
    ensures \result == (X == 7 || X == 5 || X == 3);
    assigns \nothing;
 */
bool func(unsigned long X)
{
    //@ assert 1 <= X <= 9;
    bool result;
    switch (X)
    {
        case 7:
        case 5:
        case 3:
            //@ assert X == 7 || X == 5 || X == 3;
            result = true;
            break;
        default:
            //@ assert X != 7 && X != 5 && X != 3;
            result = false;
            break;
    }
    return result;
}

/*@
    requires 1 <= X <= 9;
    ensures \result == (X == 7 || X == 5 || X == 3);
    assigns \nothing;
 */
bool func2(unsigned long X)
{
    //@ assert 1 <= X <= 9;
    bool result;
    if (X == 7 || X == 5 || X == 3)
    {
        //@ assert X == 7 || X == 5 || X == 3;
        result = true;
    }
    else
    {
        //@ assert X != 7 && X != 5 && X != 3;
        result = false;
    }
    return result;
}

/*@
    requires 1 <= X <= 9;
    ensures \result == (X == 7 || X == 5 || X == 3);
    assigns \nothing;
 */
bool func3(unsigned long X)
{
    //@ assert 1 <= X <= 9;
    if (X == 7 || X == 5 || X == 3)
    {
        //@ assert X == 7 || X == 5 || X == 3;
        return true;
    }
    else
    {
        //@ assert X != 7 && X != 5 && X != 3;
        return false;
    }
}
