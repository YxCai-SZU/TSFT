/*@
    predicate less_than_plus_one(integer a, integer b) = a + 1 < b + 2;
    predicate less_than_double(integer a, integer b) = a * 2 < b * 2;
*/

/*@
    lemma calc_example_2: \forall integer a, b; a < b ==> less_than_plus_one(a, b);
    lemma calc_example_3: \forall integer a, b; a < b ==> less_than_double(a, b);
*/

int main() {
    return 0;
}
