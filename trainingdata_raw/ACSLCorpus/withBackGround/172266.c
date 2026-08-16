/*@
predicate is_even(integer i) = \true;
predicate f(integer i) = \true;

lemma lemma_even_f: \forall integer i; is_even(i) ==> f(i);
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert \true;
    return 0;
}
