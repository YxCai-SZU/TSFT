/*@
predicate is_greater_than(integer a, integer b) = a > b;

lemma distributive_and_associative_add:
    \forall integer a, b, c; a + (b + c) == a + (c + b);

lemma transitive_greater_than:
    \forall integer a, b, c; (a > b && b > c) ==> a > c;

lemma example_no_parens:
    \forall integer a, b; a > b ==> a > b;
*/

/*@
requires a > b;
ensures \result == 1;
assigns \nothing;
*/
int example_no_parens_func(int a, int b) {
    int result;
    //@ assert a > b;
    result = (a > b);
    return result;
}

/*@
assigns \nothing;
*/
int main() {
    return 0;
}
