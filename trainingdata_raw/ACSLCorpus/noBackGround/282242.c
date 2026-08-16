#include <stdbool.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100);
    requires A <= B;
    ensures \result == ((((A) <= (C) && (C) <= (B)) ? 1 : 0) == 1);
*/
bool func(int A, int B, int C)
{
    bool result;

    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (B) <= 100);
    //@ assert (-100 <= (C) <= 100);
    //@ assert A <= B;

    if (A <= C && C <= B)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == ((((A) <= (C) && (C) <= (B)) ? 1 : 0) == 1);
    return result;
}
