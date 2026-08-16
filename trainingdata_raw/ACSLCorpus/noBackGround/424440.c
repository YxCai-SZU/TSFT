/*@
    requires x >= 0;
    requires y >= 0;
    ensures \result >= x + 3;
*/
int arithmetic_operations_impl(int x, int y)
{
    int result;
    //@ assert x * y >= 0;
    //@ assert x * y + x >= x;
    //@ assert x * y + 2 * x >= 2 * x;
    //@ assert x * y + 2 * x + 3 >= 2 * x + 3;
    //@ assert 2 * x >= x;
    //@ assert 2 * x + 3 >= x + 3;
    //@ assert x * y + 2 * x + 3 >= x + 3;
    result = x * y + 2 * x + 3;
    return result;
}

int main()
{
    return 0;
}
