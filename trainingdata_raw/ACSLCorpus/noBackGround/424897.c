/*@
    requires 0 < A && A < 180;
    requires 0 < B && B < 180;
    requires 0 < C && C < 180;
    requires A + B + C == 180;
    ensures \result == 1;
    ensures ((A) > 0 && (B) > 0 && (C) > 0 &&
        (A) + (B) + (C) == 180 &&
        (A) <= 180 && (B) <= 180 && (C) <= 180);
*/
int main_isolation(int A, int B, int C)
{
    //@ assert 0 < A && A < 180;
    //@ assert 0 < B && B < 180;
    //@ assert 0 < C && C < 180;
    //@ assert A + B + C == 180;
    return 1;
}
