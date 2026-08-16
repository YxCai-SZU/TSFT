#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == (((C) - (((B)) - ((A)))) > 0);
*/
bool func(long A, long B, long C)
{
    long diff;
    long result;

    //@ assert (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    diff = B - A;
    //@ assert diff == ((B) - (A));
    result = C - diff;
    //@ assert result == ((C) - (((B)) - ((A))));

    if (result > 0)
    {
        //@ assert ((C) - (((B)) - ((A)))) > 0;
        return true;
    }
    else
    {
        //@ assert ((C) - (((B)) - ((A)))) <= 0;
        return false;
    }
}
