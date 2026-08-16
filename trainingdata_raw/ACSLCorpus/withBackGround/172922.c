#include <stdbool.h>

/*@
    predicate is_valid_index(integer i) = 0 <= i < 5;
    
    predicate element_matches(int *x, integer i) = 
        x[i] == i + 1 || x[i] == 0;
    
    predicate all_elements_match(int *x) = 
        \forall integer i; 0 <= i < 5 ==> element_matches(x, i);
    
    predicate zero_exists(int *x) = 
        \exists integer i; 0 <= i < 5 && x[i] == 0;
    
    predicate no_zero_before(int *x, integer idx) = 
        \forall integer j; 0 <= j < idx ==> x[j] != 0;
    
    predicate zero_exists_from(int *x, integer idx) = 
        \exists integer j; idx <= j < 5 && x[j] == 0;
*/

/*@
    requires \valid(x + (0..4));
    requires all_elements_match(x);
    requires zero_exists(x);
    ensures \result > 0 && \result < 6;
    ensures x[\result - 1] == 0;
*/
int func(int *x)
{
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant all_elements_match(x);
        loop invariant no_zero_before(x, i);
        loop invariant zero_exists_from(x, i);
        loop assigns i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        
        if (x[i] == 0)
        {
            //@ assert x[i] == 0;
            return i + 1;
        }
        
        //@ assert x[i] != 0;
        i = i + 1;
    }
    
    return -1;
}
