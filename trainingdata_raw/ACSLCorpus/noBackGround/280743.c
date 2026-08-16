/*@
    requires \true;
    ensures \true;
*/
void example_abs_usage(void)
{
    //@ assert (((-5) < 0) ? -(-5) : (-5)) >= 0;
    //@ assert (((-8) < 0) ? -(-8) : (-8)) >= 0;
    //@ assert (((10) < 0) ? -(10) : (10)) >= 0;
}

int main(void)
{
    return 0;
}
