#include <stdbool.h>

/*@
    predicate is_in_array(integer val, integer a, integer b, integer c, integer d, integer e) =
        val == a || val == b || val == c || val == d || val == e;

    logic integer array_element(integer idx, integer a, integer b, integer c, integer d, integer e) =
        idx == 0 ? a :
        idx == 1 ? b :
        idx == 2 ? c :
        idx == 3 ? d :
        idx == 4 ? e : 0;

    lemma element_exists_in_range:
        \forall integer i, a, b, c, d, e;
        0 <= i < 5 ==> is_in_array(array_element(i, a, b, c, d, e), a, b, c, d, e);
*/

/*@
    requires \valid(input + (0..4));
    requires -100 <= input[0] <= 100;
    requires -100 <= input[1] <= 100;
    requires -100 <= input[2] <= 100;
    requires -100 <= input[3] <= 100;
    requires -100 <= input[4] <= 100;
    requires input[0] <= input[2];
    requires input[2] <= input[4];
    ensures is_in_array(\result, input[0], input[1], input[2], input[3], input[4]);
*/
long func(const long input[5])
{
    long min_val;
    int i;
    
    min_val = input[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= 5;
        loop invariant \exists integer j; 0 <= j < i && min_val == array_element(j, input[0], input[1], input[2], input[3], input[4]);
        loop assigns i, min_val;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        long x;
        
        x = input[i];
        
        //@ assert x == array_element(i, input[0], input[1], input[2], input[3], input[4]);
        
        if (x < min_val)
        {
            min_val = x;
        }
        
        //@ assert \exists integer j; 0 <= j < i+1 && min_val == array_element(j, input[0], input[1], input[2], input[3], input[4]);
        
        i += 1;
    }
    
    //@ assert is_in_array(min_val, input[0], input[1], input[2], input[3], input[4]);
    
    return min_val;
}
