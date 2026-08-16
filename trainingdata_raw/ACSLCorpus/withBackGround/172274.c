/*@
    logic integer multiply(integer x, integer y) = x * y;

    lemma multiply_commutativity:
        \forall integer x, y; multiply(x, y) == multiply(y, x);
*/

/*@
    requires \true;
    ensures \true;
*/
void example_multiply_usage(void) {
    //@ assert multiply(3, 5) == multiply(5, 3);
    //@ assert multiply(2, 8) == multiply(8, 2);
    //@ assert multiply(-1, 10) == multiply(10, -1);
}

int main() {
    example_multiply_usage();
    return 0;
}
