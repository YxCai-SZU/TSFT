#include <stdint.h>

/*@ predicate is_in_range(integer a) = 1 <= a && a <= 10; */

/*@ lemma a_squared_bound: \forall integer a; is_in_range(a) ==> a * a <= 100; */
/*@ lemma a_cubed_bound: \forall integer a; is_in_range(a) ==> a * a * a <= 1000; */

/*@
    requires is_in_range(a);
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a_squared;
    uint32_t a_cubed;
    uint32_t result;

    //@ assert is_in_range(a);
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;

    a_squared = a * a;
    //@ assert a_squared <= 100;

    a_cubed = a * a * a;
    //@ assert a_cubed <= 1000;

    result = a + a_squared + a_cubed;
    return result;
}

int main()
{
    return 0;
}
