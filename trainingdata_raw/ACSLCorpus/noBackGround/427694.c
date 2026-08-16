/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == A * C || \result == A * D || \result == B * C || \result == B * D;
    assigns \nothing;
*/
long func(long A, long B, long C, long D)
{
    long answer;
    long max_val;

    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (C) <= 100);
    //@ assert (-10000 <= (A * C) <= 10000);
    //@ assert (-10000 <= (A * D) <= 10000);
    answer = A * C;

    max_val = A * D;
    if (max_val > answer) {
        answer = max_val;
    }

    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (B) <= 100);
    //@ assert (-10000 <= (B * C) <= 10000);
    //@ assert (-10000 <= (B * D) <= 10000);
    max_val = B * C;
    if (max_val > answer) {
        answer = max_val;
    }

    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (C) <= 100);
    //@ assert (-10000 <= (A * C) <= 10000);
    //@ assert (-10000 <= (A * D) <= 10000);
    max_val = B * D;
    if (max_val > answer) {
        answer = max_val;
    }

    return answer;
}
