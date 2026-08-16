#include <stdbool.h>

/*@
    predicate condition_holds(integer n, integer a) =
        n % 500 <= a;
*/

/*@
    requires 1 <= n && n <= 1000000;
    requires 0 <= a && a <= 1000000;
    ensures \result == true <==> (n % 500 <= a);
*/
bool func(unsigned int n, unsigned int a)
{
    bool result;
    
    //@ assert n % 500 == n % 500;
    
    if (n % 500 <= a) {
        //@ assert condition_holds(n, a);
        result = true;
    } else {
        //@ assert !condition_holds(n, a);
        result = false;
    }
    
    //@ assert result == true <==> condition_holds(n, a);
    return result;
}
