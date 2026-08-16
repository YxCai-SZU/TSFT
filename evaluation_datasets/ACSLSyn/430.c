#include <stdbool.h>

/*@
    predicate max_m_is_m_or_zero(integer m, integer max_m) =
        max_m == m || max_m == 0;
*/
bool func1(int n, int m) {
    int max_m;
    if (m > 0) {
        max_m = m;
    } else {
        max_m = 0;
    }
    //@ assert max_m_is_m_or_zero(m, max_m);
    return n == max_m;
}

/*@ predicate is_valid_order(integer a, integer b, integer c) =
      a < b && b < c;
*/
bool func2(int a, int b, int c) {
    bool is_valid;
    is_valid = true;
    //@ assert is_valid == true;
    is_valid = is_valid && (a < b);
    //@ assert is_valid == (a < b);
    is_valid = is_valid && (b < c);
    //@ assert is_valid == (a < b && b < c);
    return is_valid;
}

/*@
    predicate is_max(integer m, integer a, integer b, integer c, integer d, integer e) =
        m == a || m == b || m == c || m == d || m == e;
*/
bool func3(int a, int b, int c, int d, int e, int k) {
    int max = a;
    //@ assert is_max(max, a, b, c, d, e);
    if (b > max) {
        max = b;
        //@ assert is_max(max, a, b, c, d, e);
    }
    if (c > max) {
        max = c;
        //@ assert is_max(max, a, b, c, d, e);
    }
    if (d > max) {
        max = d;
        //@ assert is_max(max, a, b, c, d, e);
    }
    if (e > max) {
        max = e;
        //@ assert is_max(max, a, b, c, d, e);
    }
    //@ assert is_max(max, a, b, c, d, e);
    return k >= max;
}

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
    predicate all_unique(int *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];
    predicate exists_duplicate(int *s, integer len) =
        \exists integer i, j; 0 <= i < j < len && s[i] == s[j];
    predicate has_duplicates(int *s, integer len) = exists_duplicate(s, len);
*/
int func4(int a, int b) {
    int result;
    //@ assert a * b <= 100 * 100;
    //@ assert a * b >= 1 * 1;
    result = a * b;
    return result;
}

/*@
    predicate packet_valid(integer n, integer m, integer a, integer b, integer c,
                           integer a2, integer b2, integer c2, integer d2, integer e2, integer k,
                           integer p1, integer p2) =
        (n == m || n == 0) && (a < b && b < c) && 
        (k >= a2 && k >= b2 && k >= c2 && k >= d2 && k >= e2) &&
        p1 >= 1 && p1 <= 100 && p2 >= 1 && p2 <= 100;
*/

bool validate_packet(int n, int m, int a, int b, int c,
                     int a2, int b2, int c2, int d2, int e2, int k,
                     int p1, int p2) {
    bool valid = true;
    
    bool id_check = func1(n, m);
    valid = valid && id_check;
    
    bool order_check = func2(a, b, c);
    valid = valid && order_check;
    
    bool priority_check = func3(a2, b2, c2, d2, e2, k);
    valid = valid && priority_check;
    
    int payload_size = func4(p1, p2);
    //@ assert payload_size == p1 * p2;
    valid = valid && (payload_size >= 1 && payload_size <= 10000);
    
    return valid;
}
