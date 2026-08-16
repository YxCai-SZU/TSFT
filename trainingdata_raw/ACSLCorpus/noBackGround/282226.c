#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b && b < c && c < d && d < e;
    ensures \result == (k >= 0 || (b - a <= k && c - a <= k && d - a <= k && e - a <= k));
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist_a_b;
    long dist_a_c;
    long dist_a_d;
    long dist_a_e;
    long dist_b_c;
    long dist_b_d;
    long dist_b_e;
    long dist_c_d;
    long dist_c_e;
    long dist_d_e;
    long max_dist;

    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));

    if (a > b) {
        dist_a_b = a - b;
    } else {
        dist_a_b = b - a;
    }
    //@ assert dist_a_b == (((a) > (b)) ? ((a) - (b)) : ((b) - (a)));

    if (a > c) {
        dist_a_c = a - c;
    } else {
        dist_a_c = c - a;
    }
    //@ assert dist_a_c == (((a) > (c)) ? ((a) - (c)) : ((c) - (a)));

    if (a > d) {
        dist_a_d = a - d;
    } else {
        dist_a_d = d - a;
    }
    //@ assert dist_a_d == (((a) > (d)) ? ((a) - (d)) : ((d) - (a)));

    if (a > e) {
        dist_a_e = a - e;
    } else {
        dist_a_e = e - a;
    }
    //@ assert dist_a_e == (((a) > (e)) ? ((a) - (e)) : ((e) - (a)));

    if (b > c) {
        dist_b_c = b - c;
    } else {
        dist_b_c = c - b;
    }
    //@ assert dist_b_c == (((b) > (c)) ? ((b) - (c)) : ((c) - (b)));

    if (b > d) {
        dist_b_d = b - d;
    } else {
        dist_b_d = d - b;
    }
    //@ assert dist_b_d == (((b) > (d)) ? ((b) - (d)) : ((d) - (b)));

    if (b > e) {
        dist_b_e = b - e;
    } else {
        dist_b_e = e - b;
    }
    //@ assert dist_b_e == (((b) > (e)) ? ((b) - (e)) : ((e) - (b)));

    if (c > d) {
        dist_c_d = c - d;
    } else {
        dist_c_d = d - c;
    }
    //@ assert dist_c_d == (((c) > (d)) ? ((c) - (d)) : ((d) - (c)));

    if (c > e) {
        dist_c_e = c - e;
    } else {
        dist_c_e = e - c;
    }
    //@ assert dist_c_e == (((c) > (e)) ? ((c) - (e)) : ((e) - (c)));

    if (d > e) {
        dist_d_e = d - e;
    } else {
        dist_d_e = e - d;
    }
    //@ assert dist_d_e == (((d) > (e)) ? ((d) - (e)) : ((e) - (d)));

    max_dist = dist_a_b;

    if (max_dist < dist_a_c) {
        max_dist = dist_a_c;
    }

    if (max_dist < dist_a_d) {
        max_dist = dist_a_d;
    }

    if (max_dist < dist_a_e) {
        max_dist = dist_a_e;
    }

    if (max_dist < dist_b_c) {
        max_dist = dist_b_c;
    }

    if (max_dist < dist_b_d) {
        max_dist = dist_b_d;
    }

    if (max_dist < dist_b_e) {
        max_dist = dist_b_e;
    }

    if (max_dist < dist_c_d) {
        max_dist = dist_c_d;
    }

    if (max_dist < dist_c_e) {
        max_dist = dist_c_e;
    }

    if (max_dist < dist_d_e) {
        max_dist = dist_d_e;
    }

    //@ assert max_dist == e - a;
    //@ assert max_dist <= k ==> (b - a <= k && c - a <= k && d - a <= k && e - a <= k);
    
    return k >= 0 || max_dist <= k;
}
