/*@
    requires (-10000 <= (A) <= 10000) && (-10000 <= (B) <= 10000) && (-10000 <= (C) <= 10000) && (-10000 <= (D) <= 10000);
    requires A <= B && C <= D;
    ensures \result == ((B) * (D)) || \result == ((A) * (C)) ||
            \result == ((A) * (D)) || \result == ((B) * (C));
*/
long func(long A, long B, long C, long D)
{
    long max_val;
    long temp_val;

    //@ assert (-10000 <= (A) <= 10000);
    //@ assert (-10000 <= (B) <= 10000);
    //@ assert (-10000 <= (C) <= 10000);
    //@ assert (-10000 <= (D) <= 10000);
    
    //@ assert ((A) * (C)) <= 100000000;
    //@ assert ((A) * (C)) >= -100000000;
    
    //@ assert ((A) * (D)) <= 100000000;
    //@ assert ((A) * (D)) >= -100000000;
    
    //@ assert ((B) * (C)) <= 100000000;
    //@ assert ((B) * (C)) >= -100000000;
    
    //@ assert ((B) * (D)) <= 100000000;
    //@ assert ((B) * (D)) >= -100000000;

    max_val = A * C;

    temp_val = A * D;
    //@ assert temp_val == ((A) * (D));
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = B * C;
    //@ assert temp_val == ((B) * (C));
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = B * D;
    //@ assert temp_val == ((B) * (D));
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
