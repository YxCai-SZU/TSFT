#include <stdbool.h>

/* ACSL specifications from the first snippet */
/*@
    predicate distance_in_range(integer d) = 1 <= d && d <= 10000;
    predicate time_in_range(integer t) = 1 <= t && t <= 10000;
    predicate speed_in_range(integer s) = 1 <= s && s <= 10000;
    predicate no_overflow(integer t, integer s) = t * s <= 10000 * 10000;
*/
/*@
    logic integer compute_product(integer t, integer s) = t * s;
*/
/*@
    lemma overflow_lemma:
        \forall integer t, s;
            time_in_range(t) && speed_in_range(s) ==> no_overflow(t, s);
*/
bool func1(unsigned int d, unsigned int t, unsigned int s)
{
    unsigned int total_distance;
    unsigned int total_time;
    unsigned int speed;
    bool result;

    total_distance = d;
    total_time = t;
    speed = s;

    //@ assert distance_in_range(total_distance);
    //@ assert time_in_range(total_time);
    //@ assert speed_in_range(speed);
    //@ assert no_overflow(total_time, speed);

    result = (total_time * speed >= total_distance);
    return result;
}

/* ACSL specifications from the second snippet */
/*@ predicate is_positive(integer x) = x > 0;
    predicate is_zero(integer x) = x == 0;
    predicate condition_holds(integer a, integer b) = 
        is_positive(a) || is_positive(b) || (is_zero(a) && is_zero(b));
 */
bool func2(long a, long b)
{
    bool a_is_positive;
    bool b_is_positive;
    bool a_is_zero;
    bool b_is_zero;
    bool result;

    a_is_positive = a > 0;
    b_is_positive = b > 0;
    a_is_zero = a == 0;
    b_is_zero = b == 0;

    if (a_is_positive || b_is_positive || (a_is_zero && b_is_zero))
    {
        //@ assert condition_holds(a, b);
        result = true;
    }
    else
    {
        //@ assert !condition_holds(a, b);
        result = false;
    }

    return result;
}

/* ACSL specifications from the third snippet */
typedef enum {
    Open,
    Close
} FileStatus;

typedef struct {
    bool read;
    bool write;
    FileStatus status;
} Permission;

/*@ predicate permission_equal(Permission p1, Permission p2) =
    p1.read == p2.read &&
    p1.write == p2.write &&
    p1.status == p2.status;
*/

/*@
lemma file_status_example:
    \forall Permission p1, Permission p2;
    permission_equal(p1, p2) ==> p1.read == p2.read;
*/

/* Synthesized function: File transfer status checker
   Real-world scenario: A file transfer system that checks if a transfer can complete based on:
   - Distance, time, and speed constraints (func1)
   - File permission validity (func2 on permission values)
   - Permission structure consistency (func3 as a helper)
   
   Data flow:
   1. Validate that the transfer parameters (distance, time, speed) allow completion
   2. Check that the file permissions (read/write flags as long values) are valid
   3. Ensure the permission structure remains consistent after a hypothetical operation
   
   The final assertion verifies that when the transfer is feasible and permissions are valid,
   the permission structure maintains consistency.
*/

/*@
    predicate transfer_feasible(unsigned int d, unsigned int t, unsigned int s) =
        distance_in_range(d) && time_in_range(t) && speed_in_range(s) && (t * s >= d);
    
    predicate permission_valid(Permission p) =
        condition_holds((long)p.read, (long)p.write);
    
    predicate final_consistency(Permission p, unsigned int d, unsigned int t, unsigned int s) =
        (transfer_feasible(d, t, s) && permission_valid(p)) ==> permission_equal(p, p);
*/

bool synthesized_func(unsigned int d, unsigned int t, unsigned int s, Permission p) {
    bool transfer_ok;
    bool permission_ok;
    
    transfer_ok = func1(d, t, s);
    
    permission_ok = func2((long)p.read, (long)p.write);
    
    
    //@ assert final_consistency(p, d, t, s);
    
    return transfer_ok && permission_ok;
}
