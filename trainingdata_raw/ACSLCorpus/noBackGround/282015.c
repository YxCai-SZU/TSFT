#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
  requires a * b <= INT64_MAX && a * b >= INT64_MIN;
  ensures \result == a * b;
  assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= INT64_MAX;
    //@ assert a * b >= INT64_MIN;
    //@ assert ((a) * (b) <= 10000);
    
    int64_t answer = a * b;
    return answer;
}

/*@
  requires \valid(a) && \valid(b);
  ensures \result == (a[0] < b[0]);
  assigns \nothing;
*/
bool ord(const int64_t a[2], const int64_t b[2]) {
    bool result;
    if (a[0] < b[0]) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

/*@
  ensures \valid(\result + (0..2));
  ensures \result[0] == 1 && \result[1] == 10 && \result[2] == 3;
  assigns \result[0..2];
*/
int64_t* vector_example(void) {
    static int64_t vec[3];
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    
    vec[1] = 10;
    
    return vec;
}
