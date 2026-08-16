/*@
predicate is_positive(integer n) = n > 0;
predicate is_less_than_two(integer n) = n < 2;

lemma inequality_lemma:
    \forall integer n; n < n + 1;

lemma inequality_positive_lemma:
    \forall integer n; n > 0 ==> 0 < n;

lemma sum_inequality_lemma:
    \forall integer a, b; a > 0 && b > 0 ==> a + b < a + 2 * b;

lemma product_inequality_lemma:
    \forall integer n; n > 0 && n < 2 ==> n < n * 3;
*/

/*@
requires n > 0;
ensures n < n + 2;
*/
void calc_example_6(int n) {
    //@ assert n < n + 1;
    //@ assert n + 1 < n + 2;
}

/*@
requires n > 0;
ensures 0 < n + 2;
*/
void calc_example_7(int n) {
    //@ assert 0 < n;
    //@ assert n < n + 2;
}

/*@
requires a > 0 && b > 0;
ensures a + b < a + 2 * b;
*/
void calc_example_8(int a, int b) {
    //@ assert a + b < a + 2 * b;
}

/*@
requires n > 0 && n < 2;
ensures n < n * 3;
*/
void calc_example_9(int n) {
    //@ assert n < n * 3;
}

int main() {
    return 0;
}
