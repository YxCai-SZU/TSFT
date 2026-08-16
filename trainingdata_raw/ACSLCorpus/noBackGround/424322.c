/*@
    requires (0 < (x) && (x) < (y));
    ensures ((x) * 2 < (y) * 2);
*/
void example_5(int x, int y)
{
    //@ assert 0 < x && x < y;
    //@ assert x * 2 < y * 2;
}

int main()
{
    return 0;
}
