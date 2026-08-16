/*@
    requires ((a) == (b) + (c));
    ensures ((a) <= (b) + (c) + 1);
*/
void example_3(int a, int b, int c)
{
    //@ assert a == b + c;
    //@ assert a <= b + c + 1;
}

/*@
    requires ((x) == (y) + 1);
    ensures ((x) <= (y) + 2);
*/
void example_4(int x, int y)
{
    //@ assert x == y + 1;
    //@ assert x <= y + 2;
}

/*@
    requires ((x) == (y) + (z) && (y) == (z) + 1);
    ensures ((x) <= (y) + (z) + 1);
*/
void example_5(int x, int y, int z)
{
    //@ assert x == y + z;
    //@ assert y == z + 1;
    //@ assert x <= y + z + 1;
}

/*@
    requires ((x) == (y) + (z) && (y) == (z) + 1);
    ensures ((x) <= (y) + (z) + 2);
*/
void example_6(int x, int y, int z)
{
    //@ assert x == y + z;
    //@ assert y == z + 1;
    //@ assert x <= y + z + 2;
}

int main(void)
{
    return 0;
}
