#include <stdbool.h>

/*@
    requires ((A) >= 0 && (A) <= 123 &&
        (B) >= 0 && (B) <= 123 &&
        (C) >= 0 && (C) <= 123 &&
        (D) >= 0 && (D) <= 123 &&
        (E) >= 0 && (E) <= 123 &&
        (K) >= 0 && (K) <= 123);
    ensures \result == true <==> (A + B + C + D + E + 5 - K) <= 0;
    assigns \nothing;
*/
bool func(long A, long B, long C, long D, long E, long K)
{
    long a, b, c, d, e;
    long sum;
    bool result;

    a = A;
    b = B;
    c = C;
    d = D;
    e = E;

    //@ assert a == A && b == B && c == C && d == D && e == E;

    a = (a + 1 < a) ? (a + 1) : a;
    //@ assert a == A;

    b = (b + 1 < b) ? (b + 1) : b;
    //@ assert b == B;

    c = (c + 1 < c) ? (c + 1) : c;
    //@ assert c == C;

    d = (d + 1 < d) ? (d + 1) : d;
    //@ assert d == D;

    e = (e + 1 < e) ? (e + 1) : e;
    //@ assert e == E;

    sum = a + b + c + d + e + 5 - K;
    //@ assert sum == ((A) + (B) + (C) + (D) + (E) + 5 - (K));

    if (sum <= 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (A + B + C + D + E + 5 - K) <= 0;
    return result;
}
