#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 0 <= a <= 100;
    predicate p_in_range(integer p) = 0 <= p <= 100;
    predicate pies_non_negative(integer pies) = pies >= 0;
    predicate pies_bound(integer pies, integer a, integer p) = pies <= a * 3 + p;
*/

/*@
    logic integer total_pieces(integer a, integer p) = a * 3 + p;
*/

/*@
    lemma pieces_relation:
        \forall integer a, p, temp_a, apple_pies;
        a_in_range(a) && p_in_range(p) && temp_a >= 0 && apple_pies >= 0 &&
        temp_a + 2 * apple_pies == total_pieces(a, p) ==>
        apple_pies <= total_pieces(a, p) / 2;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result >= 0;
    ensures \result <= a * 3 + p;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t apple_pies;
    uint32_t temp_a;
    
    apple_pies = 0;
    temp_a = a * 3 + p;
    
    /*@
        loop invariant 0 <= a <= 100;
        loop invariant 0 <= p <= 100;
        loop invariant temp_a >= 0;
        loop invariant apple_pies >= 0;
        loop invariant temp_a + 2 * apple_pies == a * 3 + p;
        loop invariant apple_pies <= (a * 3 + p) / 2;
        loop assigns temp_a, apple_pies;
        loop variant temp_a;
    */
    while (temp_a >= 2)
    {
        //@ assert temp_a >= 2;
        temp_a -= 2;
        apple_pies += 1;
        //@ assert temp_a + 2 * apple_pies == a * 3 + p;
    }
    
    //@ assert apple_pies >= 0;
    //@ assert apple_pies <= a * 3 + p;
    return apple_pies;
}

int main(void)
{
    return 0;
}
