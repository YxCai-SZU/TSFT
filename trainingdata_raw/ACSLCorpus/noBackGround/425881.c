/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    requires 1 <= c && c <= 10;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && a != c) || (a == c && a != b) || (b == c && a != b));
    ensures \result == 3 ==> (a != b && b != c && a != c);
*/
int func(int a, int b, int c)
{
    int num = 0;

    //@ assert (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    
    if (a == b) {
        num += 1;
    }
    if (b == c) {
        num += 1;
    }
    if (a == c) {
        num += 1;
    }

    //@ assert 0 <= num && num <= 3;
    
    if (num == 0) {
        //@ assert num == 0;
        return 3;
    } else if (num == 1 || num == 2) {
        //@ assert num == 1 || num == 2;
        return 2;
    } else if (num == 2 || num == 3) {
        //@ assert num == 2 || num == 3;
        return 1;
    } else {
        return 0;
    }
}
