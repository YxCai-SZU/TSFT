#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid(map1+(0..size-1)) && \valid(map2+(0..size-1));
    requires (\forall integer i; 0 <= i < (size) ==> \at((map1)[i], Here) == \at((map2)[i], Here));
    ensures (\forall integer i; 0 <= i < (size) ==> \at((map1)[i], Here) == \at((map2)[i], Here));
*/
void assertMapsAreEqual(int8_t *map1, int8_t *map2, uint32_t size) {
    //@ assert (\forall integer i; 0 <= i < (size) ==> \at((map1)[i], Here) == \at((map2)[i], Here));
}

int main() {
    return 0;
}
