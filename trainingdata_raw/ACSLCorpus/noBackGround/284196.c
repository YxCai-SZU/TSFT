/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    requires a <= b && c <= d;
    ensures \result == (\max(\max((a)*(c), (a)*(d)), \max((b)*(c), (b)*(d))));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max1;
    long max2;
    long result;
    
    //@ assert a*c <= 100000000;
    
    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }
    
    //@ assert max1 == \max(a*c, a*d);
    
    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }
    
    //@ assert max2 == \max(b*c, b*d);
    
    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }
    
    //@ assert result == (\max(\max((a)*(c), (a)*(d)), \max((b)*(c), (b)*(d))));
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
