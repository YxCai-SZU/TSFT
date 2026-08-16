#include <stdbool.h>

/*@
    predicate is_divisible_by_2(integer x) = x % 2 == 0;
    predicate is_divisible_by_5(integer x) = x % 5 == 0;
*/

/*@
    requires 1 <= input && input <= 1000000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (input % 2 == 0 || input % 5 == 0);
    ensures \result == 0 ==> (input % 2 != 0 && input % 5 != 0);
*/
int func(long input)
{
    int result;
    bool is_divisible_by_2;
    bool is_divisible_by_5;
    long temp_input;
    
    result = 0;
    is_divisible_by_2 = false;
    is_divisible_by_5 = false;
    
    // Check divisibility by 2
    temp_input = input;
    /*@
        loop invariant 1 <= input && input <= 1000000000;
        loop invariant 0 <= temp_input && temp_input <= input;
        loop invariant temp_input % 2 == input % 2;
        loop assigns temp_input;
    */
    while (temp_input >= 2)
    {
        temp_input -= 2;
    }
    
    if (temp_input == 0)
    {
        is_divisible_by_2 = true;
    }
    
    // Check divisibility by 5
    temp_input = input;
    /*@
        loop invariant 1 <= input && input <= 1000000000;
        loop invariant 0 <= temp_input && temp_input <= input;
        loop invariant temp_input % 5 == input % 5;
        loop assigns temp_input;
    */
    while (temp_input >= 5)
    {
        temp_input -= 5;
    }
    
    if (temp_input == 0)
    {
        is_divisible_by_5 = true;
    }
    
    if (is_divisible_by_2 || is_divisible_by_5)
    {
        result = 1;
    }
    
    //@ assert result == 1 ==> (is_divisible_by_2 || is_divisible_by_5);
    return result;
}
