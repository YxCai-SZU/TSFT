/*@
    predicate test_bool(integer a) = a == 0;

    lemma calc_example_8:
        \forall integer a; test_bool(a) ==> a == 0;

    logic integer square_number(integer n) = n * n;

    lemma calc_example_9:
        \forall integer n1, integer n2; 0 <= n1 && n1 <= n2 ==> square_number(n1) <= square_number(n2);
*/

/*@
    requires 3 <= 5;
    ensures square_number(3) <= square_number(5);
    assigns \nothing;
*/
void calc_example_9_proof() {
    //@ assert 3 <= 5;
    //@ assert 0 <= 3;
    //@ assert square_number(3) <= square_number(5);
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
