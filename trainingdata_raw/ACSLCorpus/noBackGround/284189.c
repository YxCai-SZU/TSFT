/*@
    requires (0 <= (a) && (a) <= 1000000000 &&
        0 <= (b) && (b) <= 1000000000 &&
        0 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (k) <= (a) + (b) + (c) ? (a) - ((k) - (a) - (b)) :
        (a) - (c));
*/
long func(long a, long b, long c, long k) {
    long ans;
    long k_remaining;
    
    ans = 0;
    k_remaining = k;

    //@ assert ans == 0 && k_remaining == k;
    
    if (a >= k_remaining) {
        ans += k_remaining;
        k_remaining = 0;
        //@ assert ans == k && k_remaining == 0;
    } else {
        ans += a;
        k_remaining -= a;
        //@ assert ans == a && k_remaining == k - a;
    }

    //@ assert ans >= 0 && ans <= a;
    //@ assert k_remaining >= 0;
    
    if (b >= k_remaining) {
        k_remaining = 0;
        //@ assert k_remaining == 0;
    } else {
        k_remaining -= b;
        //@ assert k_remaining == k - a - b;
    }

    //@ assert k_remaining >= 0;
    
    if (c >= k_remaining) {
        ans -= k_remaining;
        k_remaining = 0;
        //@ assert ans == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (k) <= (a) + (b) + (c) ? (a) - ((k) - (a) - (b)) :         (a) - (c)) && k_remaining == 0;
    } else {
        ans -= c;
        k_remaining -= c;
        //@ assert ans == a - c && k_remaining == k - a - b - c;
    }

    //@ assert ans >= -c;
    //@ assert ans <= a;
    //@ assert ans == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (k) <= (a) + (b) + (c) ? (a) - ((k) - (a) - (b)) :         (a) - (c));
    
    return ans;
}
