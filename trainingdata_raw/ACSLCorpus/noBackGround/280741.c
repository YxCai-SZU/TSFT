/*@
    requires \true;
    ensures \true;
*/
void test() {
    //@ assert ((10) < 0 ? -(10) : (10)) >= 0;
    //@ assert ((10) < 0 ? -(10) : (10)) == 10;
    //@ assert ((-20) < 0 ? -(-20) : (-20)) >= 0;
    //@ assert ((-20) < 0 ? -(-20) : (-20)) == 20;
}

int main() {
    test();
    return 0;
}
