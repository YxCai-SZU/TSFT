/*@
    requires ((8)) == ((a));
    ensures ((3)) <= ((a));
*/
void calc_example_a(int a) {
    //@ assert ((8)) == ((a));
}

int main() {
    return 0;
}
