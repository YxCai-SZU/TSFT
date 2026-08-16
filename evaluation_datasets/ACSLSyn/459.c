#include <stdbool.h>
#include <stdint.h>

/* ========== Original functions (unchanged) ========== */

/* Function 1: func_check_range */
/*@
    predicate in_range(integer x) =
        (5 <= x && x <= 6) ||
        (10 <= x && x <= 11) ||
        (16 <= x && x <= 17) ||
        (21 <= x && x <= 22) ||
        (27 <= x && x <= 28);
*/

bool func_check_range(unsigned int x)
{
    //@ assert 1 <= x <= 100;
    
    if (x >= 5 && x <= 6) {
        //@ assert in_range(x);
        return true;
    } else if (x >= 10 && x <= 11) {
        //@ assert in_range(x);
        return true;
    } else if (x >= 16 && x <= 17) {
        //@ assert in_range(x);
        return true;
    } else if (x >= 21 && x <= 22) {
        //@ assert in_range(x);
        return true;
    } else if (x >= 27 && x <= 28) {
        //@ assert in_range(x);
        return true;
    }
    
    //@ assert !in_range(x);
    return false;
}

/* Function 2: func_compare_products */
/*@
    predicate valid_range_10000(integer v) = 1 <= v <= 10000;
    
    logic integer safe_product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer x, y; 
        valid_range_10000(x) && valid_range_10000(y) ==> 
        1 <= safe_product(x, y) <= 10000 * 10000;
*/

int func_compare_products(int a, int b, int c, int d)
{
    int product1;
    int product2;
    int result;
    
    //@ assert valid_range_10000(a);
    //@ assert valid_range_10000(b);
    //@ assert valid_range_10000(c);
    //@ assert valid_range_10000(d);
    
    //@ assert 1 <= safe_product(a, b) <= 10000 * 10000;
    product1 = a * b;
    
    //@ assert 1 <= safe_product(c, d) <= 10000 * 10000;
    product2 = c * d;
    
    //@ assert product1 >= product2 ==> safe_product(a, b) >= safe_product(c, d);
    result = (product1 >= product2);
    
    return result;
}

/* Function 3: func_process_product */
/*@
    predicate valid_range_100(integer a) = 1 <= a && a <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma overflow_bound: \forall integer a, b;
        valid_range_100(a) && valid_range_100(b) ==> product(a, b) <= 10000;
*/

int32_t func_process_product(uint32_t a, uint32_t b)
{
    uint32_t product;
    int32_t result;

    //@ assert valid_range_100(a) && valid_range_100(b);
    //@ assert product(a, b) <= 10000;

    product = a * b;
    result = -1;

    if (product < 1000000)
    {
        result = (int32_t)product + 1;
    }

    //@ assert result == -1 ==> product(a, b) >= 1000000;

    return result;
}

/* Function 4: func_verify_sequence */
/*@
    predicate is_valid_seq(integer len, int *arr) =
        len == 5 &&
        arr[0] == 0 &&
        arr[1] == 10 &&
        arr[2] == 21 &&
        arr[3] == 30 &&
        arr[4] == 40;

    logic integer seq_index(integer len, int *arr, integer i) =
        (i == 0) ? arr[0] :
        (i == 1) ? arr[1] :
        (i == 2) ? arr[2] :
        (i == 3) ? arr[3] :
        arr[4];

    logic integer seq_subrange(integer len, int *arr, integer i, integer j) =
        (i == 2 && j == 4) ? arr[2] + arr[3] * 1000 : 0;

    lemma seq_property:
        \forall integer len, int *arr;
        is_valid_seq(len, arr) ==> seq_index(len, arr, 2) == 21;

    lemma seq_subrange_property:
        \forall integer len, int *arr;
        is_valid_seq(len, arr) ==> seq_subrange(len, arr, 2, 4) == 21 + 30 * 1000;
*/

bool func_verify_sequence(int *v)
{
    int i = 0;
    while (i < 5)
    {
        i++;
    }

    //@ assert v[0] == 0 && v[1] == 10 && v[2] == 21 && v[3] == 30 && v[4] == 40;
    //@ assert v[0] == 0 && v[1] == 10;
    //@ assert v[2] == 21;
    //@ assert v[3] == 30;
    //@ assert v[2] == 21 && v[3] == 30;
    //@ assert seq_index(5, v, 2) == 21;
    //@ assert seq_index(5, v, 3) == 30;
    //@ assert seq_subrange(5, v, 2, 4) == 21 + 30 * 1000;

    return true;
}


/* ========== Synthesized complex function ========== */

/* 
 * Scenario: Packet processing in a network protocol.
 * Data flow:
 *   1. Extract a header field 'field' from a packet descriptor (represented by a sequence of 5 values).
 *   2. Compute two control integers from the field: a = field + 1, b = field / 3 + 1 (ensuring valid ranges).
 *   3. Process the product (a * b) to get a transformed value.
 *   4. Compare the processed result against a threshold computed from another pair (c, d) derived from the sequence.
 * The final assertion verifies that if the processed product is not saturated (-1), then it is consistent with the field range.
 */

int synthesize_packet_processing(int *v)
{
    bool seq_ok = func_verify_sequence(v);
    //@ assert seq_ok == true;
    //@ assert v[2] == 21;
    //@ assert v[3] == 30;

    bool in_special = func_check_range(v[2]);
    //@ assert in_special == true;  // v[2] == 21, which is in range

    uint32_t a = v[2] + 1;       // 22
    uint32_t b = v[3] / 3 + 1;   // 11
    int c = v[2];                // 21
    int d = v[3] / 2 + 1;        // 16

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;

    int32_t processed = func_process_product(a, b);
    //@ assert processed == 22*11 + 1;  // product=242 < 1000000, so result = 243

    int threshold = func_compare_products(c, d, 10, 100);
    //@ assert threshold == (safe_product(21,16) >= safe_product(10,100));  // 336 >= 1000 -> false (0)

    int result;
    if (processed != -1) {
        result = (int)processed + threshold;
    } else {
        result = -1;
    }

    //@ assert (processed != -1) ==> (processed == product((integer)v[2]+1, (integer)v[3]/3+1) + 1);

    return result;
}

int main()
{
    int arr[5] = {0, 10, 21, 30, 40};
    int res = synthesize_packet_processing(arr);
    return 0;
}
