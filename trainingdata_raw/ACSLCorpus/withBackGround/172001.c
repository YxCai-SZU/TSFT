#include <stdbool.h>

/*@
    predicate sum_ge(integer a, integer b, integer c) = a + b >= c;
*/

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= c <= 1000000000;
    ensures \result == true <==> sum_ge(a, b, c);
    ensures \result == false <==> !sum_ge(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert 0 <= a <= 1000000000;
    //@ assert 0 <= b <= 1000000000;
    //@ assert 0 <= c <= 1000000000;
    
    if (a + b >= c)
    {
        //@ assert sum_ge(a, b, c);
        result = true;
    }
    else
    {
        //@ assert !sum_ge(a, b, c);
        result = false;
    }
    
    return result;
}
