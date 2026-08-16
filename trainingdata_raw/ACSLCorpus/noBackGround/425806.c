/*@
    requires ((a) < (b) && (b) < (c));
    ensures \result == a + (c - b);
    ensures \result == c - (b - a);
*/
int calc_example_2(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c));
    //@ assert a + (c - b) == c - (b - a);
    return a + (c - b);
}

/*@
    requires ((a) < (b) && (b) < (c));
    ensures \result == (b - a) + (c - b);
    ensures \result == c - a;
*/
int example_3(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c));
    //@ assert (b - a) + (c - b) == c - a;
    return (b - a) + (c - b);
}

/*@
    requires ((a) < (b) && (b) < (c));
    ensures \result == a + (c - b);
    ensures \result == c - (b - a);
*/
int example_4(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c));
    //@ assert a + (c - b) == c - (b - a);
    return a + (c - b);
}

int main()
{
    return 0;
}
