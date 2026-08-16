#include <stddef.h>
#include <stdint.h>

/*@ predicate distances_valid(int64_t* arr, size_t len) =
      len >= 1 && len <= 100 &&
      \forall size_t i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ logic integer di_upper_bound(integer idx) = idx * 100; */

/*@ lemma di_non_negative:
      \forall integer di; di >= 0 ==> di + 1 >= 1;
*/

/*@ lemma count_bounds:
      \forall integer idx, cnt;
        0 <= idx && 1 <= cnt && cnt <= idx + 1 ==> cnt >= 1;
*/

/*@ requires
      1 <= n && n <= 100 &&
      1 <= x && x <= 10000 &&
      \valid(distances + (0 .. n-1)) &&
      distances_valid(distances, n);
    ensures
      \result >= 1 && \result <= n + 1;
    @*/
int32_t func(size_t n, int64_t x, int64_t* distances)
{
    int64_t di = 0;
    int32_t count = 1;
    size_t index = 0;

    /*@ loop invariant
          0 <= index <= n &&
          1 <= count <= index + 1 &&
          di >= 0 &&
          di <= di_upper_bound(index) &&
          distances_valid(distances, n);
      loop assigns di, count, index;
    @*/
    while (index < n && di <= x) {
        int64_t l = distances[index];
        di += l;
        //@ assert di >= l;
        if (di <= x) {
            count += 1;
        }
        index += 1;
    }
    //@ assert count >= 1;
    return count;
}
