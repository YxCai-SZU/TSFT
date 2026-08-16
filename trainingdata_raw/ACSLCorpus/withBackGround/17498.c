#include <stdint.h>

/*@ predicate func_spec(integer a) = 1 <= a && a <= 10; */

/*@ logic integer func_value(integer a) = a + (a * a) + (a * a * a); */

/*@ lemma func_bounds: \forall integer a; func_spec(a) ==> func_value(a) <= 1110; */

/*@ requires func_spec(a);
    ensures \result == func_value(a);
    assigns \nothing;
 */
uint32_t func(uint32_t a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert a + (a * a) + (a * a * a) <= 1110;
    return a + (a * a) + (a * a * a);
}

/*@ requires func_spec(a);
    ensures \result == func_value(a);
    assigns \nothing;
 */
uint32_t func_vec(uint32_t a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert a + (a * a) + (a * a * a) <= 1110;
    return a + (a * a) + (a * a * a);
}

int main()
{
    return 0;
}
