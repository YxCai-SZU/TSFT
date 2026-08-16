#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a != b;
    ensures \result == ((c > a && c < b) || (c > b && c < a));
*/
bool func(int a, int b, int c)
{
    bool c_greater_than_a;
    bool c_less_than_b;
    bool c_greater_than_b;
    bool c_less_than_a;
    bool result;

    c_greater_than_a = c > a;
    c_less_than_b = c < b;
    c_greater_than_b = c > b;
    c_less_than_a = c < a;

    if (c_greater_than_a && c_less_than_b)
    {
        result = true;
        //@ assert result == true;
        return result;
    }
    else if (c_greater_than_b && c_less_than_a)
    {
        result = true;
        //@ assert result == true;
        return result;
    }
    else
    {
        //@ assert !(c_greater_than_a && c_less_than_b) && !(c_greater_than_b && c_less_than_a);
        result = false;
        //@ assert result == false;
        return result;
    }
}
