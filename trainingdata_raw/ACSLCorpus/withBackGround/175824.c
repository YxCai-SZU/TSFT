#include <stdint.h>

/*@
    predicate in_range(integer a, integer b) =
        1 <= a && a <= b && b <= 100;

    logic integer compute_a(integer i) = i * 8 / 100;
    logic integer compute_b(integer i) = i * 10 / 100;

    lemma division_property:
        \forall integer i; compute_a(i) == i * 8 / 100 && compute_b(i) == i * 10 / 100;
*/

/*@
    requires in_range(a, b);
    ensures \result == -1 || (\result >= 0 && \result < 1000000);
    ensures \result == -1 || 
            (\result * 8 / 100 == a && \result * 10 / 100 == b);
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= 1000000;
        loop invariant \forall integer j; 0 <= j < i ==>
            compute_a(j) != a || compute_b(j) != b;
        loop assigns i;
    */
    while (i < 1000000)
    {
        //@ assert i * 8 / 100 == compute_a(i);
        
        if (i * 8 / 100 == a && i * 10 / 100 == b)
        {
            //@ assert compute_a(i) == a && compute_b(i) == b;
            return (int32_t)i;
        }
        
        i++;
    }
    
    //@ assert \forall integer j; 0 <= j < 1000000 ==> compute_a(j) != a || compute_b(j) != b;
    return -1;
}
