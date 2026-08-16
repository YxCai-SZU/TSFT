/*@
predicate distributive_property(integer a, integer b, integer c) =
    a * (b + c) == a * b + a * c;

lemma distributive_add: \forall integer a, b, c; distributive_property(a, b, c);
*/

int main() {
    //@ assert distributive_property(1, 2, 3);
    return 0;
}
