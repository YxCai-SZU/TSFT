#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_size(size_t s) = s < 0x80000000; */

bool contains_exact_count(const int *arr, size_t arr_len, size_t count) {
    //@ assert is_valid_size(arr_len);
    //@ assert is_valid_size(count);
    if (arr_len == count) {
        return true;
    } else {
        return false;
    }
}

int func(int n, int m) {
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    return (n - 1) * (m - 1);
}

bool process_grid_and_check_size(int n, int m, const int *arr) {
    int grid_size = func(n, m);
    //@ assert grid_size == (n - 1) * (m - 1);
    //@ assert grid_size >= 1 && grid_size <= 99 * 99;
    //@ assert is_valid_size((size_t)grid_size);
    
    bool result = contains_exact_count(arr, (size_t)grid_size, (size_t)grid_size);
    //@ assert result == ((size_t)grid_size == (size_t)grid_size);
    //@ assert result == true;
    
    return result;
}
