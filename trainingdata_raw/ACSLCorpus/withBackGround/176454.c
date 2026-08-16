#include <stdbool.h>

/*@
    predicate is_sum_30(integer x, integer y) = x + y == 30;
    
    logic integer sum(integer x, integer y) = x + y;
    
    lemma sum_is_30: \forall integer x, y; x == 10 && y == 20 ==> sum(x, y) == 30;
*/

/*@
    requires x == 10 && y == 20;
    ensures \result == 30;
    assigns \nothing;
*/
int multi_capture_closure(int x, int y)
{
    //@ assert x == 10 && y == 20;
    int result = x + y;
    //@ assert result == 30;
    return result;
}

/*@
    requires result == 30;
    ensures result == 30;
*/
void prove_result_is_30(int result)
{
    //@ assert result == 30;
}

/*@
    requires x == 10 && y == 20;
    ensures x + y == 30;
*/
void prove_sum_is_30(int x, int y)
{
    //@ assert x + y == 30;
}

int main()
{
    int x = 10;
    int y = 20;
    int result = multi_capture_closure(x, y);
    //@ assert result == 30;
    prove_result_is_30(result);
    prove_sum_is_30(x, y);
    return 0;
}
