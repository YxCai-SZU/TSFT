
int func(int n, int m)
{
    int res;
    //@ assert (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    
    if (n > 9 || m > 9) {
        res = -1;
        //@ assert (n > 9 || m > 9) ==> res == -1;
    } else {
        //@ assert n >= 1 && n <= 9;
        //@ assert m >= 1 && m <= 9;
        //@ assert n * m <= 81;
        res = n * m;
        //@ assert (n <= 9 && m <= 9) ==> res == n * m;
    }
    
    //@ assert (((n) > 9 || (m) > 9) ==> (res) == -1 &&         ((n) <= 9 && (m) <= 9) ==> (res) == (n) * (m));
    return res;
}
