/*@
    requires (0 <= (x) && (x) <= 10 && 0 <= (y) && (y) <= 10);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
unsigned char multiply(unsigned char x, unsigned char y)
{
    //@ assert (0 <= (x) && (x) <= 10 && 0 <= (y) && (y) <= 10);
    //@ assert ((x) * (y)) <= 100;
    return x * y;
}

int main()
{
    return 0;
}
