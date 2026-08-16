/*@
    predicate valid_params(integer x, integer a, integer b) =
        1 <= a && a <= 1000 &&
        1 <= b && b <= 1000 &&
        a + b <= x && x <= 10000 &&
        x % 1 == 0 &&
        a % 1 == 0 &&
        b % 1 == 0;

    logic integer func_result(integer x, integer a, integer b) =
        (x - a) > (a + b - x) ? (x - a) : (a + b - x);
*/

/*@
    requires valid_params(x, a, b);
    ensures \result >= 0;
    ensures \result <= x;
    ensures \result == x - a || \result == a + b - x;
    assigns \nothing;
*/
long func(long x, long a, long b)
{
    long result;
    //@ assert valid_params(x, a, b);
    
    if (x - a > a + b - x)
    {
        //@ assert x - a >= 0;
        //@ assert x - a <= x;
        result = x - a;
    }
    else
    {
        //@ assert a + b - x >= 0;
        //@ assert a + b - x <= x;
        result = a + b - x;
    }
    
    return result;
}
