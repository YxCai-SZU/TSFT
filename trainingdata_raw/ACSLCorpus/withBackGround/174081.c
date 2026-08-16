/*@
    predicate positive(integer n) = n > 0;
    predicate less_than_three(integer n) = n > 0 && n < 3;

    lemma multiplication_property: \forall integer n; positive(n) ==> n * 2 >= n;
    lemma exponentiation_property: \forall integer n; less_than_three(n) ==> n * n * n <= 8;
*/

int main() {
    return 0;
}
