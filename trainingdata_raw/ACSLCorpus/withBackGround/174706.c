/*@
predicate non_decreasing_sequence(integer x, integer y, integer z) =
    x <= y && y <= z ==> x <= z;

predicate non_increasing_sequence(integer a, integer b, integer c) =
    a >= b && b >= c ==> a >= c;

predicate positive_sequence(integer d, integer e, integer f) =
    0 <= d && d <= e && e <= f ==> 0 <= f;

predicate sequence_bounds(integer x, integer y) =
    0 <= x && x <= y && y <= 10 ==> 0 <= y && y <= 10;

predicate property_propagates(integer a, integer b, integer c) =
    0 <= a && a <= b && b <= 10 && b <= c && c <= 20 ==>
    0 <= b && b <= 10 && b <= c && c <= 20;

lemma non_decreasing_lemma: \forall integer x, y, z;
    non_decreasing_sequence(x, y, z);

lemma non_increasing_lemma: \forall integer a, b, c;
    non_increasing_sequence(a, b, c);

lemma positive_sequence_lemma: \forall integer d, e, f;
    positive_sequence(d, e, f);

lemma sequence_bounds_lemma: \forall integer x, y;
    sequence_bounds(x, y);

lemma property_propagates_lemma: \forall integer a, b, c;
    property_propagates(a, b, c);
*/

/*@
requires 0 <= a && a <= b && b <= 10 && b <= c && c <= 20;
ensures 0 <= b && b <= 10 && b <= c && c <= 20;
*/
void property_propagates_function(int a, int b, int c) {
    //@ assert non_decreasing_sequence(a, b, c);
    //@ assert sequence_bounds(a, b);
    //@ assert 0 <= b;
}

int main() {
    return 0;
}
