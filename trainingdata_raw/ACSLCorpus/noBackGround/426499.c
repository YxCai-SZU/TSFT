/*@
    requires (-100 <= (A) <= 100);
    requires (-100 <= (B) <= 100);
    requires (-100 <= (C) <= 100);
    ensures \result == 1 <==> ((C) >= (A) && (C) <= (B));
*/
_Bool func(int A, int B, int C)
{
    // Variable declarations at top of scope
    _Bool result;

    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (B) <= 100);
    //@ assert (-100 <= (C) <= 100);

    result = (C >= A && C <= B);
    return result;
}
