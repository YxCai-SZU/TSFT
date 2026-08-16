#include <stdbool.h>

/*@
  requires (1 <= (N) && (N) <= 10000) && (0 <= (A) && (A) <= 1000);
  ensures \result == (N % 500 <= A);
  assigns \nothing;
*/
bool func(unsigned int N, unsigned int A)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert N % 500 <= A ==> N % 500 <= A;
    
    result = (N % 500 <= A);
    return result;
}
