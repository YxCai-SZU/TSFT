/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
int func(int a, int b, int c, int d)
{
    int sa, sb, sc, sd;
    int min_ab, min_cd;
    int s;
    
    sa = a;
    sb = b;
    sc = c;
    sd = d;
    
    //@ assert sa == a && sb == b && sc == c && sd == d;
    
    if (sa > sb)
    {
        sa = b;
        sb = a;
    }
    
    if (sc > sd)
    {
        sc = d;
        sd = c;
    }
    
    //@ assert sa == ((a) <= (b) ? (a) : (b)) && sb == (a <= b ? b : a);
    //@ assert sc == ((c) <= (d) ? (c) : (d)) && sd == (c <= d ? d : c);
    
    if (sa < sc)
    {
        min_ab = sa;
        min_cd = sc;
    }
    else
    {
        min_ab = sc;
        min_cd = sa;
    }
    
    //@ assert min_ab == ((sa) <= (sc) ? (sa) : (sc));
    //@ assert min_cd == (sa <= sc ? sc : sa);
    
    s = min_ab + min_cd;
    
    //@ assert min_ab == a || min_ab == b || min_ab == c || min_ab == d;
    //@ assert min_cd == a || min_cd == b || min_cd == c || min_cd == d;
    
    return s;
}
