#include <stdbool.h>
#include <stddef.h>

struct Point {
    int x;
    int y;
};

/*@ predicate is_equal(struct Point p1, struct Point p2) =
      p1.x == p2.x && p1.y == p2.y;
*/

/*@ logic integer hash_key(struct Point p) = p.x * 31 + p.y; */

/*@ lemma hash_axiom:
      \forall struct Point p1, p2;
        is_equal(p1, p2) ==> hash_key(p1) == hash_key(p2);
*/

struct HashMap {
    struct Point* keys;
    unsigned int* values;
    size_t capacity;
    size_t size;
};

/*@ predicate valid_map(struct HashMap* m) =
      m != 0 &&
      \valid(m) &&
      (m->keys == 0 || \valid(m->keys + (0 .. m->capacity-1))) &&
      (m->values == 0 || \valid(m->values + (0 .. m->capacity-1))) &&
      m->size <= m->capacity;
*/

/*@ logic integer map_len(struct HashMap* m) = m->size; */

/*@ requires valid_map(m);
    requires \forall struct Point p1, p2;
               is_equal(p1, p2) ==> hash_key(p1) == hash_key(p2);
    ensures map_len(m) == 0;
    assigns m->size;
*/
void points_maplen(struct HashMap* m) {
    //@ assert valid_map(m);
    m->size = 0;
    //@ assert map_len(m) == 0;
}
