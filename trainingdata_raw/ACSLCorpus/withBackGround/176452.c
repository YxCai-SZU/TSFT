#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 1000000000;
    
    logic integer target_result(integer a) = a / 2 + a % 2;
    
    lemma result_correctness:
        \forall integer a; is_valid_a(a) ==> target_result(a) == a / 2 + a % 2;
*/

/*@
    requires is_valid_a(a);
    ensures \result == target_result(a);
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    uint64_t ans = 0;
    uint64_t two = 2;
    uint64_t temp_a = a;
    
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant ans >= 0;
        loop invariant temp_a + two * ans == a;
        loop assigns temp_a, ans;
        loop variant temp_a;
    */
    while (temp_a >= two)
    {
        //@ assert temp_a >= 2;
        temp_a -= two;
        ans += 1;
        //@ assert temp_a + two * ans == a;
    }
    
    if (temp_a == 1)
    {
        ans += 1;
    }
    
    //@ assert ans == a / 2 + a % 2;
    return ans;
}

int main()
{
    return 0;
}
