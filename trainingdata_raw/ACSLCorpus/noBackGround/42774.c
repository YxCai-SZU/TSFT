/*@
    requires \true;
    ensures \true;
*/
void example_double(void) {
    //@ assert (((3) <= 0) ? 0 : 2 * (3)) <= (((7) <= 0) ? 0 : 2 * (7));
    //@ assert (((10) <= 0) ? 0 : 2 * (10)) <= (((20) <= 0) ? 0 : 2 * (20));
}

int main(void) {
    example_double();
    return 0;
}
