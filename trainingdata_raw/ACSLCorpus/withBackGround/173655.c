/*@
predicate less_than(integer a, integer b) = a < b;

lemma transitive_less: \forall integer a, b, c; a < b && b < c ==> a < c;
lemma total_less_or_equal: \forall integer a, b, c; a < b && b < c ==> a < c;
lemma non_reflexive_less: \forall integer a; a >= 0 ==> a >= a;
lemma antisymmetric_greater: \forall integer a, b; a > b ==> a != b;
*/

int main() {
    //@ assert \true;
    return 0;
}
