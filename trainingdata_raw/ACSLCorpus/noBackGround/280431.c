/*@
    requires a == b && b == c;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_7(int a, int b, int c) {
    //@ assert a == b;
    //@ assert b == c;
    //@ assert a == c;
    return 0;
}

/*@
    requires \forall integer i; ((i) + (i)) == i + i;
    requires \forall integer i; (2 * (i)) == 2 * i;
    ensures \forall integer i; ((i) + (i)) == (2 * (i));
    assigns \nothing;
*/
void two_doubles_equal() {
    //@ assert \forall integer i; ((i) + (i)) == i + i;
    //@ assert \forall integer i; (2 * (i)) == 2 * i;
    //@ assert \forall integer i; ((i) + (i)) == (2 * (i));
}

int main() {
    return 0;
}
