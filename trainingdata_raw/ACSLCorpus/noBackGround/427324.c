/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= 1;
    assigns \nothing;
*/
long func(long A, long B, long C, long D)
{
    long S1;
    long S2;
    long result;

    //@ assert 1 <= ((A) * (B)) <= 100000000;
    //@ assert 1 <= ((C) * (D)) <= 100000000;

    S1 = A * B;
    S2 = C * D;

    //@ assert S1 == ((A) * (B));
    //@ assert S2 == ((C) * (D));
    //@ assert S1 >= 1;
    //@ assert S2 >= 1;

    if (S1 >= S2)
    {
        result = S1;
    }
    else
    {
        result = S2;
    }

    //@ assert result == S1 || result == S2;
    //@ assert result >= 1;

    return result;
}
