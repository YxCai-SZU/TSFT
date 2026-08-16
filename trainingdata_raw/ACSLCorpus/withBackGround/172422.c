/*@
    predicate is_less_than(integer a, integer b, integer c) =
        a < b && b < c;

    predicate is_greater_than(integer a, integer b, integer c) =
        a > b && b > c;

    lemma less_than_transitive:
        \forall integer a, b, c;
            is_less_than(a, b, c) ==> a < c;

    lemma greater_than_transitive:
        \forall integer a, b, c;
            is_greater_than(a, b, c) ==> a > c;
*/

int main() {
    int a, b, c;
    
    //@ assert is_less_than(1, 2, 3);
    //@ assert is_greater_than(3, 2, 1);
    
    return 0;
}
