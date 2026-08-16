/*@
    predicate is_abs(integer x, integer result) =
        (x >= 0 ==> result == x) &&
        (x < 0 ==> result == -x);

    logic integer abs(integer x) =
        x >= 0 ? x : -x;

    logic integer max(integer x, integer y) =
        x > y ? x : y;

    lemma max_lemma_1:
        \forall integer a, b, m;
            m == max(a, b) ==> a <= m && b <= m;

    lemma max_lemma_2:
        \forall integer a, b, m;
            m == max(a, b) ==> m == a || m == b;

    lemma sum_bound_lemma:
        \forall integer a, b, c, d, m1, m2;
            m1 == max(a, b) && m2 == max(c, d) ==>
            m1 + m2 <= max(a, b) + max(c, d);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int res;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;

    if (a > b)
    {
        max1 = a;
    }
    else
    {
        max1 = b;
    }

    //@ assert max1 == max(a, b);
    //@ assert a <= max1 && b <= max1;

    if (c > d)
    {
        max2 = c;
    }
    else
    {
        max2 = d;
    }

    //@ assert max2 == max(c, d);
    //@ assert c <= max2 && d <= max2;

    //@ assert max1 + max2 <= a + b + c + d;
    res = max1 + max2;

    //@ assert res >= 0;

    return res;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
