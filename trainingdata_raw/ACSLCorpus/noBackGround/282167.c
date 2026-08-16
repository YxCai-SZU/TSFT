/*@
    requires ((a) < 5);
    ensures ((\result) == (a) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int result;
    unsigned int i = 0;

    /*@
        loop invariant ((i) <= 10);
        loop invariant ((a) < 5);
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        i = i + 1;
    }

    result = a + 1;
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
