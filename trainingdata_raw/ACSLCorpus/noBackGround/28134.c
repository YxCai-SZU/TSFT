#include <stdbool.h>

/*@
  requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100);
  requires A <= B;
  ensures \result == (C >= A && C <= B);
*/
bool func(long A, long B, long C)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert A <= B;
    
    result = (C >= A && C <= B);
    return result;
}
