#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((count) < 0x80000000);
    ensures \result == (((integer)(length)) == (integer)count);
    assigns \nothing;
*/
bool contains_exact_count(int *arr, size_t length, size_t count) {
    // Variable declarations at top of scope
    bool result;

    //@ assert ((count) < 0x80000000);

    if (length == count) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (((integer)(length)) == (integer)count);
    return result;
}

#ifdef TEST
#include <assert.h>

int main() {
    int v1_arr[0] = {};
    int v2_arr[1] = {1};
    int v3_arr[2] = {1, 2};

    assert(contains_exact_count(v1_arr, 0, 0) == true);
    assert(contains_exact_count(v1_arr, 0, 1) == false);
    assert(contains_exact_count(v2_arr, 1, 0) == false);
    assert(contains_exact_count(v2_arr, 1, 1) == true);
    assert(contains_exact_count(v2_arr, 1, 2) == false);
    assert(contains_exact_count(v3_arr, 2, 0) == false);
    assert(contains_exact_count(v3_arr, 2, 1) == false);
    assert(contains_exact_count(v3_arr, 2, 2) == true);
    assert(contains_exact_count(v3_arr, 2, 3) == false);

    return 0;
}
#endif
