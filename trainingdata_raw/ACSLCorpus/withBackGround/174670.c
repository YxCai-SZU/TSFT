#include <stdint.h>

/*@
    predicate valid_range(integer X) =
        0 <= X && X <= 1000000000;
*/

/*@
    logic integer compute_result(integer X) =
        (X / 500) * 1000 + (X % 500 / 5) * 5;
*/

/*@
    lemma division_property:
        \forall integer X;
        valid_range(X) ==>
        X - (X / 500) * 500 - (X % 500 / 5) * 5 >= 0;
*/

/*@
    requires valid_range(X);
    ensures \result == compute_result(X);
    assigns \nothing;
*/
int64_t func(int64_t X)
{
    int64_t result;
    int64_t temp;
    int64_t count_500;
    int64_t count_5;
    
    result = 0;
    temp = X;
    count_500 = 0;
    
    /*@
        loop invariant 0 <= temp <= X;
        loop invariant 0 <= count_500 <= X/500;
        loop invariant temp == X - count_500 * 500;
        loop assigns temp, count_500;
    */
    while (temp >= 500)
    {
        //@ assert temp >= 500;
        temp -= 500;
        count_500 += 1;
    }
    
    count_5 = 0;
    
    /*@
        loop invariant 0 <= temp <= X;
        loop invariant 0 <= count_5 <= X/5;
        loop invariant temp == X - count_500 * 500 - count_5 * 5;
        loop assigns temp, count_5;
    */
    while (temp >= 5)
    {
        //@ assert temp >= 5;
        temp -= 5;
        count_5 += 1;
    }
    
    result = count_500 * 1000 + count_5 * 5;
    //@ assert result == compute_result(X);
    return result;
}
