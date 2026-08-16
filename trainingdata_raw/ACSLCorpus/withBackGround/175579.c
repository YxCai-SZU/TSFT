/*@
    predicate is_less_than_20(integer x) = x < 20;
    predicate is_less_than_30(integer x) = x < 30;
    
    lemma addition_chain_correctness: 
        \forall integer x; is_less_than_20(x) ==> x + 10 < 30;
*/

/*@
    requires x < 20;
    ensures \result < 30;
    assigns \nothing;
*/
int addition_chain_correctness(int x) {
    //@ assert x < 20;
    
    int result = x + 10;
    
    //@ assert result < 30;
    return result;
}

int main() {
    return 0;
}
