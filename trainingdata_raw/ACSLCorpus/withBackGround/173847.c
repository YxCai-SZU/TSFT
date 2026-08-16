/*@
    predicate is_in_range(integer r) = 0 <= r && r <= 100;

    logic integer func(integer r) = r * r;

    lemma func_monotonic:
        \forall integer r, r2;
            is_in_range(r) && is_in_range(r2) && r <= r2 ==>
            func(r) <= func(r2);
*/

int main() {
    return 0;
}
