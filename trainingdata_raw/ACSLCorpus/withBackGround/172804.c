/*@
    predicate example_1_pre(integer a, integer b) = a < b;
    predicate example_1_post(integer a, integer b) = a <= b;
    lemma example_1: \forall integer a, b; example_1_pre(a, b) ==> example_1_post(a, b);
*/

/*@
    predicate example_7_pre(integer a, integer b, integer c) = a + b == c;
    predicate example_7_post(integer a, integer b, integer c) = a + b <= c + 1;
    lemma example_7: \forall integer a, b, c; example_7_pre(a, b, c) ==> example_7_post(a, b, c);
*/

/*@
    predicate example_8_pre(integer a, integer b) = a + b == b + a;
    predicate example_8_post(integer a, integer b) = a + b <= b + a + 1;
    lemma example_8: \forall integer a, b; example_8_pre(a, b) ==> example_8_post(a, b);
*/

/*@
    predicate example_9_pre(integer a, integer b, integer c) = a < b && b < c;
    predicate example_9_post(integer a, integer b, integer c) = a < c;
    lemma example_9: \forall integer a, b, c; example_9_pre(a, b, c) ==> example_9_post(a, b, c);
*/

/*@
    predicate example_10_pre(integer a, integer b, integer c) = a < b && b <= c;
    predicate example_10_post(integer a, integer b, integer c) = a < c;
    lemma example_10: \forall integer a, b, c; example_10_pre(a, b, c) ==> example_10_post(a, b, c);
*/

int main() {
    return 0;
}
