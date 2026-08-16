/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int add;
    int sub;
    int mul;
    int result;

    add = a + b;
    sub = a - b;
    mul = a * b;

    //@ assert -200 <= add <= 200;
    //@ assert -200 <= sub <= 200;
    //@ assert -10000 <= mul <= 10000;

    if (add >= sub && add >= mul)
    {
        result = add;
    }
    else if (sub >= add && sub >= mul)
    {
        result = sub;
    }
    else
    {
        result = mul;
    }

    //@ assert result == (((add) >= (sub) && (add) >= (mul)) ? (add) : (((sub) >= (add) && (sub) >= (mul)) ? (sub) : (mul)));
    return result;
}
