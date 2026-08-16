#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a <= 10;
    
    logic integer func_spec(integer a) = a + a * a + a * a * a;
    
    lemma func_bound: \forall integer a; is_valid_a(a) ==> func_spec(a) <= 1331;
*/

/*@
    requires is_valid_a(a);
    ensures \result == func_spec(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert 1 <= a;
    //@ assert a <= 10;
    
    //@ assert a + a * a + a * a * a <= 1331;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == func_spec(a);
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    // Variable declarations at scope top
    uint32_t result1;
    uint32_t result2;
    uint32_t result3;
    
    result1 = func(1);
    //@ assert result1 == 1;
    assert(result1 == 1);
    
    result2 = func(3);
    //@ assert result2 == 39;
    assert(result2 == 39);
    
    result3 = func(10);
    //@ assert result3 == 1331;
    assert(result3 == 1331);
    
    return 0;
}
#endif
