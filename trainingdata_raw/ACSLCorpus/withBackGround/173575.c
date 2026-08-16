/*@
    predicate is_product(integer a, integer b, integer c) = a * b == c;
*/

/*@
    lemma prod_example_1:
        \forall integer a, b;
        a == 5 && b == 3 ==> is_product(a, b, 15);
*/

/*@
    lemma prod_example_2:
        \forall integer a, b;
        a == 4 && b == 6 ==> is_product(a, b, 24);
*/

int main() {
    int a;
    int b;
    int result;

    a = 5;
    b = 3;
    //@ assert a == 5;
    //@ assert b == 3;
    //@ assert is_product(a, b, 15);
    result = a * b;

    a = 4;
    b = 6;
    //@ assert a == 4;
    //@ assert b == 6;
    //@ assert is_product(a, b, 24);
    result = a * b;

    return 0;
}
