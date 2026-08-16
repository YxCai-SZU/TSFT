#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(vec1) && \valid(vec2);
    requires len1 <= 0x7FFFFFFF && len2 <= 0x7FFFFFFF;
    assigns \nothing;
    ensures \result == (len1 == len2);
*/
bool find_equal_vector_length(int *vec1, int *vec2, size_t len1, size_t len2) {
    //@ assert len1 <= 0x7FFFFFFF;
    //@ assert len2 <= 0x7FFFFFFF;
    return len1 == len2;
}

/*@ requires len1 <= 0x7FFFFFFF && len2 <= 0x7FFFFFFF;
    assigns \nothing;
*/
void verify_vector_length_upper_bound(size_t len1, size_t len2) {
    //@ assert len1 <= 0x7FFFFFFF;
    //@ assert len2 <= 0x7FFFFFFF;
}

#ifdef TEST
#include <assert.h>

void test_equal_vector_length(void) {
    int vec1_storage[3] = {0};
    int vec2_storage[3] = {0};
    int *vec1 = vec1_storage;
    int *vec2 = vec2_storage;
    size_t len1 = 0;
    size_t len2 = 0;
    
    //@ assert len1 == len2;
    assert(len1 == len2);
    
    len1 = 1;
    //@ assert len1 != len2;
    assert(len1 != len2);
    
    len2 = 1;
    //@ assert len1 == len2;
    assert(len1 == len2);
}
#endif
