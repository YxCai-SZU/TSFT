/* ============================================================
   Real-world scenario: Time slot alignment verification system
   ============================================================
   Description: In a scheduling system, we need to verify if a 
   given time offset (a, b in minutes modulo 60) can be aligned 
   with a daily schedule. The system first checks if the total 
   available time slots (a + b) are sufficient for a task (c), 
   then validates that the task duration (n) is within allowed 
   limits, and finally checks if the time difference between 
   two clock readings is a multiple of a 6-minute scheduling 
   quantum.
   ============================================================ */

/* ============================================================
   Function 1: Check if time slots a and b are sufficient for task c
   ============================================================ */
/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 500;
    predicate b_in_range(integer b) = 1 <= b && b <= 500;
    predicate c_in_range(integer c) = 1 <= c && c <= 1000;
    predicate i_in_range(integer i, integer b) = 1 <= i && i <= b + 1;
    predicate s_equals_i_minus_1(integer s, integer i) = s == i - 1;
*/

int func1(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int s;
    unsigned int i;
    
    s = 0;
    i = 1;
    
    while (i <= b) {
        //@ assert s == i - 1;
        s += 1;
        i += 1;
    }
    
    //@ assert s == b;
    return (s + a >= c);
}

/* ============================================================
   Function 2: Validate task duration n is within allowed limits
   ============================================================ */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate loop_inv(integer n, integer i, integer result) =
        1 <= n && n <= 100 &&
        1 <= i && i <= n + 1 &&
        result >= 0 &&
        result < 1000000;
    predicate inner_inv(integer n, integer i, integer temp_result, integer result) =
        1 <= n && n <= 100 &&
        1 <= i && i <= n + 1 &&
        temp_result >= 0 &&
        temp_result < 2000000 &&
        result < 1000000;
    logic integer decreases_outer(integer n, integer i) = n - i + 1;
    lemma outer_decreases: \forall integer n, i; 1 <= n <= 100 && 1 <= i <= n + 1 ==> decreases_outer(n, i) >= 0;
    lemma inner_decreases: \forall integer temp_result; temp_result >= 1000000 ==> temp_result > temp_result - 1000000;
*/

int func2(unsigned int n) {
    int result = 0;
    unsigned int i = 1;
    
    
    while (i <= n) {
        int temp_result = result;
        
        while (temp_result >= 1000000) {
            //@ assert temp_result >= 1000000;
            temp_result -= 1000000;
        }
        
        result = temp_result;
        i++;
    }
    
    //@ assert result >= 0;
    //@ assert result < 1000000;
    return result;
}

/* ============================================================
   Function 3: Check if time difference is multiple of 6-minute quantum
   ============================================================ */
#include <stdbool.h>

/*@
    predicate diff_less_than_sixty(integer a, integer b, integer diff) =
        (a < b ==> diff == b - a) && (a >= b ==> diff == a - b) &&
        diff < 60;

    logic integer compute_diff(integer a, integer b) =
        a < b ? b - a : a - b;
*/

bool func3(unsigned long a, unsigned long b)
{
    unsigned long min_val;
    unsigned long max_val;
    unsigned long diff;

    min_val = a < b ? a : b;
    max_val = a > b ? a : b;
    diff = max_val - min_val;

    //@ assert diff == max_val - min_val;
    //@ assert diff < 60;

    return diff % 6 == 0;
}

/* ============================================================
   Synthesized function: verifyTimeSlotAlignment
   ============================================================
   High-level property: The system successfully verifies that a 
   complete time slot allocation (a, b, c, n, time1, time2) 
   satisfies all scheduling constraints when the function returns true.
   ============================================================ */

bool verifyTimeSlotAlignment(
    unsigned int a, unsigned int b, unsigned int c,
    unsigned int n,
    unsigned long time1, unsigned long time2
) {
    int sufficient = func1(a, b, c);
    
    int valid_duration = func2(n);
    
    bool aligned = func3(time1, time2);
    
    bool result = (sufficient != 0) && (valid_duration >= 0) && aligned;
    
    //@ assert result ==> (a + b >= c) && (valid_duration < 1000000) && ((time1 - time2) % 6 == 0);
    
    return result;
}
