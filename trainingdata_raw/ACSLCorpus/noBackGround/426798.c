/*@
    requires \true;
    ensures \true;
*/
void example_mul_usage(void)
{
    //@ assert ((10) * (3)) == 30;
    //@ assert ((12) * (4)) == 48;
    //@ assert ((97) * (11)) == 1067;
}

int main(void)
{
    example_mul_usage();
    return 0;
}
