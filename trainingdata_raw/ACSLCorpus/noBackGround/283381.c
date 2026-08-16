/*@
    requires 1 <= x < 10;
    requires 1 <= y < 10;
    ensures \result == ((x * y) % 2 == 0);
    assigns \nothing;
*/
int func(unsigned int x, unsigned int y)
{
    // Variable declarations
    unsigned int product;
    int is_even;

    //@ assert x * y < 100;
    product = x * y;
    is_even = (product % 2 == 0);
    return is_even;
}

int main()
{
    return 0;
}
