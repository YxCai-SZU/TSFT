#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    requires 1 <= D <= 100;
    ensures \result == true <==> (((((A)) - ((C)) > 0) && (((A)) - ((D)) > 0)) ||
        ((((B)) - ((C)) > 0) && (((B)) - ((D)) > 0)));
*/
bool func(int A, int B, int C, int D)
{
    bool result;
    
    //@ assert 1 <= A <= 100 && 1 <= B <= 100 && 1 <= C <= 100 && 1 <= D <= 100;
    
    if (A > C && A > D)
    {
        result = true;
        //@ assert (((((A)) - ((C)) > 0) && (((A)) - ((D)) > 0)) ||         ((((B)) - ((C)) > 0) && (((B)) - ((D)) > 0)));
        return result;
    }
    else if (B > C && B > D)
    {
        result = true;
        //@ assert (((((A)) - ((C)) > 0) && (((A)) - ((D)) > 0)) ||         ((((B)) - ((C)) > 0) && (((B)) - ((D)) > 0)));
        return result;
    }
    else
    {
        result = false;
        //@ assert !(((((A)) - ((C)) > 0) && (((A)) - ((D)) > 0)) ||         ((((B)) - ((C)) > 0) && (((B)) - ((D)) > 0)));
        return result;
    }
}
