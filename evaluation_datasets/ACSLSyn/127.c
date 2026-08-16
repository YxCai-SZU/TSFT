#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_array(int64_t* arr, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] <= 5 &&
    \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ predicate found_zero(int64_t* arr, integer len, integer idx) =
    0 <= idx < len && arr[idx] == 0;
*/

/*@ predicate no_zero_before(int64_t* arr, integer idx) =
    \forall integer k; 0 <= k < idx ==> arr[k] != 0;
*/

/*@ lemma zero_exists_in_array:
    \forall int64_t* arr, integer len;
    valid_array(arr, len) ==> \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ lemma array_length_five:
    \forall int64_t* arr, integer len;
    valid_array(arr, len) ==> len == 5;
*/

/*@ lemma values_in_range:
    \forall int64_t* arr, integer len, integer i;
    valid_array(arr, len) && 0 <= i < len ==> 0 <= arr[i] && arr[i] <= 5;
*/

struct OptionU64 {
    bool is_some;
    uint64_t value;
};

struct Rectangle {
    unsigned int width;
    unsigned int height;
};

/*@
    predicate is_square(struct Rectangle *r) = r->width == r->height;
    predicate is_valid_rectangle(struct Rectangle *r) = r->width >= 0 && r->height >= 0;
    predicate is_non_degenerate_rectangle(struct Rectangle *r) = r->width > 0 && r->height > 0;
*/

unsigned int area(const struct Rectangle *r) {
    //@ assert r->width > 0 && r->height > 0;
    return r->width * r->height;
}

struct OptionU64 func(int64_t* xs) {
    size_t index = 0;
    struct OptionU64 result;
    
    while (index < 5) {
        //@ assert 0 <= xs[index] && xs[index] <= 5;
        
        if (xs[index] == 0) {
            result.is_some = true;
            result.value = (uint64_t)index + 1;
            //@ assert found_zero(xs, 5, index);
            return result;
        }
        
        //@ assert xs[index] != 0;
        index++;
    }
    
    result.is_some = false;
    result.value = 0;
    //@ assert \forall integer i; 0 <= i < 5 ==> xs[i] != 0;
    return result;
}

struct OptionU64 process_data_and_rectangle(int64_t* xs, struct Rectangle* rect) {
    struct OptionU64 pos = func(xs);
    unsigned int a = area(rect);
    
    if (pos.is_some) {
        pos.value = pos.value + a;
    }
    
    //@ assert pos.is_some == true ==> (pos.value > a);
    //@ assert pos.is_some == false ==> (pos.value == 0);
    
    return pos;
}

int main() {
    return 0;
}
