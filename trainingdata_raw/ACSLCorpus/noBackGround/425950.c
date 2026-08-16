#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@
  requires 0 <= len && \valid_read(haystack+(0..len-1));
  ensures \result == 1 <==> (\exists integer i; 0 <= i < (len) && (haystack)[i] == (needle));
*/
bool contains_value(const uint32_t *haystack, size_t len, uint32_t needle)
{
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant (\forall integer j; 0 <= j < (i) ==> (haystack)[j] != (needle));
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (haystack[i] == needle) {
            //@ assert (\exists integer i; 0 <= i < (len) && (haystack)[i] == (needle));
            return true;
        }
        i++;
    }
    //@ assert !(\exists integer i; 0 <= i < (len) && (haystack)[i] == (needle));
    return false;
}

/*@
  requires \valid(map + (0..(*size)*2+1)) && \valid(size) &&
           0 <= *size < SIZE_MAX/2;
  ensures (\exists integer i; (map)[i*2] == (3) && (map)[i*2+1] == (6));
*/
void insert_and_check(uint32_t *map, size_t *size)
{
    map[*size * 2] = 3;
    map[*size * 2 + 1] = 6;
    (*size)++;
    
    //@ assert (\exists integer i; (map)[i*2] == (3) && (map)[i*2+1] == (6));
}

int main() {
    return 0;
}
