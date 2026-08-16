/*@
    predicate k_in_range(integer k) = 2 <= k && k <= 100;

    lemma k_half_le_50:
        \forall integer k; k_in_range(k) ==> k / 2 <= 50;

    lemma k_plus1_half_le_50:
        \forall integer k; k_in_range(k) ==> (k + 1) / 2 <= 50;

    lemma k_half_ge_1:
        \forall integer k; k_in_range(k) ==> k / 2 >= 1;

    lemma k_plus1_half_ge_1:
        \forall integer k; k_in_range(k) ==> (k + 1) / 2 >= 1;

    lemma product_le_2500:
        \forall integer k; k_in_range(k) ==> (k / 2) * ((k + 1) / 2) <= 2500;

    lemma product_ge_1:
        \forall integer k; k_in_range(k) ==> (k / 2) * ((k + 1) / 2) >= 1;
*/

/*@
    requires 2 <= k && k <= 100;
    ensures \result == 0;
    ensures (k / 2) * ((k + 1) / 2) <= 2500;
    ensures (k / 2) * ((k + 1) / 2) >= 1;
    ensures k / 2 <= 50;
    ensures (k + 1) / 2 <= 50;
    ensures k / 2 >= 1;
    ensures (k + 1) / 2 >= 1;
*/
int test_all(int k) {
    /*@ assert k / 2 <= 50; */
    /*@ assert (k + 1) / 2 <= 50; */
    /*@ assert k / 2 >= 1; */
    /*@ assert (k + 1) / 2 >= 1; */
    /*@ assert (k / 2) * ((k + 1) / 2) <= 2500; */
    /*@ assert (k / 2) * ((k + 1) / 2) >= 1; */
    return 0;
}

int main() {
    return 0;
}
