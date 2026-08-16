/*@
predicate is_positive(integer value) = value > 10;

lemma triangle_lemma:
    \forall integer i; is_positive(i) ==> \true;
*/

/*@
requires i > 10;
ensures \true;
assigns \nothing;
*/
void proof_triangle(int i) {
    //@ assert i > 10;
}
