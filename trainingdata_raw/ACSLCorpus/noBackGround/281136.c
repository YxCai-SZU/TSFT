/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max_val;
    int a_val;
    int b_val;
    int c_val;
    int mid_val;
    int l_val;

    max_val = a;
    //@ assert max_val == a;
    if (b > max_val)
    {
        max_val = b;
    }
    //@ assert max_val >= a && max_val >= b;
    if (c > max_val)
    {
        max_val = c;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c;

    a_val = a < 0 ? -a : a;
    b_val = b < 0 ? -b : b;
    c_val = c < 0 ? -c : c;
    //@ assert a_val == ((a) < 0 ? -(a) : (a)) && b_val == ((b) < 0 ? -(b) : (b)) && c_val == ((c) < 0 ? -(c) : (c));

    mid_val = a_val < b_val ? a_val : b_val;
    //@ assert mid_val == (a_val < b_val ? a_val : b_val);
    if (c_val < mid_val)
    {
        mid_val = c_val;
    }
    //@ assert mid_val <= a_val && mid_val <= b_val && mid_val <= c_val;

    l_val = max_val + mid_val;
    //@ assert l_val == max_val + mid_val;
    //@ assert l_val >= 0;

    return l_val;
}
