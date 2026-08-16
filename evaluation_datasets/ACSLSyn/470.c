#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

/* ===================== Original first function ===================== */

/*@
    predicate valid_array(int32_t* arr, integer len) =
        len >= 1 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;
*/

int32_t func_range(int32_t* a, uint32_t len) {
    int32_t max_value = a[0];
    int32_t min_value = a[0];
    uint32_t i = 1;

    while (i < len) {
        //@ assert 1 <= a[i] <= 100;

        if (a[i] > max_value) {
            max_value = a[i];
        }
        //@ assert max_value >= min_value;

        if (a[i] < min_value) {
            min_value = a[i];
        }
        //@ assert min_value <= max_value;

        i++;
    }

    int32_t diff = max_value - min_value;
    //@ assert diff >= 0;
    int32_t ans = diff / 2;

    if (diff % 2 == 1) {
        ans++;
    }
    //@ assert 0 <= ans <= 100;
    return ans;
}

/* ===================== Original second function ===================== */

/*@
    predicate all_even{L}(unsigned int *s, size_t len) =
        \forall size_t i; 0 <= i < len ==> s[i] % 2 == 0;

    predicate all_greater_than_threshold{L}(unsigned int *s, size_t len, unsigned int threshold) =
        \forall size_t i; 0 <= i < len ==> s[i] > threshold;
*/

bool func_check(unsigned int *v, size_t len, unsigned int threshold)
{
    size_t i = 0;
    
    while (i < len)
    {
        //@ assert v[i] > threshold;
        i++;
    }
    
    return true;
}

/* ===================== Synthesized high-level function ===================== */

/*@
    predicate valid_sensor_data(int32_t* arr, integer len) =
        valid_array(arr, len);

    predicate valid_control_signal(unsigned int *v, size_t len, unsigned int threshold) =
        all_even(v, len) && all_greater_than_threshold(v, len, threshold);
*/

int process_sensor_and_control(
    int32_t* arr, uint32_t len1,
    unsigned int* v, size_t len2,
    unsigned int threshold
)
{
    int32_t range_metric = func_range(arr, len1);
    
    bool signal_ok = func_check(v, len2, threshold);
    
    //@ assert 0 <= range_metric <= 100 && signal_ok == true;
    
    return 1;
}
