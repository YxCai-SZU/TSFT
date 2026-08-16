#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    
    logic integer pow2(integer a) = a * a;
    logic integer pow3(integer a) = a * a * a;
    logic integer total(integer a) = a + pow2(a) + pow3(a);
    
    lemma pow2_bounds: \forall integer a; a_in_range(a) ==> 1 <= pow2(a) <= 100;
    lemma pow3_bounds: \forall integer a; a_in_range(a) ==> 1 <= pow3(a) <= 1000;
    lemma total_correct: \forall integer a; a_in_range(a) ==> total(a) == a + pow2(a) + pow3(a);
*/

/*@
    requires a_in_range(a);
    ensures \result == total(a);
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    int32_t result;
    int32_t a_pow_2;
    int32_t a_pow_3;
    
    //@ assert a_in_range(a);
    
    //@ assert 1 <= a * a <= 100;
    a_pow_2 = a * a;
    
    //@ assert 1 <= a * a * a <= 1000;
    a_pow_3 = a * a * a;
    
    result = a;
    result = result + a_pow_2 + a_pow_3;
    
    //@ assert result == a + a * a + a * a * a;
    return result;
}

int main()
{
    return 0;
}
