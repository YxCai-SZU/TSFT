/*@
    requires ((n) >= 0 && (n) < 0x00010000);
    ensures ((\result) == (n) * (n));
    assigns \nothing;
*/
unsigned int is_square(unsigned int n)
{
    //@ assert n * n < 0x00010000 * 0x00010000;
    return n * n;
}

int main(void)
{
    return 0;
}
