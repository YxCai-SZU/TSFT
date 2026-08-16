/*@
    requires ((10) >= 0 && (20) >= 0 && (30) >= 0 && (10) + (20) == (30));
    assigns \nothing;
*/
void test(void) {
    //@ assert ((10) >= 0 && (20) >= 0 && (30) >= 0 && (10) + (20) == (30));
}

int main(void) {
    test();
    return 0;
}
