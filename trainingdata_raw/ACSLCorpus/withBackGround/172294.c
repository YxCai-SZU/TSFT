#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 400 <= x && x <= 1999;
    
    logic integer division_result(integer x) = 8 - (x - 400) / 200;
*/

/*@
    requires is_valid_range(x);
    ensures \result == division_result(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int quotient;
    int temp_result;
    
    result = x - 400;
    quotient = 0;
    temp_result = result;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_result;
        loop invariant temp_result == result - 200 * quotient;
        loop assigns temp_result, quotient;
        loop variant temp_result;
    */
    while (temp_result >= 200)
    {
        temp_result -= 200;
        quotient += 1;
    }
    
    result = 8 - quotient;
    return result;
}

int main(void)
{
    return 0;
}
