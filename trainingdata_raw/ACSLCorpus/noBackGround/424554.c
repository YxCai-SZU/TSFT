/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B)) && \result >= ((C) * (D));
*/
long func(long A, long B, long C, long D)
{
    long result;
    long new_result;

    //@ assert ((A) * (B)) <= 100000000;
    //@ assert ((C) * (D)) <= 100000000;

    result = A * B;
    new_result = C * D;

    if (new_result > result) {
        result = new_result;
    }

    if (C * D > A * B) {
        //@ assert ((C) * (D)) >= ((A) * (B));
        result = C * D;
    } else {
        //@ assert ((A) * (B)) >= ((C) * (D));
        result = A * B;
    }

    return result;
}
