/*@
    predicate is_leap_year(integer y) =
        1 <= y <= 9999 &&
        (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
*/

/*@
    lemma leap_year_implies_divisible_by_4:
        \forall integer y; is_leap_year(y) ==> y % 4 == 0;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3;
*/
int func(int r)
{
    int pi_approx;
    int circumference;
    pi_approx = 3;
    circumference = 2 * r * pi_approx;
    //@ assert circumference == 2 * r * 3;
    return circumference;
}

/*@
    requires 1 <= year <= 9999;
    ensures \result == 1 <==> (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
*/
int is_leap_year(unsigned int year)
{
    int result;
    if (year % 4 != 0)
    {
        result = 0;
        return result;
    }
    else if (year % 100 != 0)
    {
        result = 1;
        return result;
    }
    else if (year % 400 != 0)
    {
        result = 0;
        return result;
    }
    else
    {
        result = 1;
        return result;
    }
}
