/*@
    predicate is_evenly_divisible(integer a, integer b) =
        a >= 0 && b > 0 ==> (a % b == 0);

    predicate is_oddly_divisible(integer a, integer b) =
        a >= 0 && b > 0 ==> (a % b != 0);

    lemma prove_divisibility:
        \forall integer a, b;
            a >= 0 && b > 0 && a % b == 0 ==> a % b == 0;

    lemma prove_odd_divisibility:
        \forall integer a, b;
            a >= 0 && b > 0 && a % b != 0 ==> a % b != 0;
*/

int main() {
    return 0;
}
