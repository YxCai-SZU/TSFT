/*@
    predicate valid_params(integer a, integer b) =
        a >= 1 && a <= 10 && b >= 1 && b <= 10;

    logic integer func(integer a, integer b) =
        a <= 1 ? a : a + func(a - 1, b);

    lemma func_is_monotonic:
        \forall integer a, b;
            valid_params(a, b) ==> func(a, b) >= a;
*/

int main() {
    //@ assert valid_params(5, 5) ==> func(5, 5) >= 5;
    return 0;
}
