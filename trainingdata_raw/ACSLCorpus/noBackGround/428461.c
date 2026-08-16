/*@
    requires n > 0;
    ensures \result == n;
*/
int ext_equal_fnspec(int n)
{
    //@ assert ((n) > 0);
    return n;
}

/*@
    requires n > 0;
    ensures \result == n;
*/
int ext_equal_struct(int n)
{
    //@ assert ((n) > 0);
    return n;
}

int main()
{
    return 0;
}
