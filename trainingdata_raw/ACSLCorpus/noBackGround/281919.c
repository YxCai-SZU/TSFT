#include <limits.h>

/*@
    requires ((0 <= ((a)) <= 23 && 0 <= ((b)) <= 59) &&
        (0 <= ((c)) <= 23 && 0 <= ((d)) <= 59) &&
        0 <= (e) <= 100 &&
        (a) <= (c) &&
        ((a) == (c) ==> (b) <= (d)) &&
        (b) <= 100 &&
        (d) <= 100 &&
        (b) + (e) <= (d));
    ensures \result == d - (b + e);
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int train_in_tokyio;
    int taxi;
    int result;
    
    //@ assert (0 <= (a) <= 23 && 0 <= (b) <= 59);
    //@ assert (0 <= (c) <= 23 && 0 <= (d) <= 59);
    //@ assert 0 <= e <= 100;
    //@ assert a <= c;
    //@ assert (a == c && b <= d) || a < c;
    //@ assert b <= 100;
    //@ assert d <= 100;
    //@ assert b + e <= d;
    
    // Calculate train_in_tokyio
    if (a < c) {
        train_in_tokyio = c - a;
    } else {
        train_in_tokyio = c + 24 - a;
    }
    //@ assert train_in_tokyio == (a < c ? c - a : c + 24 - a);
    
    train_in_tokyio = train_in_tokyio * 60;
    //@ assert train_in_tokyio == (a < c ? c - a : c + 24 - a) * 60;
    
    if (b < d) {
        train_in_tokyio = train_in_tokyio + (d - b);
    } else {
        train_in_tokyio = train_in_tokyio + (d + 60 - b);
    }
    //@ assert train_in_tokyio == (((a) < (c) ? (c) - (a) : (c) + 24 - (a)) * 60 + ((b) < (d) ? (d) - (b) : (d) + 60 - (b)));
    
    // Calculate taxi
    taxi = e * 5;
    //@ assert taxi == ((e) * 5);
    
    // Calculate result
    if (train_in_tokyio < taxi) {
        result = train_in_tokyio;
    } else {
        result = taxi;
    }
    //@ assert result == (train_in_tokyio < taxi ? train_in_tokyio : taxi);
    
    // Proof assertions
    //@ assert result <= train_in_tokyio && result <= taxi;
    //@ assert result <= d - (b + e) || result <= taxi;
    
    //@ assert d - (b + e) >= 0;
    
    return d - (b + e);
}
