/*@
    predicate is_less_than_five(integer x) = x < 5;
    predicate is_less_equal_six(integer x) = x <= 6;

    lemma proof_a: \forall integer x; is_less_than_five(x) ==> x + 1 <= 6;
    lemma proof_b: \forall integer x; is_less_than_five(x) ==> x + 1 <= 6;
    lemma proof_c: \forall integer x; is_less_than_five(x) ==> x + 1 <= 6;
*/

/*@
    assigns \nothing;
*/
int main() {
    int x;
    
    //@ assert is_less_than_five(3);
    //@ assert 3 + 1 <= 6;
    
    return 0;
}
