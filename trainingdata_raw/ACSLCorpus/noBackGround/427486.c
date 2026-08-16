/*@
    requires (0 <= (a) <= 50) && (0 <= (b) <= 50) && (0 <= (c) <= 50);
    ensures ((\result) >= 0);
    ensures \result <= a + b + c;
*/
long func(long a, long b, long c)
{
    long result;
    long min_ab;
    long min_val;
    long remainder;

    result = 0;
    //@ assert ((result) >= 0);

    // Calculate min(a, b)
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == (((a) < (b)) ? (a) : (b));
    //@ assert ((min_ab) >= 0);

    // Calculate min(min_ab, c)
    if (min_ab < c) {
        min_val = min_ab;
    } else {
        min_val = c;
    }
    //@ assert min_val == (((min_ab) < (c)) ? (min_ab) : (c));
    //@ assert ((min_val) >= 0);
    //@ assert min_val <= a + b + c;

    result += min_val;
    //@ assert ((result) >= 0);
    //@ assert result <= a + b + c;

    remainder = c - min_val;
    //@ assert ((remainder) >= 0);

    if (remainder > 0) {
        result += remainder;
    } else {
        result += 0;
    }
    //@ assert result == min_val + (remainder > 0 ? remainder : 0);
    //@ assert ((result) >= 0);
    //@ assert result <= a + b + c;

    return result;
}
