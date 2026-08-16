/*@
    predicate non_negative(integer x) = x >= 0;

    lemma triple_incr: \forall integer num; non_negative(num) ==> num + num + num == 3 * num;
    lemma multiple_decr: \forall integer a, b; non_negative(a) && non_negative(b) && a >= b ==> a - b == a - b;
    lemma multiple_decr_steps: \forall integer a, b; non_negative(a) && non_negative(b) && a >= b ==> a - b == a - b;
*/

int main() {
    //@ assert \true;
    return 0;
}
