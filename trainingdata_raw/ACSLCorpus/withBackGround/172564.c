#include <stdint.h>

/*@ predicate bound_condition(integer x, integer y) = 
      x <= 9 && y <= 9 ==> x * y <= 81; */

/*@ lemma bound_check: 
      \forall integer x, y; 0 <= x <= 9 && 0 <= y <= 9 ==> x * y <= 81; */

/*@ predicate count_up_condition(integer n) = 
      n <= 10 ==> n * 2 + n * 5 <= 125; */

/*@ lemma count_up_check: 
      \forall integer n; 0 <= n <= 10 ==> n * 2 + n * 5 <= 125; */

/*@ assigns \nothing;
    ensures \true; */
void bound_check_impl(uint32_t x, uint32_t y) {
    //@ assert bound_condition(x, y);
}

/*@ assigns \nothing;
    ensures \true; */
void count_up_check_impl(uint32_t n) {
    //@ assert count_up_condition(n);
}
