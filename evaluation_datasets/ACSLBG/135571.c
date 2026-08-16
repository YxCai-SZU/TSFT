#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_odd(integer x) = (x & 1) != 0; */


size_t filter_even(const int* numbers, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    
    while (i < len) {
        int x = numbers[i];
        //@ assert x == numbers[i];
        if ((x & 1) != 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

int main() {
    return 0;
}
