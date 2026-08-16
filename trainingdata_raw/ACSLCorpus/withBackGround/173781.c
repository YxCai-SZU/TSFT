/*@
    predicate equality_chain(integer a, integer b, integer c) =
        a + 3 == b + 2 && b + 2 == c + 1;

    lemma calculation_combining_example:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_multiple:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_maximum:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_oneline:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_maximum_1:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_maximum_2:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_maximum_3:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;

    lemma example_maximum_4:
        \forall integer a, b, c;
        equality_chain(a, b, c) ==> a + 3 == c + 1;
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert \true;
    
    return 0;
}
