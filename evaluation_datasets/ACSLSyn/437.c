#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ===== Original functions (adapted with proper naming) ===== */

/* Function 1: compute weighted adjustment factor */
/*@
    predicate sorted_array(unsigned int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] < arr[j];

    lemma len_non_negative:
        \forall unsigned int *arr, integer len; len >= 0 ==> sorted_array(arr, len) ==> len >= 0;
*/

unsigned int compute_adjustment(unsigned int A, unsigned int P)
{
    unsigned int ret;
    //@ assert 0 <= A <= 100;
    //@ assert 0 <= P <= 100;
    ret = (A * 3 + P) / 2;
    //@ assert ret <= A * 3 + P;
    return ret;
}

size_t verify_vector_lenient(unsigned int *v, size_t len)
{
    size_t i = 0;
    size_t count = 0;
    
    while (i < len)
    {
        //@ assert i < len;
        count += 1;
        i += 1;
        //@ assert count == i;
    }
    //@ assert i == len;
    //@ assert count == len;
    return count;
}

/* Function 2: count missing sequential elements */
/*@ predicate valid_array(int *a, integer n) =
      n >= 0 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/


/*@ lemma loop_decreases:
      \forall integer n, integer idx; 0 <= idx <= n ==> n - idx >= 0;
*/

int count_missing_sequential(int *A, int N) {
    int count = 0;
    int num = 0;
    size_t index = 0;
    
    while (index < (size_t)N && num < N) {
        int ai = A[index];
        
        //@ assert 0 <= index < (size_t)N;
        //@ assert 1 <= ai <= 100;
        
        if (ai == num + 1) {
            num = num + 1;
        } else {
            count = count + 1;
        }
        index = index + 1;
        
        //@ assert count >= 0;
        //@ assert count <= (int)index;
        //@ assert 0 <= num <= N;
    }
    
    //@ assert count >= 0;
    //@ assert count <= N;
    return count;
}

/* Function 3: classify value range */
/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;
    
    logic integer classify_result(integer a) =
        a <= 5 ? 1 : 0;
*/

int classify_value(unsigned int a)
{
    int result = 0;
    unsigned int i = 1;
    
    while (i <= 10)
    {
        if (i == a)
        {
            if (a <= 5)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        i++;
    }
    
    return result;
}

/* Function 4: compare two 2D coordinates */
/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate c_in_range(integer c) = 1 <= c && c <= 100;
    predicate d_in_range(integer d) = 1 <= d && d <= 100;

    logic integer compare_result(integer a, integer b, integer c, integer d) =
        (a < c && b < d) ? 2 :
        (a > c && b > d) ? 0 :
        ((a == c && b <= d) || (a > c && b == d) || (a == c && b >= d) || (a < c && b == d)) ? 1 : 1;

    lemma result_range:
        \forall integer a, b, c, d;
        a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d) ==>
        0 <= compare_result(a, b, c, d) && compare_result(a, b, c, d) <= 2;
*/

size_t compare_2d_points(size_t a, size_t b, size_t c, size_t d)
{
    size_t result;

    //@ assert a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d);

    if (a < c && b < d)
    {
        //@ assert a < c && b < d;
        result = 2;
    }
    else if (a > c && b > d)
    {
        //@ assert a > c && b > d;
        result = 0;
    }
    else if ((a == c && b <= d) || (a > c && b == d))
    {
        //@ assert (a == c && b <= d) || (a > c && b == d);
        result = 1;
    }
    else
    {
        result = 1;
    }

    //@ assert result >= 0 && result <= 2;
    //@ assert (a < c && b < d) ==> result == 2;
    //@ assert (a > c && b > d) ==> result == 0;
    //@ assert ((a == c && b <= d) || (a > c && b == d)) ==> result == 1;
    //@ assert ((a == c && b >= d) || (a < c && b == d)) ==> result == 1;

    return result;
}

/* ===== Synthesized complex function: Packet routing decision with priority and sequence validation ===== */

size_t route_packet_with_priority(
    unsigned int *sorted_packet_ids, size_t num_packets,
    int *sequence_array, int seq_len,
    size_t coord_a, size_t coord_b, size_t coord_c, size_t coord_d,
    unsigned int priority_in, unsigned int load_in)
{
    size_t route_decision;
    int missing_count;
    unsigned int adjustment;
    int classification;
    
    //@ assert \valid_read(sorted_packet_ids + (0 .. num_packets-1));
    //@ assert sorted_array(sorted_packet_ids, num_packets);
    {
        size_t verified_len = verify_vector_lenient(sorted_packet_ids, num_packets);
        //@ assert verified_len == num_packets;
    }
    
    //@ assert valid_array(sequence_array, seq_len);
    missing_count = count_missing_sequential(sequence_array, seq_len);
    //@ assert missing_count >= 0 && missing_count <= seq_len;
    
    adjustment = compute_adjustment(priority_in, load_in);
    //@ assert adjustment <= priority_in * 3 + load_in;
    
    //@ assert 1 <= adjustment || adjustment == 0;
    if (adjustment >= 1 && adjustment <= 10) {
        classification = classify_value(adjustment);
        //@ assert classification == (adjustment <= 5 ? 1 : 0);
    } else {
        classification = 0;
    }
    
    {
        size_t base_route = compare_2d_points(coord_a, coord_b, coord_c, coord_d);
        //@ assert base_route >= 0 && base_route <= 2;
        
        if (classification == 1 && missing_count > 0) {
            route_decision = (base_route == 2) ? 1 : base_route;
        } else {
            route_decision = base_route;
        }
    }
    
    //@ assert route_decision >= 0 && route_decision <= 2;
    return route_decision;
}
