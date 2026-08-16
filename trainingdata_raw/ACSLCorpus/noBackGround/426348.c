/*@
    requires 0 <= a < 100;
    requires 0 <= b < 100;
    ensures \result == (a * b < 10000);
    assigns \nothing;
*/
int non_linear_arith_example(unsigned int a, unsigned int b) {
    //@ assert (0 <= (a) < 100 && 0 <= (b) < 100);
    //@ assert ((a) * (b)) < 10000;
    return a * b < 10000;
}

