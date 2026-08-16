/*@
predicate greater_than_or_equal_implies_greater_than_or_equal(integer a, integer b) =
    a >= b ==> a >= b;

predicate greater_than_or_equal_implies_greater_than_or_equal_neg(integer a, integer b) =
    a >= b ==> a >= b;

predicate greater_than_implies_greater_than_or_equal(integer a, integer b) =
    a > b ==> a >= b;

predicate greater_than_or_equal_implies_greater_than(integer a, integer b) =
    (a >= b && a != b) ==> a > b;

predicate greater_than_or_equal_neg_implies_greater_than_neg(integer a, integer b) =
    (a >= b && a != b) ==> a > b;

lemma greater_than_or_equal_implies_greater_than_or_equal_lemma:
    \forall integer a, b; a >= b ==> a >= b;

lemma greater_than_or_equal_implies_greater_than_or_equal_neg_lemma:
    \forall integer a, b; a >= b ==> a >= b;

lemma greater_than_implies_greater_than_or_equal_lemma:
    \forall integer a, b; a > b ==> a >= b;

lemma greater_than_or_equal_implies_greater_than_lemma:
    \forall integer a, b; (a >= b && a != b) ==> a > b;

lemma greater_than_or_equal_neg_implies_greater_than_neg_lemma:
    \forall integer a, b; (a >= b && a != b) ==> a > b;
*/

int main() {
    //@ assert greater_than_or_equal_implies_greater_than_or_equal(5, 3);
    //@ assert greater_than_or_equal_implies_greater_than_or_equal_neg(5, 3);
    //@ assert greater_than_implies_greater_than_or_equal(5, 3);
    //@ assert greater_than_or_equal_implies_greater_than(5, 3);
    //@ assert greater_than_or_equal_neg_implies_greater_than_neg(5, 3);
    return 0;
}
