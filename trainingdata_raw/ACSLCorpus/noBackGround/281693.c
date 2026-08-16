#include <stdbool.h>

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == true <==> (a < b && b < c) || (a > b && b > c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert a > 0 && b > 0 && c > 0;

    if (a < b && b < c)
    {
        //@ assert ((a) < (b) && (b) < (c));
        result = true;
    }
    else if (a > b && b > c)
    {
        //@ assert ((a) > (b) && (b) > (c));
        result = true;
    }
    else
    {
        //@ assert !((a) < (b) && (b) < (c)) && !((a) > (b) && (b) > (c));
        result = false;
    }

    //@ assert ((result) == true <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c)))));
    return result;
}
