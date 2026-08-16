#include <stdint.h>

/*@
    predicate valid_input(integer x) = 1 <= x <= 100000;

    logic integer q1(integer x) = x / 100;
    logic integer r1(integer x) = x - q1(x) * 100;
    logic integer q2(integer x) = r1(x) / 10;
    logic integer r2(integer x) = r1(x) - q2(x) * 10;
    logic integer expected_result(integer x) = 
        1000 * q1(x) + 100 * q2(x) + r2(x);

    lemma q1_definition: \forall integer x; q1(x) == x / 100;
    lemma r1_definition: \forall integer x; r1(x) == x - q1(x) * 100;
    lemma q2_definition: \forall integer x; q2(x) == r1(x) / 10;
    lemma r2_definition: \forall integer x; r2(x) == r1(x) - q2(x) * 10;
    lemma result_definition: \forall integer x; expected_result(x) == 
        1000 * (x / 100) + 100 * ((x - (x / 100) * 100) / 10) + 
        (x - (x / 100) * 100 - ((x - (x / 100) * 100) / 10) * 10);
*/

/*@
    requires valid_input(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t q1;
    uint32_t r1;
    uint32_t q2;
    uint32_t r2;
    uint32_t ans;

    //@ assert valid_input(x);
    
    q1 = x / 100;
    //@ assert q1 == x / 100;
    
    r1 = x - q1 * 100;
    //@ assert r1 == x - q1 * 100;
    
    q2 = r1 / 10;
    //@ assert q2 == r1 / 10;
    
    r2 = r1 - q2 * 10;
    //@ assert r2 == r1 - q2 * 10;
    
    ans = 1000 * q1 + 100 * q2 + r2;
    //@ assert ans == 1000 * (x / 100) + 100 * ((x - (x / 100) * 100) / 10) + (x - (x / 100) * 100 - ((x - (x / 100) * 100) / 10) * 10);
    
    return ans;
}
