#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer a_tens(integer a) = (a * 10) / 100;
    logic integer b_tens(integer b) = b / 10;

    lemma tens_lemma:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            a_tens(a) == (a * 10) / 100 &&
            b_tens(b) == b / 10;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == (a_tens(a) < b_tens(b));
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int a_tens;
    unsigned int b_tens;
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    a_tens = (a * 10) / 100;
    b_tens = b / 10;
    
    //@ assert a_tens == a_tens(a);
    //@ assert b_tens == b_tens(b);
    
    result = a_tens < b_tens;
    
    //@ assert result == (a_tens(a) < b_tens(b));
    return result;
}
