#include <stdbool.h>

/*@
    predicate is_valid_int(int x) = x >= -2147483648 && x <= 2147483647;
*/

/*@
    requires is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    if (a < b)
    {
        //@ assert a < b;
        if (b < c)
        {
            //@ assert a < b && b < c;
            return true;
        }
        else
        {
            //@ assert !(a < b && b < c);
            return false;
        }
    }
    else
    {
        //@ assert !(a < b && b < c);
        return false;
    }
}

/*@
    requires is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func1(int a, int b, int c)
{
    bool answer = false;
    //@ assert is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    if (a < b)
    {
        //@ assert a < b;
        if (b < c)
        {
            //@ assert a < b && b < c;
            answer = true;
        }
    }
    //@ assert answer == (a < b && b < c);
    return answer;
}

/*@
    requires is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func2(int a, int b, int c)
{
    bool answer = false;
    //@ assert is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    if (a < b)
    {
        //@ assert a < b;
        if (b < c)
        {
            //@ assert a < b && b < c;
            answer = true;
        }
    }
    //@ assert answer == (a < b && b < c);
    return answer;
}
