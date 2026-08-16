/*@
    predicate le_nat(integer a, integer b) = 0 <= a && a <= b;

    lemma proof_example_i:
        \forall integer a, b;
            le_nat(a, b) ==> a * 2 <= b * 2;
*/

/*@
    requires 0 <= a && a <= b;
    ensures \result == 1;
    assigns \nothing;
*/
int example(int a, int b) {
    //@ assert a <= b;
    //@ assert a * 2 <= b * 2;
    return 1;
}

int main() {
    return 0;
}
