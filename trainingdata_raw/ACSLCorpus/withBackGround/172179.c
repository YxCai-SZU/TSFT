#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@
    predicate is_empty_map(uint32_t *keys, uint32_t *values, size_t size) =
        size == 0;
*/

/*@
    lemma clear_map_lemma:
        \forall uint32_t *keys, *values, size_t size;
        is_empty_map(keys, values, size) ==> size == 0;
*/

/*@
    requires \valid(size) && *size >= 0 && *size <= capacity;
    requires \valid(keys + (0 .. capacity-1));
    requires \valid(values + (0 .. capacity-1));
    ensures *size == 0;
    assigns *size;
*/
void clear_map(uint32_t* keys, uint32_t* values, size_t* size, size_t capacity)
{
    // Variable declarations
    size_t old_size = *size;
    
    // Clear the map by setting size to 0
    *size = 0;
    
    //@ assert *size == 0;
}
