#include <stdbool.h>

/*@ predicate condition_holds(integer a, integer b, integer c) =
      (a <= c && c <= a + b) || (c <= a + b && a + b <= c);
*/

/*@
  requires 1 <= a && a <= 100;
  requires 1 <= b && b <= 100;
  requires 1 <= c && c <= 100;
  ensures \result == true <==> condition_holds(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result = false;
    int sum = a + b;
    
    //@ assert sum == a + b;
    
    if (a <= c && c <= sum) {
        result = true;
    } else if (c <= sum && sum <= c) {
        result = true;
    }
    
    //@ assert result == true <==> condition_holds(a, b, c);
    
    return result;
}
