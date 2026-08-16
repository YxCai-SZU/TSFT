/*@
    requires \true;
    ensures \true;
*/
void example_mod_usage(void)
{
    //@ assert ((10) % (3)) < 3;
    //@ assert ((9) % (7)) < 7;
}

int main(void)
{
    example_mod_usage();
    return 0;
}
