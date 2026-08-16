/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;

    logic integer sum(integer x, integer y) = x + y;

    predicate check_condition(integer a, integer b, integer c, integer result) =
        result == 1 <==> (sum(a, b) == c || sum(a, c) == b || sum(b, c) == a);
*/


int func(long long a, long long b, long long c)
{
    int result;
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    
    if (a + b == c || a + c == b || b + c == a) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert check_condition(a, b, c, result);
    return result;
}
