/*@
    predicate is_even(integer n) = n % 2 == 0;
    logic integer abs(integer x) = x < 0 ? -x : x;
    logic integer min(integer x, integer y) = x <= y ? x : y;
    logic integer max(integer x, integer y) = x >= y ? x : y;
    
    lemma calc_abs: \forall integer x; x < 0 ==> abs(x) == -x;
    lemma lemma_abs_nonneg: \forall integer x; x < 0 ==> abs(x) >= 0;
    lemma lemma_min_is_min: \forall integer x, y; x <= y ==> min(x, y) <= x && min(x, y) <= y;
    lemma lemma_max_is_max: \forall integer x, y; x <= y ==> max(x, y) >= x && max(x, y) >= y;
    lemma lemma_max_nooverflow: \forall integer x, y; x <= y ==> max(x, y) <= y;
*/

int main() {
    return 0;
}
