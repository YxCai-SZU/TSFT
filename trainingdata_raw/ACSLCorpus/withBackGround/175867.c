/*@
    predicate is_even(integer i) = i % 2 == 0;
    predicate is_odd(integer i) = i % 2 != 0;
    predicate f(integer i) = \true;
    
    lemma even_f: \forall integer i; is_even(i) ==> f(i);
    lemma odd_f: \forall integer i; is_odd(i) ==> f(i);
*/

/*@
    requires \true;
    ensures \true;
*/
void main() {
    //@ assert \true;
}
