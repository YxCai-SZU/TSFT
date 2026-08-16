#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100) && (1 <= (D) <= 100);
    ensures \result == true <==> ((A) - (((B)) - (((C)) - ((D))))) > 0;
    assigns \nothing;
*/
bool func(int A, int B, int C, int D)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);
    //@ assert (1 <= (D) <= 100);

    //@ assert ((B) - ((C) - (D))) <= 199;
    //@ assert ((A) - (((B)) - (((C)) - ((D))))) <= 199;

    if (A - (B - (C - D)) > 0)
    {
        //@ assert ((A) - (((B)) - (((C)) - ((D))))) > 0;
        result = true;
    }
    else
    {
        //@ assert !(((A) - (((B)) - (((C)) - ((D))))) > 0);
        result = false;
    }

    return result;
}
