/*@
    requires \true;
    ensures \true;
*/
void example_test_usage(void) {
    //@ assert ((10) + 1) <= ((20) + 1);
    //@ assert ((15) + 1) <= ((30) + 1);
    //@ assert ((0) + 1) <= ((50) + 1);
}
