#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == true <==> (a < b && b < c) || (a > b && b > c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ ghost unsigned int old_a = a, old_b = b, old_c = c;

    if (a < b && b < c)
    {
        //@ assert ((a) < (b) && (b) < (c));
        result = true;
        return result;
    }

    if (a > b && b > c)
    {
        //@ assert ((a) > (b) && (b) > (c));
        result = true;
        return result;
    }

    result = false;
    //@ assert !((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    return result;
}
