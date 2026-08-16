/*@
    requires (0 <= (x) < 0x10000);
    ensures \result == x * x;
    assigns \nothing;
*/
unsigned int square(unsigned int x)
{
    //@ assert (0 <= (x) < 0x10000);
    //@ assert (0 <= (x * x) < 0x100000000);
    return x * x;
}

/*@
    requires (0 <= (x) < 0x10000) && (0 <= (y) < 0x10000);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int multiply(unsigned int x, unsigned int y)
{
    //@ assert (0 <= (x) < 0x10000) && (0 <= (y) < 0x10000);
    //@ assert (0 <= (x * y) < 0x100000000);
    return x * y;
}

int main()
{
    return 0;
}
