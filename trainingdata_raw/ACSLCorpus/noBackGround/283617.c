/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000);
    ensures \result == (500 * k >= x);
*/
int func(unsigned int k, unsigned int x)
{
    int result;
    //@ assert (1 <= (k) && (k) <= 100 &&         1 <= (x) && (x) <= 100000);
    result = (500 * k >= x);
    //@ assert result == (500 * k >= x);
    return result;
}

int main()
{
    //@ assert 500 * 1 >= 500;
    //@ assert !(500 * 1 >= 501);
    //@ assert 500 * 100 >= 50000;
    //@ assert !(500 * 100 >= 50001);
    return 0;
}
