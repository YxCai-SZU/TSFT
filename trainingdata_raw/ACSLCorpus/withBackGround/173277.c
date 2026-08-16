/*@
    predicate square_nonneg(integer x) = x * x >= 0;

    lemma square_nonneg_lemma:
        \forall integer x; square_nonneg(x);
*/

/*@
    requires \true;
    ensures \result == 0;
*/
int main() {
    int x;
    
    //@ assert square_nonneg(x);
    
    return 0;
}
