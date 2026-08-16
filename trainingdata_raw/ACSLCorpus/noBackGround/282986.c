/*@
    requires \valid(result);
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    assigns *result;
    ensures *result >= 1 && *result <= 3;
    ensures (a == b && b == c) ==> *result == 1;
    ensures (a != b && b != c && a != c) ==> *result == 3;
*/
void func(int a, int b, int c, int *result)
{
    int cnt = 0;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a == b) {
        cnt += 1;
    }
    if (b == c) {
        cnt += 1;
    }
    if (c == a) {
        cnt += 1;
    }
    
    //@ assert cnt == (((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0));
    //@ assert 0 <= cnt <= 3;
    
    if (cnt == 3) {
        *result = 1;
        //@ assert *result == 1;
        return;
    } else if (cnt == 0) {
        *result = 3;
        //@ assert *result == 3;
        return;
    } else {
        //@ assert cnt == 1 || cnt == 2;
        *result = 2;
        //@ assert *result == 2;
        return;
    }
}
