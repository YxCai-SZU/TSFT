/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max;
    int sum;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    
    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) :         (c));
    //@ assert max >= 1 && max <= 100;
    
    sum = a + b + c;
    //@ assert sum >= 3 && sum <= 300;
    
    if (max * 2 <= sum) {
        //@ assert max * 2 <= sum;
        return 1;
    } else {
        //@ assert max * 2 > sum;
        return 2;
    }
}
