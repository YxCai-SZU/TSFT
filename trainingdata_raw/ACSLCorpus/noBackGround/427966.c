/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
int func2(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    result = (b - a == c - b);
    //@ assert result == (b - a == c - b);
    return result;
}

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
*/
int func(int r)
{
    int pi;
    int circumference;
    //@ assert (1 <= (r) <= 100);
    pi = 3;
    circumference = 2 * r * pi;
    //@ assert circumference == (6 * (r));
    return circumference;
}

int main()
{
    return 0;
}
