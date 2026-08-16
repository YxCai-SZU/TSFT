#include <stdbool.h>

/*@ predicate is_between(integer a, integer b, integer c) =
      (a <= c && c <= b) || (a >= c && c >= b);
*/

/*@
  requires 0 <= A <= 100;
  requires 0 <= B <= 100;
  requires 0 <= C <= 100;
  requires A != B && B != C && A != C;
  ensures \result == ( (A <= C && C <= B) || (A >= C && C >= B) );
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    
    //@ assert A != B && B != C && A != C;
    
    if ((A <= C && C <= B) || (A >= C && C >= B))
    {
        result = true;
        //@ assert is_between(A, B, C);
    }
    else
    {
        //@ assert !is_between(A, B, C);
        result = false;
    }
    
    return result;
}
