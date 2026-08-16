/*@
    requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    ensures \result <= 10000 * 10000;
*/
int lemma_isolation(int n, int m) {
    //@ assert (1 <= (n) && (n) <= 10000);
    //@ assert (1 <= (m) && (m) <= 10000);
    //@ assert ((n) * (m)) <= 10000 * 10000;
    return n * m;
}

/*@
    requires 1 <= n <= 10000;
    ensures \result <= 10000 * 10000;
*/
int lemma_nonlinear_arith(int n) {
    //@ assert (1 <= (n) && (n) <= 10000);
    //@ assert ((n) * (n)) <= 10000 * 10000;
    return n * n;
}

int main() {
    return 0;
}
