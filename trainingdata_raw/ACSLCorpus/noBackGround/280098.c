/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && b != c) ==> \result == c;
    ensures (a == c && c != b) ==> \result == b;
    ensures (b == c && c != a) ==> \result == a;
    ensures (a != b && b != c && c != a) ==> \result == 0;
    ensures -100 <= \result <= 100;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    
    if (a == b && b != c) {
        ans = c;
    } else if (b == c && c != a) {
        ans = a;
    } else if (a == c && c != b) {
        ans = b;
    } else {
        ans = 0;
    }
    
    //@ assert ((-100 <= ((a)) <= 100) && (-100 <= ((b)) <= 100) && (-100 <= ((c)) <= 100));
    //@ assert ans == ((a) == (b) && (b) != (c) ? (c) :         (b) == (c) && (c) != (a) ? (a) :         (a) == (c) && (c) != (b) ? (b) :         0);
    //@ assert -100 <= ans <= 100;
    
    return ans;
}
