#include <stdint.h>

/*@
    requires 1 <= A <= 9;
    requires 1 <= B <= 9;
    requires 1 <= C <= 9;
    ensures \result >= 10 && \result <= 999;
    ensures \result == ((A) == (B) && (B) == (C) ? (A) * 10 + (B) + (C) :
        (A) == (B) ? (A) * 10 + (B) + 1 + (C) :
        (B) == (C) ? (A) + (B) * 10 + (C) + 1 :
        (A) == (C) ? (A) + (B) + (C) * 10 + 1 :
        (A) + (B) * 10 + (C) + 2);
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    // Variable declarations at top of scope
    int64_t result;

    if (A == B && B == C)
    {
        result = A * 10 + B + C;
        //@ assert result == ((A) == (B) && (B) == (C) ? (A) * 10 + (B) + (C) :         (A) == (B) ? (A) * 10 + (B) + 1 + (C) :         (B) == (C) ? (A) + (B) * 10 + (C) + 1 :         (A) == (C) ? (A) + (B) + (C) * 10 + 1 :         (A) + (B) * 10 + (C) + 2);
        return result;
    }
    else if (A == B)
    {
        //@ assert A * 10 + B + 1 + C >= 10 && A * 10 + B + 1 + C <= 999;
        result = A * 10 + B + 1 + C;
        //@ assert result == ((A) == (B) && (B) == (C) ? (A) * 10 + (B) + (C) :         (A) == (B) ? (A) * 10 + (B) + 1 + (C) :         (B) == (C) ? (A) + (B) * 10 + (C) + 1 :         (A) == (C) ? (A) + (B) + (C) * 10 + 1 :         (A) + (B) * 10 + (C) + 2);
        return result;
    }
    else if (B == C)
    {
        //@ assert A + B * 10 + C + 1 >= 10 && A + B * 10 + C + 1 <= 999;
        result = A + B * 10 + C + 1;
        //@ assert result == ((A) == (B) && (B) == (C) ? (A) * 10 + (B) + (C) :         (A) == (B) ? (A) * 10 + (B) + 1 + (C) :         (B) == (C) ? (A) + (B) * 10 + (C) + 1 :         (A) == (C) ? (A) + (B) + (C) * 10 + 1 :         (A) + (B) * 10 + (C) + 2);
        return result;
    }
    else if (A == C)
    {
        //@ assert A + B + C * 10 + 1 >= 10 && A + B + C * 10 + 1 <= 999;
        result = A + B + C * 10 + 1;
        //@ assert result == ((A) == (B) && (B) == (C) ? (A) * 10 + (B) + (C) :         (A) == (B) ? (A) * 10 + (B) + 1 + (C) :         (B) == (C) ? (A) + (B) * 10 + (C) + 1 :         (A) == (C) ? (A) + (B) + (C) * 10 + 1 :         (A) + (B) * 10 + (C) + 2);
        return result;
    }
    else
    {
        //@ assert A + B * 10 + C + 2 >= 10 && A + B * 10 + C + 2 <= 999;
        result = A + B * 10 + C + 2;
        //@ assert result == ((A) == (B) && (B) == (C) ? (A) * 10 + (B) + (C) :         (A) == (B) ? (A) * 10 + (B) + 1 + (C) :         (B) == (C) ? (A) + (B) * 10 + (C) + 1 :         (A) == (C) ? (A) + (B) + (C) * 10 + 1 :         (A) + (B) * 10 + (C) + 2);
        return result;
    }
}
