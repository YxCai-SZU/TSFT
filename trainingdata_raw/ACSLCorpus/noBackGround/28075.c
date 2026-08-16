/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == ((n) - (k) + 1);
*/
int func(int n, int k)
{
    int res;
    //@ assert (1 <= (k) && (k) <= (n) && (n) <= 50);
    res = n - k + 1;
    //@ assert res == ((n) - (k) + 1);
    return res;
}

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) / 2 + (n) % 2);
*/
int func2(int n)
{
    int half;
    int temp_n;
    int count;
    int remainder;
    int res;

    half = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count && count <= n / 2;
        loop invariant temp_n == n - 2 * count;
        loop assigns temp_n, count;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n == n - 2 * count;
        temp_n -= 2;
        count += 1;
        //@ assert temp_n == n - 2 * count;
    }

    if (temp_n == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }

    half = count;
    res = half + remainder;
    //@ assert res == ((n) / 2 + (n) % 2);
    return res;
}

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) / 2 + (n) % 2);
*/
int func3(int n)
{
    int half;
    int temp_n;
    int count;
    int remainder;
    int res;

    half = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count && count <= n / 2;
        loop invariant temp_n == n - 2 * count;
        loop assigns temp_n, count;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n == n - 2 * count;
        temp_n -= 2;
        count += 1;
        //@ assert temp_n == n - 2 * count;
    }

    if (temp_n == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }

    half = count;
    res = half + remainder;
    //@ assert res == ((n) / 2 + (n) % 2);
    return res;
}

/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == ((n) - (k) + 1);
*/
int func4(int n, int k)
{
    int res;
    //@ assert (1 <= (k) && (k) <= (n) && (n) <= 50);
    res = n - k + 1;
    //@ assert res == ((n) - (k) + 1);
    return res;
}

int main()
{
    return 0;
}
