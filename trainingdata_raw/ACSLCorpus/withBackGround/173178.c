#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 != 0;
    
    logic integer func_logic(integer n) = (n % 2 == 0) ? 1 : 0;
    
    lemma even_implies_result_one:
        \forall integer n; 1 <= n <= 100 && is_even(n) ==> func_logic(n) == 1;
    
    lemma odd_implies_result_zero:
        \forall integer n; 1 <= n <= 100 && is_odd(n) ==> func_logic(n) == 0;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result >= 0;
    ensures (n % 2 == 0) ==> \result == 1;
    ensures (n % 2 != 0) ==> \result == 0;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0)
    {
        //@ assert n % 2 == 0;
        result = 1;
        //@ assert result >= 0;
    }
    else
    {
        //@ assert n % 2 != 0;
        result = 0;
        //@ assert result >= 0;
    }
    
    //@ assert result >= 0;
    return result;
}

int main()
{
    return 0;
}
