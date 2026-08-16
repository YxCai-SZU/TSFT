/*@
    predicate positive_and_bounded(integer x, integer y) =
        x > 0 && y > 0 && x <= 10 && y <= 10;

    lemma proof_example_2: \forall integer x, y; positive_and_bounded(x, y) ==> x + y <= 20;
*/

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    int x;
    int y;
    
    //@ ghost int x_val = 5;
    //@ ghost int y_val = 5;
    
    //@ assert positive_and_bounded(x_val, y_val);
    //@ assert x_val + y_val <= 20;
    
    return 0;
}
