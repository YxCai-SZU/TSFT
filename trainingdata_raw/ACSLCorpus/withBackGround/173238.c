#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 5;

    lemma proof_func: \forall integer x; is_valid_range(x) ==> x + 1 <= 6;
*/

/*@
    requires 1 <= x <= 5;
    ensures \result == x + 1;
    ensures \result <= 6;
*/
int add_one(int x)
{
    int result;

    //@ assert 1 <= x <= 5;
    result = x + 1;
    //@ assert result <= 6;
    
    return result;
}

int main()
{
    return 0;
}
