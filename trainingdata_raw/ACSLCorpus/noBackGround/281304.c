/*@
    requires ((a) == (b) + (c));
    ensures ((a) <= (b) + (c) + 1);
*/
void example_4(int a, int b, int c)
{
    //@ assert a == b + c;
    //@ assert a <= b + c + 1;
}

/*@
    requires ((a) == (b) + (c));
    ensures ((a) <= (b) + (c) + 1);
*/
void example_5(int a, int b, int c)
{
    //@ assert a == b + c;
    //@ assert a <= b + c + 1;
}

int main()
{
    return 0;
}
