/*@
    requires (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000) && (-1000 <= (c) && (c) <= 1000) && (-1000 <= (d) && (d) <= 1000);
    ensures ((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d));
    ensures ((\result) >= (a) || (\result) >= (b) || (\result) >= (c) || (\result) >= (d));
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    //@ assert (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000) && (-1000 <= (c) && (c) <= 1000) && (-1000 <= (d) && (d) <= 1000);
    
    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    
    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    
    if (max_ab > max_cd) {
        res = max_ab;
    } else {
        res = max_cd;
    }
    
    //@ assert ((res) == (a) || (res) == (b) || (res) == (c) || (res) == (d));
    //@ assert ((res) >= (a) || (res) >= (b) || (res) >= (c) || (res) >= (d));
    
    return res;
}
