/*@
    requires \true;
    ensures \true;
*/
void example_min_usage(void)
{
    //@ assert (((10) <= (20)) ? (10) : (20)) <= 10;
    //@ assert (((9) <= (7)) ? (9) : (7)) <= 9;
}

int main(void)
{
    example_min_usage();
    return 0;
}
