/*@
    predicate a_in_range(integer a) = 1 <= a <= 5;
    predicate b_in_range(integer b) = 1 <= b <= 5;
    predicate sum_in_range(integer a, integer b) = 2 <= a + b <= 10;

    lemma proof_example: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> sum_in_range(a, b);
    lemma verify: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> sum_in_range(a, b);
    lemma additional_verification: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> a_in_range(a) && b_in_range(b) && sum_in_range(a, b);
    lemma case_analysis: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) && (b == 1 || b == 2 || b == 3 || b == 4 || b == 5) && 1 <= a + b <= 10;
    lemma generalProof: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> sum_in_range(a, b) && (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) && (b == 1 || b == 2 || b == 3 || b == 4 || b == 5) && a_in_range(a) && b_in_range(b);
    lemma assertion: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> 1 <= a + b <= 10;
    lemma proof: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> a_in_range(a) && b_in_range(b) && a + b >= 2 && a + b <= 10 && 1 <= a + b <= 10;
    lemma invariant: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> a_in_range(a) && b_in_range(b) && sum_in_range(a, b);
    lemma example: \forall integer a, b; a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10 ==> a_in_range(a) && b_in_range(b) && 1 <= a + b <= 10;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures sum_in_range(a, b);
*/
void proof_example_func(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert sum_in_range(a, b);
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures sum_in_range(a, b);
*/
void verify_func(int a, int b) {
    //@ assert sum_in_range(a, b);
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures a_in_range(a) && b_in_range(b) && sum_in_range(a, b);
*/
void additional_verification_func(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert sum_in_range(a, b);
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) && (b == 1 || b == 2 || b == 3 || b == 4 || b == 5) && 1 <= a + b <= 10;
*/
void case_analysis_func(int a, int b) {
    //@ assert (a == 1 || a == 2 || a == 3 || a == 4 || a == 5);
    //@ assert (b == 1 || b == 2 || b == 3 || b == 4 || b == 5);
    //@ assert 1 <= a + b <= 10;
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures sum_in_range(a, b) && (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) && (b == 1 || b == 2 || b == 3 || b == 4 || b == 5) && a_in_range(a) && b_in_range(b);
*/
void generalProof_func(int a, int b) {
    //@ assert sum_in_range(a, b);
    //@ assert (a == 1 || a == 2 || a == 3 || a == 4 || a == 5);
    //@ assert (b == 1 || b == 2 || b == 3 || b == 4 || b == 5);
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures 1 <= a + b <= 10;
*/
void assertion_func(int a, int b) {
    //@ assert 1 <= a + b <= 10;
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures a_in_range(a) && b_in_range(b) && a + b >= 2 && a + b <= 10 && 1 <= a + b <= 10;
*/
void proof_func(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert a + b >= 2;
    //@ assert a + b <= 10;
    //@ assert 1 <= a + b <= 10;
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures a_in_range(a) && b_in_range(b) && sum_in_range(a, b);
*/
void invariant_func(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert sum_in_range(a, b);
}

/*@
    requires a_in_range(a) && b_in_range(b) && 2 <= a + b <= 10;
    ensures a_in_range(a) && b_in_range(b) && 1 <= a + b <= 10;
*/
void example_func(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert 1 <= a + b <= 10;
}

int main() {
    return 0;
}
