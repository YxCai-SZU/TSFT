/*@
requires ((3) % 2 != 0);
ensures \true;
*/
void example_odd_usage(void) {
    //@ assert ((3) % 2 != 0);
    //@ assert !((4) % 2 != 0);
}

int main() {
    example_odd_usage();
    return 0;
}
