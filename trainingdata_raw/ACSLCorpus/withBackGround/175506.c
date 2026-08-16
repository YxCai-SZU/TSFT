/*@
    predicate monotonic_condition(integer i, integer j) =
        1 <= i && i <= 100 && j <= 100 && i <= j;

    lemma test_monotonic:
        \forall integer i, j;
            monotonic_condition(i, j) ==>
            (i * (i + 1)) / 2 <= (j * (j + 1)) / 2;
*/

/*@
    requires monotonic_condition(i, j);
    ensures \result == 0;
    assigns \nothing;
*/
int test_monotonic(int i, int j) {
    //@ assert monotonic_condition(i, j);
    
    if (j == i) {
        // Base case: trivial equality
    } else {
        // Induction step: recursive call with j-1
        //@ assert monotonic_condition(i, j-1);
        test_monotonic(i, j - 1);
    }
    
    // Final verification of the monotonic property
    //@ assert (i * (i + 1)) / 2 <= (j * (j + 1)) / 2;
    
    return 0;
}

int main() {
    return 0;
}
