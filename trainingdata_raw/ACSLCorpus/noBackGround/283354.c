#include <stdint.h>

/*@ requires (0 < (n) <= 100 &&
      0 < (d) <= 100 &&
      0 < (s) <= 100);
    ensures \result == ((n) * (d));
    assigns \nothing;
*/
int32_t total_distance_before_collision(int32_t n, int32_t d, int32_t s) {
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert 0 < n && n <= 100;
    //@ assert 0 < d && d <= 100;
    //@ assert 0 < s && s <= 100;
    //@ assert n * d <= 10000;
    
    result = n * d;
    //@ assert result == ((n) * (d));
    return result;
}

int main() {
    return 0;
}
