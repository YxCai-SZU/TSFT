/*@
    requires x < 46340;
    ensures \result == x * x;
    assigns \nothing;
*/
unsigned int compute_square(unsigned int x)
{
    //@ assert x < 46340;
    unsigned int result;
    result = x * x;
    //@ assert result == x * x;
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    unsigned int x;
    unsigned int square;
    x = 100;
    //@ assert x < 46340;
    square = compute_square(x);
    //@ assert square == 10000;
    return 0;
}
