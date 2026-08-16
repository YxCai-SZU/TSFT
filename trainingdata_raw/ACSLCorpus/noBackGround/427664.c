#include <stdbool.h>

/*@
  requires -1000000000 <= A <= 1000000000;
  requires -1000000000 <= B <= 1000000000;
  requires -1000000000 <= C <= 1000000000;
  requires -1000000000 <= D <= 1000000000;
  requires A <= B;
  requires C <= D;
  ensures \result == true <==> ((A) <= (D) && (C) <= (B));
*/
bool func(long long A, long long B, long long C, long long D)
{
    bool result;
    //@ assert A <= B && C <= D;
    
    if (A <= D && C <= B)
    {
        //@ assert ((A) <= (D) && (C) <= (B));
        result = true;
    }
    else
    {
        //@ assert !((A) <= (D) && (C) <= (B));
        result = false;
    }
    
    return result;
}
