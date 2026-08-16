/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (C) && (C) <= 100 &&
        1 <= (D) && (D) <= 100);
    ensures \result >= 0;
    ensures \result <= A + B + C + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int ans = 0;
    int tmp1 = 0;
    int tmp2 = 0;

    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100 &&         1 <= (C) && (C) <= 100 &&         1 <= (D) && (D) <= 100);
    
    if (A > C) {
        tmp1 = A - C;
    } else {
        tmp1 = C - A;
    }
    //@ assert tmp1 == ((A) > (C) ? (A) - (C) : (C) - (A));
    
    ans += tmp1;
    //@ assert ans == ((A) > (C) ? (A) - (C) : (C) - (A));
    
    if (B > D) {
        tmp2 = B - D;
    } else {
        tmp2 = D - B;
    }
    //@ assert tmp2 == ((B) > (D) ? (B) - (D) : (D) - (B));
    
    ans += tmp2;
    //@ assert ans == ((A) > (C) ? (A) - (C) : (C) - (A)) + ((B) > (D) ? (B) - (D) : (D) - (B));
    
    //@ assert ans >= 0;
    //@ assert ans <= A + B + C + D;
    
    return ans;
}
