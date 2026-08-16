/*@
    requires 0 <= m;
    requires \valid(s+(0..m));
    requires (\forall integer k; 0 <= k < (m) ==> (s)[k] <= (s)[k+1]);
    ensures (\forall integer k; 0 <= k < (m) ==> (s)[k] <= (s)[k+1]);
*/
void lemma_monotonic_increasing(int *s, int m) {
    //@ assert (\forall integer k; 0 <= k < (m) ==> (s)[k] <= (s)[k+1]);
}

/*@
    requires a <= b;
    requires b <= c;
    ensures a <= c;
*/
void calc_example_s(int a, int b, int c) {
    //@ assert a <= c;
}

/*@
    requires 0 <= m;
    requires \valid(s+(0..m));
    requires (\forall integer k; 0 <= k < (m) ==> (s)[k] >= (s)[k+1]);
    ensures (\forall integer k; 0 <= k < (m) ==> (s)[k] >= (s)[k+1]);
*/
void lemma_monotonic_decreasing(int *s, int m) {
    //@ assert (\forall integer k; 0 <= k < (m) ==> (s)[k] >= (s)[k+1]);
}

int main() {
    return 0;
}
