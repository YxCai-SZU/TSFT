/*@
    predicate is_in_set(integer i, integer lower, integer upper, integer mode) =
        (mode == 0) ? (i > lower) :
        (mode == 1) ? (i >= lower) :
        (mode == 2) ? (i > lower && i < upper) :
        (mode == 3) ? (i >= lower && i <= upper) :
        (mode == 4) ? (i > lower || i < upper) :
        (i >= lower && i <= upper);
*/

/*@
    lemma two_equal_set:
        \forall integer i; is_in_set(i, 0, 0, 0) ==> is_in_set(i, 0, 0, 0);
*/

/*@
    lemma two_equal_set2:
        \forall integer i; is_in_set(i, 1, 0, 1) ==> is_in_set(i, 1, 0, 1);
*/

/*@
    lemma two_equal_set3:
        \forall integer i; is_in_set(i, 0, 10, 2) ==> is_in_set(i, 0, 10, 2);
*/

/*@
    lemma two_equal_set4:
        \forall integer i; is_in_set(i, 0, 10, 3) ==> is_in_set(i, 0, 10, 3);
*/

/*@
    lemma two_equal_set5:
        \forall integer i; is_in_set(i, 0, 10, 4) ==> is_in_set(i, 0, 10, 4);
*/

/*@
    lemma two_equal_set6:
        \forall integer i; is_in_set(i, 1, 10, 5) ==> is_in_set(i, 1, 10, 5);
*/

int main() {
    return 0;
}
