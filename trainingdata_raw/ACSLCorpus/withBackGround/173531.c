/*@
    predicate is_positive(integer x) = x >= 1;

    lemma multiply_property:
        \forall integer a, b;
            is_positive(a) && is_positive(b) ==> is_positive(a * b);

    lemma add_and_multiply_property:
        \forall integer a, b, c;
            is_positive(a) && is_positive(b) && is_positive(c) ==> is_positive(a + b * c);
*/

int main() {
    return 0;
}
