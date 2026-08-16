/*@
    requires (0 <= (a) <= 50) && (0 <= (b) <= 50) && (0 <= (c) <= 50);
    ensures \result >= 0;
    ensures \result <= a + b + c;
*/
long func(long a, long b, long c)
{
    long result;
    long min_ab;
    long min_val;
    long remaining_a;
    long remaining_b;
    long remaining_c;
    long min_remaining;

    result = 0;

    //@ assert ((a) >= 0) && ((b) >= 0) && ((c) >= 0);

    // Implementing min function manually
    min_ab = a < b ? a : b;
    //@ assert ((min_ab) >= 0);

    min_val = min_ab < c ? min_ab : c;
    //@ assert ((min_val) >= 0);
    //@ assert min_val <= a + b + c;

    result += min_val;
    //@ assert result == min_val;

    // Implementing min function manually for the remaining values
    remaining_a = a - min_val;
    remaining_b = b - min_val;
    remaining_c = c - min_val;

    //@ assert ((remaining_a) >= 0) && ((remaining_b) >= 0) && ((remaining_c) >= 0);

    min_remaining = remaining_a < remaining_b ? remaining_a : remaining_b;
    //@ assert ((min_remaining) >= 0);

    result += min_remaining < remaining_c ? min_remaining : remaining_c;
    //@ assert result >= 0;

    //@ assert result <= a + b + c;

    return result;
}
