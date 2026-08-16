#include <stdint.h>

struct Person {
    uint32_t id;
    uint8_t age;
};

/*@ predicate person_eq{L}(struct Person *m1, struct Person *m2) =
        m1->id == m2->id && m1->age == m2->age;
*/

/*@ lemma person_age_eq:
        \forall struct Person *m1, *m2;
        person_eq(m1, m2) ==> m1->id == m2->id && m1->age == m2->age;
*/

int main() {
    return 0;
}
