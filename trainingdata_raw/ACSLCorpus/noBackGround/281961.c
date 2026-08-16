/*@
    requires ((a) > (b)) && ((b) >= (c));
    ensures ((a) >= (c));
*/
void calc_example_4(unsigned char a, unsigned char b, unsigned char c) {
    //@ assert ((a) > (b));
    //@ assert ((b) >= (c));
    //@ assert ((a) >= (c));
}

int main() {
    return 0;
}
