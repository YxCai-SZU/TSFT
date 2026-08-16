/*@
    requires m == n;
    requires n < p;
    ensures \result == 0;
    ensures m <= p;
*/
int calc_example_3(int m, int n, int p) {
    //@ assert m <= p;
    return 0;
}

/*@
    requires A < B;
    requires B < C;
    ensures \result == 0;
    ensures A < C;
*/
int prove_strictly_monotonic(int A, int B, int C) {
    //@ assert A < C;
    return 0;
}

/*@
    requires A <= B;
    requires B <= C;
    ensures \result == 0;
    ensures A <= C;
*/
int prove_monotonic(int A, int B, int C) {
    //@ assert A <= C;
    return 0;
}

/*@
    requires A < B;
    requires B < C;
    requires C < D;
    ensures \result == 0;
    ensures A < D;
*/
int prove_strictly_monotonic_triple(int A, int B, int C, int D) {
    //@ assert A < D;
    return 0;
}

/*@
    requires A <= B;
    requires B <= C;
    requires C <= D;
    ensures \result == 0;
    ensures A <= D;
*/
int prove_monotonic_triple(int A, int B, int C, int D) {
    //@ assert A <= D;
    return 0;
}

int main() {
    return 0;
}
