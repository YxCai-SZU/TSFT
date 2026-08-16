#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_correct(integer a, integer b, integer res) = 
        res == (a + b + 1) / 2;
    
    logic integer func_spec(integer a, integer b) = (a + b + 1) / 2;
    
    lemma bound_lemma_1:
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> 1 <= a + 1 <= 101;
    
    lemma bound_lemma_2:
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> 1 <= b + 1 <= 101;
    
    lemma bound_lemma_3:
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> (a + 1 + b + 1) <= 202;
    
    lemma bound_lemma_4:
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> (a + b + 1) <= 201;
    
    lemma bound_lemma_5:
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> (a + b + 1) / 2 <= 100;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a + b + 1) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert 1 <= a + 1 <= 101;
    //@ assert 1 <= b + 1 <= 101;
    //@ assert (a + 1 + b + 1) <= 202;
    //@ assert (a + b + 1) <= 201;
    //@ assert (a + b + 1) / 2 <= 100;
    
    result = (a + b + 1) / 2;
    
    //@ assert result == (a + b + 1) / 2;
    return result;
}

int main()
{
    return 0;
}
