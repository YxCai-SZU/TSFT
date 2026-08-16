#include <limits.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires 1 <= k <= a + b + c <= 2000000000;
    ensures \result <= a;
    ensures \result >= -c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int a_cnt;
    int k_remaining;
    int b_cnt;
    int c_cnt;
    
    //@ assert ((a) >= 0) && ((b) >= 0) && ((c) >= 0);
    //@ assert (1 <= (k) <= (a) + (b) + (c) <= 2000000000);
    
    a_cnt = a < k ? a : k;
    //@ assert a_cnt == ((a) < (k) ? (a) : (k));
    //@ assert 0 <= a_cnt <= a;
    
    k_remaining = k - a_cnt;
    //@ assert k_remaining >= 0;
    
    b_cnt = b < k_remaining ? b : k_remaining;
    //@ assert b_cnt == ((b) < (k_remaining) ? (b) : (k_remaining));
    //@ assert 0 <= b_cnt <= b;
    
    k_remaining -= b_cnt;
    //@ assert k_remaining >= 0;
    
    c_cnt = c < k_remaining ? c : k_remaining;
    //@ assert c_cnt == ((c) < (k_remaining) ? (c) : (k_remaining));
    //@ assert 0 <= c_cnt <= c;
    
    //@ assert a_cnt - c_cnt <= a;
    //@ assert a_cnt - c_cnt >= -c;
    
    return a_cnt - c_cnt;
}
