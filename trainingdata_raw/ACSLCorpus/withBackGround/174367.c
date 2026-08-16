#include <stdbool.h>

/*@
    predicate is_valid_range(integer a) = 1000 <= a && a <= 9999;
    
    logic integer extract_hundreds(integer a) = (a / 100) % 10;
    logic integer extract_units(integer a) = a % 10;
    
    lemma extract_consistency:
        \forall integer a; is_valid_range(a) ==> 
            extract_hundreds(a) == (a / 100) % 10 &&
            extract_units(a) == a % 10;
*/

/*@
    requires is_valid_range(a);
    ensures \result == (extract_hundreds(a) == extract_units(a));
    assigns \nothing;
*/
bool func(unsigned int a)
{
    unsigned int c;
    unsigned int d;
    bool result;
    
    //@ assert is_valid_range(a);
    
    c = (a / 100) % 10;
    d = a % 10;
    
    //@ assert c == extract_hundreds(a);
    //@ assert d == extract_units(a);
    
    result = (c == d);
    
    //@ assert result == (extract_hundreds(a) == extract_units(a));
    
    return result;
}
