/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a && a <= 50 &&
        0 <= b && b <= 50 &&
        0 <= c && c <= 50;

    lemma multiplication_associative:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * b * c == a * (b * c);

    lemma multiplication_bound:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * (b * c) <= 50 * 50 * 50;
*/

#include <stdbool.h>

/*@
    requires 0 <= a && a <= 50;
    requires 0 <= b && b <= 50;
    requires 0 <= c && c <= 50;
    ensures \result == true <==> 
            a * b * c == a * (b * c) && 
            a * (b * c) <= 50 * 50 * 50;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert bounds(a, b, c);
    //@ assert a * b * c == a * (b * c);
    //@ assert a * (b * c) <= 50 * 50 * 50;
    
    result = true;
    return result;
}

int main()
{
    return 0;
}
