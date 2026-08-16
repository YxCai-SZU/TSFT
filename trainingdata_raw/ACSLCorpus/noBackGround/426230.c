/*@
    requires ((a) - 2 == (b));
    ensures ((a) == (b) + 2);
    assigns \nothing;
*/
void func_example_7(int a, int b) {
    //@ assert a - 2 == b;
    //@ assert a == b + 2;
    //@ assert a - 2 <= b;
    //@ assert a <= b + 2;
    //@ assert a - 2 == b;
    //@ assert a == b + 2;
    //@ assert a - 2 >= b;
    //@ assert a >= b + 2;
}

int main() {
    return 0;
}
