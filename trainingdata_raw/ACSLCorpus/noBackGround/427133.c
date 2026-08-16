/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100);
    ensures \result == ((a) * ((b) + (c)));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int result;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100);
    result = a * (b + c);
    //@ assert result == ((a) * ((b) + (c)));
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
