#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        c <= b + 1 || d <= a + 1;
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (c <= b + 1 || d <= a + 1);
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;
    
    if (c <= b + 1 || d <= a + 1) {
        result = true;
        //@ assert result == true;
        //@ assert condition_holds(a, b, c, d);
    } else {
        //@ assert c > b + 1 && d > a + 1;
        result = false;
        //@ assert result == false;
        //@ assert !condition_holds(a, b, c, d);
    }
    
    return result;
}
