/*@
predicate is_less_than(integer a, integer b) = a < b;
predicate is_less_or_equal(integer a, integer b) = a <= b;
predicate is_greater_than(integer a, integer b) = a > b;
predicate is_greater_or_equal(integer a, integer b) = a >= b;

lemma calc_example_3: \forall integer a, b, c; is_less_than(a, b) && is_less_than(b, c) ==> is_less_or_equal(a, c);
lemma is_sorted: \forall integer a, b, c; is_less_than(a, b) && is_less_than(b, c) ==> is_less_or_equal(a, c);
lemma weakly_increasing: \forall integer a, b, c; is_less_or_equal(a, b) && is_less_or_equal(b, c) ==> is_less_or_equal(a, c);
lemma weakly_decreasing: \forall integer a, b, c; is_greater_or_equal(a, b) && is_greater_or_equal(b, c) ==> is_greater_or_equal(a, c);
lemma monotonic: \forall integer a, b, c; (is_less_or_equal(a, b) && is_less_or_equal(b, c)) || (is_greater_or_equal(a, b) && is_greater_or_equal(b, c)) ==> (is_less_or_equal(a, c) || is_greater_or_equal(a, c));
lemma monotonic_decreasing: \forall integer a, b, c; is_greater_or_equal(a, b) && is_greater_or_equal(b, c) ==> is_greater_or_equal(a, c);
lemma monotonic_increasing: \forall integer a, b, c; is_less_or_equal(a, b) && is_less_or_equal(b, c) ==> is_less_or_equal(a, c);
lemma non_decreasing: \forall integer a, b, c; is_less_or_equal(a, b) && is_less_or_equal(b, c) ==> is_less_or_equal(a, c);
lemma non_increasing: \forall integer a, b, c; is_greater_or_equal(a, b) && is_greater_or_equal(b, c) ==> is_greater_or_equal(a, c);
lemma non_decreasing_or_equal: \forall integer a, b, c; is_less_or_equal(a, b) && is_less_or_equal(b, c) ==> is_less_or_equal(a, c);
lemma non_increasing_or_equal: \forall integer a, b, c; is_greater_or_equal(a, b) && is_greater_or_equal(b, c) ==> is_greater_or_equal(a, c);
lemma monotonic_strictly_decreasing: \forall integer a, b, c; is_greater_than(a, b) && is_greater_than(b, c) ==> is_greater_than(a, c);
lemma monotonic_strictly_increasing: \forall integer a, b, c; is_less_than(a, b) && is_less_than(b, c) ==> is_less_than(a, c);
*/

/*@
requires a < b && b < c;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_3_impl(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a < b && b < c;
ensures \result == 0;
assigns \nothing;
*/
int is_sorted_impl(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int weakly_increasing_impl(int a, int b, int c) {
    //@ assert a <= b && b <= c;
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a >= b && b >= c;
ensures \result == 0;
assigns \nothing;
*/
int weakly_decreasing_impl(int a, int b, int c) {
    //@ assert a >= b && b >= c;
    //@ assert a >= b && b >= c;
    //@ assert a >= c;
    return 0;
}

/*@
requires (a <= b && b <= c) || (a >= b && b >= c);
ensures \result == 0;
assigns \nothing;
*/
int monotonic_impl(int a, int b, int c) {
    if (a <= b && b <= c) {
        //@ assert a <= c;
    } else {
        //@ assert a >= c;
    }
    return 0;
}

/*@
requires a >= b && b >= c;
ensures \result == 0;
assigns \nothing;
*/
int monotonic_decreasing_impl(int a, int b, int c) {
    //@ assert a >= b && b >= c;
    //@ assert a >= b && b >= c;
    //@ assert a >= c;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int monotonic_increasing_impl(int a, int b, int c) {
    //@ assert a <= b && b <= c;
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int non_decreasing_impl(int a, int b, int c) {
    //@ assert a <= b && b <= c;
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a >= b && b >= c;
ensures \result == 0;
assigns \nothing;
*/
int non_increasing_impl(int a, int b, int c) {
    //@ assert a >= b && b >= c;
    //@ assert a >= b && b >= c;
    //@ assert a >= c;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int non_decreasing_or_equal_impl(int a, int b, int c) {
    //@ assert a <= b && b <= c;
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a >= b && b >= c;
ensures \result == 0;
assigns \nothing;
*/
int non_increasing_or_equal_impl(int a, int b, int c) {
    //@ assert a >= b && b >= c;
    //@ assert a >= b && b >= c;
    //@ assert a >= c;
    return 0;
}

/*@
requires a > b && b > c;
ensures \result == 0;
assigns \nothing;
*/
int monotonic_strictly_decreasing_impl(int a, int b, int c) {
    //@ assert a > b && b > c;
    //@ assert a > b && b > c;
    //@ assert a > c;
    return 0;
}

/*@
requires a < b && b < c;
ensures \result == 0;
assigns \nothing;
*/
int monotonic_strictly_increasing_impl(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a < b && b < c;
    //@ assert a < c;
    return 0;
}

int main() {
    return 0;
}
