/*@
    requires \true;
    ensures \true;
*/
void example_mul_usage(void) {
    //@ assert ((1) * (((2) * (3)))) == ((((1) * (2))) * (3));
    //@ assert ((4) * (((5) * (6)))) == ((((4) * (5))) * (6));
    //@ assert ((7) * (((8) * (9)))) == ((((7) * (8))) * (9));
}

int main(void) {
    example_mul_usage();
    return 0;
}
