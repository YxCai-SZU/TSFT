/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == a * b;
    ensures \result >= 1;
    ensures \result <= 10000;
*/
long func(long a, long b)
{
    long result;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert a * b >= 1;
    //@ assert a * b <= 10000;
    
    result = a * b;
    return result;
}
