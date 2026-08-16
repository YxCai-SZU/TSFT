#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/* ==================== Original Functions (adapted) ==================== */

/* --- Function 1: checks if c is between a and b --- */
/*@
    predicate are_distinct(integer a, integer b, integer c) =
        a != b && b != c && a != c;

    predicate in_range(integer x) =
        0 <= x && x <= 100;

    predicate is_between(integer a, integer b, integer c) =
        (a <= c && c <= b) || (b <= c && c <= a);
*/

bool between_func(int a, int b, int c)
{
    bool result;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;

    result = (a <= c && c <= b) || (b <= c && c <= a);
    return result;
}

/* --- Function 2: checks a property on digits of n --- */
/*@
    predicate in_range_n(integer n) =
        1 <= n && n <= 1000000000;

    logic integer ones(integer n) = n % 100;
    logic integer tens(integer n) = n % 200;

    predicate result_condition(integer n) =
        (ones(n) <= 5 && ones(n) >= 0) || tens(n) >= 105;
*/

bool digit_prop_func(unsigned long n)
{
    unsigned long ones;
    unsigned long tens;
    bool ret;

    ones = n % 100;
    tens = n % 200;

    //@ assert ones == n % 100;
    //@ assert tens == n % 200;

    ret = (ones <= 5 && ones >= 0) || tens >= 105;
    return ret;
}

/* --- Function 3: checks if range of sorted array <= k --- */
/*@ predicate is_valid_range(int* a, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 0 <= a[i] <= 123 &&
    a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4];
*/

/*@ predicate min_bound(int* a, integer len, integer i, int min_val) =
    \forall integer j; 0 <= j < i ==> min_val <= a[j];
*/

/*@ predicate max_bound(int* a, integer len, integer i, int max_val) =
    \forall integer j; 0 <= j < i ==> max_val >= a[j];
*/

/*@ predicate min_exists(int* a, integer len, integer i, int min_val) =
    \exists integer j; 0 <= j < i && min_val == a[j];
*/

/*@ predicate max_exists(int* a, integer len, integer i, int max_val) =
    \exists integer j; 0 <= j < i && max_val == a[j];
*/

/*@ lemma monotonic_property:
    \forall int* a, integer len;
    is_valid_range(a, len) ==>
    \forall integer i; 0 <= i < len-1 ==> a[i] < a[i+1];
*/

bool range_check_func(int* a, int k) {
    int min_val;
    int max_val;
    int i;
    
    min_val = a[0];
    max_val = a[0];
    i = 1;
    
    while (i < 5) {
        //@ assert is_valid_range(a, 5);
        
        if (a[i] < min_val) {
            min_val = a[i];
        }
        
        //@ assert min_bound(a, 5, i+1, min_val);
        
        if (a[i] > max_val) {
            max_val = a[i];
        }
        
        //@ assert max_bound(a, 5, i+1, max_val);
        
        i = i + 1;
    }
    
    //@ assert min_val == a[0];
    //@ assert max_val == a[4];
    
    if (max_val - min_val > k) {
        return false;
    } else {
        return true;
    }
}

/* --- Function 4: right shift a uint64_t --- */
/*@
    predicate is_less_than_max(uint64_t a) = a < 18446744073709551616ULL;

    logic integer shift_right(integer a) = a / 2;

    lemma shift_equals_division: \forall integer a; a >= 0 ==> shift_right(a) == a / 2;
*/

uint64_t shift_func(uint64_t a)
{
    //@ assert a < 18446744073709551616ULL;
    uint64_t result = a >> 1;
    //@ assert result == shift_right(a);
    return result;
}


/* ==================== Synthesized Complex Function ==================== */

bool packet_filter(int source_ip, int dest_ip, int threshold, 
                   unsigned long packet_id, int* payload, int k,
                   uint64_t timestamp)
{
    bool check1, check2, check3;
    uint64_t shifted_ts;
    
    check1 = between_func(source_ip, dest_ip, threshold);
    //@ assert check1 == ((source_ip <= threshold && threshold <= dest_ip) || (dest_ip <= threshold && threshold <= source_ip));
    
    check2 = digit_prop_func(packet_id);
    //@ assert check2 == ((packet_id % 100 <= 5 && packet_id % 100 >= 0) || (packet_id % 200 >= 105));
    
    check3 = range_check_func(payload, k);
    //@ assert check3 == true <==> (payload[4] - payload[0] <= k);
    
    shifted_ts = shift_func(timestamp);
    //@ assert shifted_ts == shift_right(timestamp);
    
    bool result = check1 && check2 && check3;
    
    //@ assert result ==> (check2 && shifted_ts == timestamp / 2);
    
    return result;
}
