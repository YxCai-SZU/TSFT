#include <stdbool.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
    logic integer func_result(integer x) = (x == 0) ? 1 : 0;
*/

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert 0 <= x <= 1;
    
    if (x == 0) {
        //@ assert x == 0;
        result = 1;
    } else {
        //@ assert x == 1;
        result = 0;
    }
    
    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);
    return result;
}

/*@
    lemma func_correct: 
        \forall integer x; 0 <= x <= 1 ==> func_result(x) == ((x == 0) ? 1 : 0);
*/

int main()
{
    return 0;
}
