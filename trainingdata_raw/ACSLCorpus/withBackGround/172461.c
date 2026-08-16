/*@
predicate is_positive(integer value) = value > 0;
predicate is_less_than_ten(integer value) = value < 10;
predicate is_greater_than_ten(integer value) = value > 10;

lemma multi_step_tri:
    \forall integer i; is_greater_than_ten(i) ==> \true;

lemma nested_sum:
    \forall integer k; is_positive(k) && is_less_than_ten(k) ==> \true;
*/

/*@
requires \true;
ensures \true;
*/
void main() {
    // Variable declarations
    int dummy = 0;
    
    //@ assert dummy == 0;
}
