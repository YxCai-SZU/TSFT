#include <stdbool.h>

/*@
    requires 1 <= A && A <= 100;
    requires 1 <= B && B <= 100;
    requires 1 <= C && C <= 100;
    ensures \result == true <==> (((A) < (C) && (C) < (B)) || ((A) > (C) && (C) > (B)));
*/
bool func(int A, int B, int C)
{
    bool result;
    
    //@ assert 1 <= A && A <= 100;
    //@ assert 1 <= B && B <= 100;
    //@ assert 1 <= C && C <= 100;
    
    if (A < C && C < B)
    {
        //@ assert A < C && C < B;
        result = true;
    }
    else if (A > C && C > B)
    {
        //@ assert A > C && C > B;
        result = true;
    }
    else
    {
        //@ assert !(A < C && C < B) && !(A > C && C > B);
        result = false;
    }
    
    //@ assert result == true <==> (((A) < (C) && (C) < (B)) || ((A) > (C) && (C) > (B)));
    return result;
}
