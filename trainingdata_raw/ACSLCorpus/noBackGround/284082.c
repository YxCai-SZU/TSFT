#include <stdint.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100 &&
      1 <= (h) && (h) <= 100 &&
      (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    int64_t sum;
    int64_t result;
    int64_t temp_sum;
    int64_t count;
    
    //@ assert 2 <= a + b && a + b <= 200;
    //@ assert 2 <= (a + b) * h && (a + b) * h <= 20000;
    
    sum = (a + b) * h;
    result = 0;
    temp_sum = sum;
    count = 0;
    
    /*@ loop invariant 1 <= a && a <= 100;
      @ loop invariant 1 <= b && b <= 100;
      @ loop invariant 1 <= h && h <= 100;
      @ loop invariant h % 2 == 0;
      @ loop invariant sum == (a + b) * h;
      @ loop invariant 0 <= result;
      @ loop invariant 0 <= temp_sum;
      @ loop invariant sum == temp_sum + 2 * result;
      @ loop invariant 0 <= count && count <= (sum - temp_sum) / 2;
      @ loop assigns temp_sum, result, count;
      @ loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        result += 1;
        count += 1;
        //@ assert sum == temp_sum + 2 * result;
    }
    
    //@ assert result == (sum - temp_sum) / 2;
    //@ assert result == (((a) + (b)) * (h) / 2);
    return result;
}
