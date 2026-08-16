#include <stdint.h>
#include <stdbool.h>

struct HashMap {
    int32_t *keys;
    int16_t *values;
    int capacity;
    int size;
};

/*@
    predicate map_empty{L}(int32_t *keys, int16_t *values, integer size) =
        size == 0;
*/

/*@
    requires \valid(m);
    requires \valid(m->keys + (0 .. m->capacity-1));
    requires \valid(m->values + (0 .. m->capacity-1));
    requires map_empty(m->keys, m->values, m->size);
    ensures map_empty(m->keys, m->values, m->size);
*/
void ensure_empty_map(struct HashMap *m) {
    //@ ghost int32_t *old_keys = m->keys;
    //@ ghost int16_t *old_values = m->values;
    //@ ghost int old_size = m->size;
    
    //@ assert map_empty(old_keys, old_values, old_size);
    
    m->size = 0;
    
    //@ assert map_empty(m->keys, m->values, m->size);
}

int main() {
    return 0;
}
