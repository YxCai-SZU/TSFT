/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (B) && (B) <= 100 &&
        0 <= (C) && (C) <= 100);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result <= A + B + 1 + C;
    assigns \nothing;
*/
int min_tasty_cookies(int A, int B, int C)
{
    int min_val;
    int result;

    //@ assert (0 <= (A) && (A) <= 100 &&         0 <= (B) && (B) <= 100 &&         0 <= (C) && (C) <= 100);

    if (A + B + 1 < C)
    {
        min_val = A + B + 1;
        //@ assert min_val == A + B + 1;
    }
    else
    {
        min_val = C;
        //@ assert min_val == C;
    }

    //@ assert min_val == ((A) + (B) + 1 < (C) ? (A) + (B) + 1 : (C));
    result = C - min_val;

    //@ assert result == C - ((A) + (B) + 1 < (C) ? (A) + (B) + 1 : (C));
    return result;
}
