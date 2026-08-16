/*@
    predicate valid_input(integer a, integer b) =
        0 <= a && a <= 23 &&
        0 <= b && b <= 23;

    logic integer mod24_sum(integer a, integer b) =
        (a + b) % 24;

    lemma mod24_range:
        \forall integer a, b;
        valid_input(a, b) ==> 0 <= mod24_sum(a, b) && mod24_sum(a, b) <= 23;
*/


unsigned int func(unsigned int a, unsigned int b) {
    unsigned int res;
    unsigned int sum;

    sum = a + b;
    res = sum % 24;

    //@ assert res == mod24_sum(a, b);
    //@ assert 0 <= res && res <= 23;

    return res;
}

/*@
    lemma nonlinear_arithmetic_example_4:
        \forall integer a, b;
        valid_input(a, b) ==> a * b == a * b;
*/
