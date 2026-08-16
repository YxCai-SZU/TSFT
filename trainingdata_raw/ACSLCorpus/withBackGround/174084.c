/*@
    predicate non_negative(integer val) = val >= 0;
    predicate within_range(integer val, integer low, integer high) = low <= val && val <= high;
    predicate pay_condition(integer x, integer a, integer pay) = (x > a ==> pay == x - a) && (x <= a ==> pay == 0);
    predicate result_condition(integer pay, integer b, integer result) = result == pay + b;
*/

/*@
    requires 1 <= x && x <= 10000;
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    ensures \result >= 0;
    ensures \result <= x + b;
*/
int func(int x, int a, int b)
{
    int pay;
    int result;

    //@ assert within_range(x, 1, 10000);
    //@ assert within_range(a, 1, 10000);
    //@ assert within_range(b, 1, 10000);

    if (x > a)
    {
        pay = x - a;
        //@ assert pay_condition(x, a, pay);
    }
    else
    {
        pay = 0;
        //@ assert pay_condition(x, a, pay);
    }

    //@ assert non_negative(pay);
    //@ assert non_negative(b);
    //@ assert pay <= x;

    result = pay + b;
    //@ assert result_condition(pay, b, result);

    //@ assert non_negative(result);
    //@ assert result <= x + b;

    return result;
}
