/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    ensures \result == A + B || \result == A - B || \result == A * B;
    ensures \result >= A + B && \result >= A - B && \result >= A * B;
*/
int func(int A, int B)
{
    int sum;
    int diff;
    int prod;
    int result;
    
    //@ assert -100 <= A <= 100 && -100 <= B <= 100;
    
    sum = A + B;
    diff = A - B;
    
    //@ assert -10000 <= A * B <= 10000;
    prod = A * B;
    
    if (sum > diff && sum > prod) {
        result = sum;
    } else if (diff > prod) {
        result = diff;
    } else {
        result = prod;
    }
    
    //@ assert result == (((sum) >= (diff) && (sum) >= (prod)) ? (sum) : (((diff) >= (prod)) ? (diff) : (prod)));
    //@ assert result >= sum && result >= diff && result >= prod;
    
    return result;
}
