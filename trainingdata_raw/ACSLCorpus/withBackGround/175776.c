#include <stdbool.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;
    
    logic integer opposite(integer x) = 1 - x;
    
    lemma opposite_property:
        \forall integer x; is_valid_input(x) ==> 
            (x == 0 ==> opposite(x) == 1) && 
            (x == 1 ==> opposite(x) == 0);
*/

/*@
    requires is_valid_input(x);
    ensures (x == 0 ==> \result == 1);
    ensures (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

int main()
{
    return 0;
}
