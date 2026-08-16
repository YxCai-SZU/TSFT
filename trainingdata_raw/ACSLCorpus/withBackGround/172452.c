/*@
    predicate has_factor(integer n) =
        \exists integer f; 1 < f && f < n && (n % f) == 0;

    predicate has_square_factor(integer n) =
        \exists integer f; 1 < f && f < n && (n % f) == 0 && f * f <= n;

    lemma square_factor_implies_factor:
        \forall integer n; has_square_factor(n) ==> has_factor(n);
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert \true;
    return 0;
}
