/*@
    requires \true;
    ensures \result >= x && \result >= y;
    ensures \result == x || \result == y;
    assigns \nothing;
*/
int compute_g(int x, int y)
{
    int result;

    //@ assert (((x) > (y) ==> (((x) > (y) ? (x) : (y))) == (x)) && ((x) <= (y) ==> (((x) > (y) ? (x) : (y))) == (y)));
    
    if (x > y)
    {
        result = x;
    }
    else
    {
        result = y;
    }

    //@ assert result == ((x) > (y) ? (x) : (y));
    //@ assert result >= x;
    //@ assert result >= y;
    //@ assert result == x || result == y;

    return result;
}

int main()
{
    int a;
    int b;
    int max_val;

    a = 5;
    b = 3;
    max_val = compute_g(a, b);

    //@ assert max_val == a || max_val == b;
    //@ assert max_val >= a && max_val >= b;

    return 0;
}
