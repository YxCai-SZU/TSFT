/*@
    requires ((a) <= (b) && (b) <= (c) && (c) <= (d));
    ensures \result == ((a) <= (c) && (b) >= (d) ? (d) - (a) :
        (a) > (c) && (b) >= (d) ? (b) - (c) :
        (a) <= (c) && (b) < (d) ? (b) - (a) :
        (d) - (c));
    ensures \result <= d - a;
*/
int compute_func(int a, int b, int c, int d)
{
    int result;
    
    //@ assert ((a) <= (b) && (b) <= (c) && (c) <= (d));
    
    if (a <= c && b >= d) {
        result = d - a;
        //@ assert result == d - a;
    } else if (a > c && b >= d) {
        result = b - c;
        //@ assert result == b - c;
    } else if (a <= c && b < d) {
        result = b - a;
        //@ assert result == b - a;
    } else {
        result = d - c;
        //@ assert result == d - c;
    }
    
    //@ assert result <= d - a;
    return result;
}

int main()
{
    return 0;
}
