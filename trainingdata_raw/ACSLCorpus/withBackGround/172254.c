#include <limits.h>

/*@
    predicate input_in_range(integer i) = 1 <= i && i <= 100;
    
    logic integer square(integer i) = i * i;
    
    lemma square_bounds: \forall integer i; input_in_range(i) ==> square(i) <= 10000;
    
    lemma final_result: \forall integer i, integer r; 
        input_in_range(i) && r == 3 * square(i) ==> r == i * i * 3;
*/

/*@
    requires 1 <= input && input <= 100;
    ensures \result == input * input * 3;
    assigns \nothing;
*/
int func(int input)
{
    int result;
    int temp_result;
    int count;
    
    //@ assert input_in_range(input);
    
    //@ assert square(input) <= 10000;
    result = input * input;
    
    //@ assert result == square(input);
    
    temp_result = 0;
    count = 0;
    
    /*@
        loop invariant 0 <= count && count <= result;
        loop invariant temp_result == 3 * count;
        loop invariant result == square(input);
        loop assigns temp_result, count;
        loop variant result - count;
    */
    while (count < result)
    {
        temp_result += 3;
        count += 1;
    }
    
    result = temp_result;
    
    //@ assert result == 3 * square(input);
    
    return result;
}
