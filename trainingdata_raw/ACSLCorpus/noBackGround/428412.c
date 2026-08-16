/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    requires ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100) && (a) * (b) <= 1000) && ((1 <= ((a)) <= 100) && (1 <= ((c)) <= 100) && (a) * (c) <= 1000);
    requires ((1 <= (((d))) <= 100) && (1 <= ((d)) <= 100) && ((d)) * (d) <= 1000) && ((1 <= ((c)) <= 100) && (1 <= ((d)) <= 100) && (c) * (d) <= 1000);
    ensures \result == a * b || \result == c * d;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long result;

    //@ assert ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100) && (a) * (b) <= 1000);
    x = a * b;

    //@ assert ((1 <= ((c)) <= 100) && (1 <= ((d)) <= 100) && (c) * (d) <= 1000);
    y = c * d;

    if (x > y) {
        result = x;
    } else {
        result = y;
    }

    //@ assert result == x || result == y;
    return result;
}
