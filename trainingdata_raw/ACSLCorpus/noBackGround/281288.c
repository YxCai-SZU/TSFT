#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool result;

    sum = a + b + c;

    if (sum == 2 * a || sum == 2 * b || sum == 2 * c)
    {
        //@ assert sum == 2 * a || sum == 2 * b || sum == 2 * c;
        if (a + b == c || a + c == b || b + c == a)
        {
            result = true;
        }
        else
        {
            result = false;
        }
        return result;
    }

    //@ assert !(a + b == c || a + c == b || b + c == a);
    result = false;
    return result;
}
