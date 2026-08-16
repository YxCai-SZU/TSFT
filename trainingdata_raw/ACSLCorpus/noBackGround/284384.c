/*@
    requires (-10000 <= (A) <= 10000) && (-10000 <= (B) <= 10000) && (-10000 <= (C) <= 10000) && (-10000 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int prod1;
    int prod2;
    int max_val;

    //@ assert (-10000 <= (A) <= 10000) && (-10000 <= (B) <= 10000);
    //@ assert -100000000 <= ((A) * (B)) <= 100000000;
    prod1 = A * B;

    //@ assert (-10000 <= (C) <= 10000) && (-10000 <= (D) <= 10000);
    //@ assert -100000000 <= ((C) * (D)) <= 100000000;
    prod2 = C * D;

    if (prod1 > prod2) {
        max_val = prod1;
    } else {
        max_val = prod2;
    }

    //@ assert max_val >= ((A) * (B));
    //@ assert max_val >= ((C) * (D));

    return max_val;
}
