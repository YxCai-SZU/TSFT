/*@
    logic integer circumference_circle(integer r) = (2 * 31416 * r) / 10000;

    lemma circumference_nonlinear:
        \forall integer r; r >= 0 ==> circumference_circle(r) >= 0;

    lemma circumference_linear:
        \forall integer r; r >= 0 ==> circumference_circle(r) == (2 * 31416 * r) / 10000;
*/

void test() {
    //@ assert circumference_circle(100) >= 0;
    //@ assert circumference_circle(100) == (2 * 31416 * 100) / 10000;
}

int main() {
    return 0;
}
