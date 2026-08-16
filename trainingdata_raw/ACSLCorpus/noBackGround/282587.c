/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + ((x) % 500) / 5 * 5);
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int result;
    unsigned int temp;
    unsigned int remainder;

    result = 0;
    temp = x / 500;
    result = result + temp * 1000;
    remainder = x % 500;
    temp = remainder / 5;
    result = result + temp * 5;

    //@ assert result == (x / 500) * 1000 + (x % 500) / 5 * 5;
    return result;
}
