#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == true <==> (a == b && b == c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    //@ assert a * b <= 81;
    //@ assert ((a) * (b) * (c)) <= 729;

    if (a == b && b == c)
    {
        result = true;
    }
    else
    {
        //@ assert a != b || b != c;
        result = false;
    }

    return result;
}
