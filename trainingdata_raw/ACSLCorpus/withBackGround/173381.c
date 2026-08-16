/*@
predicate positive(integer n) = n > 0;

lemma inequality: \forall integer n; n < n + 1;
lemma increasing_sequence: \forall integer n; positive(n) ==> n < n + 1 < n + 2 < n + 3;
lemma decreasing_sequence: \forall integer n; positive(n) ==> n > n - 1 > n - 2 > n - 3;
*/

/*@
requires n > 0;
ensures n < n + 2;
*/
void calc_example_6(int n) {
    //@ assert n > 0;
    //@ assert n < n + 2;
}

/*@
requires n > 0;
ensures n < n + 1 < n + 2 < n + 3;
*/
void calc_example_7(int n) {
    //@ assert n > 0;
    //@ assert n < n + 1 < n + 2 < n + 3;
}

/*@
requires n > 0;
ensures n > n - 1 > n - 2 > n - 3;
*/
void calc_example_8(int n) {
    //@ assert n > 0;
    //@ assert n > n - 1 > n - 2 > n - 3;
}

int main() {
    return 0;
}
