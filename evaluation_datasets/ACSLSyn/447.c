#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/* Original function 1: Event validation */
struct Event {
    int tag; // 0:Marathon, 1:Sprint, 2:Relay
    unsigned int time;
    char* location;
    unsigned char team_size;
};

/*@
    predicate is_valid_event_pre(integer tag, integer time) =
        (tag == 0 && time > 7200) ||
        (tag == 2 && time < 3600) ||
        (tag == 1 && time < 60);
*/

bool is_valid_event(struct Event e) {
    bool result;
    
    if (e.tag == 0) {
        result = (e.time > 7200);
    } else if (e.tag == 2) {
        result = (e.time < 3600);
    } else if (e.tag == 1) {
        result = (e.time < 60);
    } else {
        result = false;
    }
    
    //@ assert result == true;
    return result;
}

/* Original function 2: Compute target value */
/*@
    predicate valid_range_n(integer n) = 1 <= n <= 1000000;
    logic integer target(integer n) = (n / 2) + (n % 2);
*/

uint64_t compute_target(uint64_t n)
{
    uint64_t count;
    uint64_t half;
    uint64_t is_odd;
    uint64_t return_value;

    if (n == 1) {
        return 1;
    }

    count = 0;
    half = n / 2;
    is_odd = n % 2;

    while (half >= 1) {
        half -= 1;
        count += 1;
    }

    return_value = count + is_odd;
    //@ assert return_value == target(n);
    return return_value;
}

/* Original function 3: Validate arrays */
/*@
    predicate all_even{L}(uint32_t *s, integer len) =
        \forall integer i; 0 <= i < len ==> (s[i] % 2 == 0);
    
    predicate no_evens{L}(uint32_t *s, integer len) =
        \forall integer i; 0 <= i < len ==> (s[i] % 2 != 0);
    
    predicate all_greater_than_5{L}(uint32_t *s, integer len) =
        \forall integer i; 0 <= i < len ==> s[i] > 5;
    
    predicate all_less_than_50{L}(uint32_t *s, integer len) =
        \forall integer i; 0 <= i < len ==> s[i] < 50;
*/

int64_t range_count(int64_t n, int64_t k) {
    int64_t ans;
    ans = n - k + 1;
    return ans;
}

void validate_arrays(uint32_t *v, uint32_t *v2, uint32_t *v3, uint32_t *v4) {
    //@ assert all_even(v, 4);
}

/* Original function 4: Triangle type check */
/*@
    predicate valid_range_x(integer x) = 1 <= x <= 100;
    logic integer func_spec(integer a, integer b, integer c) =
        b == a + c ? 1 :
        (a == b + c || c == a + b) ? 2 : -1;
*/

int32_t check_triangle(uint32_t a, uint32_t b, uint32_t c) {
    int32_t result;
    
    if (b == a + c) {
        result = 1;
    } else if (a == b + c || c == a + b) {
        result = 2;
    } else {
        result = -1;
    }
    
    //@ assert result >= -1 && result <= 2;
    //@ assert result == 1 || result == 2 || result == -1;
    return result;
}

/* Synthesized function: Sports event data processing system */
int32_t process_race_data(struct Event e, uint64_t n, 
                          uint32_t *v, uint32_t *v2, uint32_t *v3, uint32_t *v4,
                          uint32_t a, uint32_t b, uint32_t c) {
    bool event_valid = is_valid_event(e);
    
    uint64_t metric = compute_target(n);
    
    validate_arrays(v, v2, v3, v4);
    
    int32_t triangle_result = check_triangle(a, b, c);
    
    return triangle_result;
}
