#include <stdbool.h>

/*@
    predicate is_between(integer a, integer b, integer c) =
        (a <= c && c <= b) || (b <= c && c <= a);
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == true <==> is_between(a, b, c);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    if (a <= c && c <= b) {
        //@ assert is_between(a, b, c);
        return true;
    }
    if (b <= c && c <= a) {
        //@ assert is_between(a, b, c);
        return true;
    }
    
    //@ assert !is_between(a, b, c);
    return false;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == true <==> is_between(a, b, c);
*/
bool func2(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;
    
    result = (a <= c && c <= b) || (b <= c && c <= a);
    //@ assert result == true <==> is_between(a, b, c);
    return result;
}
