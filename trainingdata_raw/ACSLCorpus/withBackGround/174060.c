#include <stdbool.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x <= 100;
    predicate result_condition(integer x, bool r) = r == (x >= 30);
*/

/*@
    requires is_valid_input(input);
    ensures result_condition(input, \result);
*/
bool func(int input)
{
    int x;
    bool result;
    
    x = input;
    
    if (x < 30) {
        result = false;
    } else {
        //@ assert x >= 30;
        result = true;
    }
    
    return result;
}
