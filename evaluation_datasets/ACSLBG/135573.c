/*@
    predicate valid_range(integer x) = 0 <= x <= 100;
*/

/*@
    lemma product_bound:
        \forall integer x, integer y;
            valid_range(x) && valid_range(y) ==> x * y <= 10000;
*/


int func(int a, int b, int c, int d)
{
    int result;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert valid_range(c) && valid_range(d);

    if (a * b > c * d)
    {
        result = a * b;
    }
    else
    {
        result = c * d;
    }

    //@ assert result == a * b || result == c * d;
    //@ assert result >= a * b && result >= c * d;

    return result;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int result;

    result = func(a, b, c, d);
    //@ assert result == 12;

    return 0;
}
