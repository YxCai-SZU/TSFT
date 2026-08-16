/*@
predicate non_decreasing(integer a, integer b, integer c) =
    a <= b && b <= c;

lemma calc_example_4:
    \forall integer m, n; m + n <= m + n + 2;

lemma complex_calc_example:
    \forall integer m, n, p; m + n + p <= m + n + p + 5;
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert 1 + 2 <= 1 + 2 + 2;
    //@ assert 1 + 2 + 3 <= 1 + 2 + 3 + 5;
    return 0;
}
