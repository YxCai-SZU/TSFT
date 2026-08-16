#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a && a <= 100 && 0 <= p && p <= 100;

    logic integer calculate_kakera(integer a, integer p) = a * 3 + p;

    logic integer calculate_ans(integer kakera) = kakera / 2;

    lemma ans_bound: \forall integer a, p, kakera, ans;
        valid_range(a, p) ==>
        kakera == calculate_kakera(a, p) ==>
        ans == calculate_ans(kakera) ==>
        ans <= p + a * 3;
*/

/*@
    requires valid_range(a, p);
    ensures \result <= p + a * 3;
*/
uint32_t func(uint32_t a, uint32_t p) {
    uint32_t kakera;
    uint32_t ans;

    kakera = a * 3 + p;
    //@ assert kakera == calculate_kakera(a, p);
    
    ans = kakera / 2;
    //@ assert ans == calculate_ans(kakera);
    
    //@ assert ans <= p + a * 3;
    
    return ans;
}
