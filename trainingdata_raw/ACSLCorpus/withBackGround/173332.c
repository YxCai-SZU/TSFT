/*@
    predicate positive(integer v) = v > 0;

    lemma addition_correctness: \forall integer x, y; positive(x) && positive(y) ==> positive(x + y);
*/

/*@
    requires x > 0;
    requires y > 0;
    ensures \result > 0;
    assigns \nothing;
*/
int add_positive(int x, int y) {
    int result;
    //@ assert positive(x);
    //@ assert positive(y);
    result = x + y;
    //@ assert positive(result);
    return result;
}

int main() {
    return 0;
}
