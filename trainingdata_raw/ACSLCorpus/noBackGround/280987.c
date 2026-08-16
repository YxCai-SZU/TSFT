/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result == c || \result == ((a) * (b));
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int ans;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    //@ assert ((a) * (b)) <= 10000;

    if (a * b < c)
    {
        ans = a * b;
    }
    else
    {
        ans = c;
    }

    //@ assert ans <= c;
    //@ assert ans == c || ans == ((a) * (b));

    return ans;
}

int main()
{
    return 0;
}
