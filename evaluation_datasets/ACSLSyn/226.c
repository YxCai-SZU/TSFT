#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_in_range(integer x) = -40 <= x <= 40; */

bool check_temperature(int x) {
    return x >= 30;
}

/*@
    predicate valid_index(int i, integer len) =
        0 <= i && i < len;

    predicate valid_number(integer x) =
        1 <= x && x <= 13;

    predicate valid_array(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> valid_number(arr[i]);

    logic integer element_at(int *arr, integer i) = arr[i];
*/

bool check_sequence(int *arr, size_t len) {
    int a, b, c;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert valid_number(a);
    //@ assert valid_number(b);
    //@ assert valid_number(c);

    return (b == a + c);
}

/*@
    predicate valid_sensor_data(int *arr, integer len) =
        valid_array(arr, len) && \forall integer i; 0 <= i < len ==> is_in_range(arr[i]);

    logic integer temperature_sum(int *arr, integer len) =
        \sum(0, len-1, \lambda integer k; arr[k]);
*/

bool analyze_sensor_data(int *arr, size_t len) {
    bool seq_valid;
    bool temp_high1, temp_high2, temp_high3;
    bool any_temp_high;

    seq_valid = check_sequence(arr, len);

    temp_high1 = check_temperature(arr[0]);
    temp_high2 = check_temperature(arr[1]);
    temp_high3 = check_temperature(arr[2]);
    any_temp_high = temp_high1 || temp_high2 || temp_high3;

    //@ assert seq_valid == (element_at(arr, 1) == element_at(arr, 0) + element_at(arr, 2));
    //@ assert any_temp_high == (arr[0] >= 30 || arr[1] >= 30 || arr[2] >= 30);

    return seq_valid && any_temp_high;
}
