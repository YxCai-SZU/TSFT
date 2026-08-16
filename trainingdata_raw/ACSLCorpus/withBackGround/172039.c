/*@
predicate is_positive(integer x) = x > 0;

lemma test_exists_positive:
    \forall integer i; (\exists integer j; is_positive(j) && j == i) ==> is_positive(i);

lemma test_exists_positive_finite:
    \forall integer i; (\exists integer j; is_positive(j) && j == i) ==> is_positive(i);

lemma lemma_is_positive_is_monotonic:
    \forall integer i; is_positive(i - 1) ==> (is_positive(i) || i == 0);
*/

/*@
requires \exists integer j; is_positive(j) && j == i;
ensures is_positive(i);
*/
void test_exists_positive_concrete(int i) {
    //@ assert is_positive(i);
}

/*@
requires \exists integer j; is_positive(j) && j == i;
ensures is_positive(i);
*/
void test_exists_positive_finite_concrete(int i) {
    //@ assert is_positive(i);
}

/*@
requires is_positive(i - 1);
ensures is_positive(i) || i == 0;
*/
void lemma_is_positive_is_monotonic_concrete(int i) {
    if (i == 0) {
        //@ assert i == 0;
    } else {
        //@ assert is_positive(i);
    }
}

int main() {
    return 0;
}
