#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;

    logic integer compute_n(integer x) = x / 100;
    logic integer compute_remained(integer x) = x % 100;
    logic integer compute_a(integer x) = compute_remained(x) / 5;
    logic integer compute_b(integer x) = compute_remained(x) % 5;
    logic integer compute_ans(integer x) = compute_n(x) + compute_a(x) + compute_b(x);

    lemma ans_range: \forall integer x; is_valid_x(x) ==> 0 <= compute_ans(x);
    lemma ans_relation: \forall integer x; is_valid_x(x) ==> compute_ans(x) <= x;
*/

/*@
    requires is_valid_x(x);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint64_t x) {
    uint64_t n;
    uint64_t remained;
    uint64_t a;
    uint64_t b;
    uint64_t ans;
    uint64_t is_candy;

    //@ assert is_valid_x(x);
    
    n = x / 100;
    remained = x % 100;
    a = remained / 5;
    b = remained % 5;
    ans = n + a + b;
    
    //@ assert ans == compute_ans(x);
    
    is_candy = ans;
    
    /*@
        loop invariant 0 <= is_candy <= ans;
        loop assigns is_candy;
    */
    while (is_candy >= 2) {
        //@ assert is_candy >= 2;
        is_candy -= 2;
    }
    
    //@ assert is_candy == 0 || is_candy == 1;
    
    if (is_candy == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    return 0;
}
