#include <stdint.h>

struct Averager {
    uint32_t sum;
    uint32_t count;
};

/*@
    requires \valid(a);
    assigns *a;
    ensures a->sum == 0;
    ensures a->count == 0;
    ensures ((*a).sum >= 0 && (*a).count >= 0);
*/
void Averager_new(struct Averager *a) {
    a->sum = 0;
    a->count = 0;
    //@ assert ((*a).sum >= 0 && (*a).count >= 0);
}

/*@
    requires \valid(a);
    requires ((*a).sum >= 0 && (*a).count >= 0);
    ensures \result == ((*a).count == 0 ? 0 : (*a).sum / (*a).count);
*/
uint32_t average(struct Averager *a) {
    if (a->count == 0) {
        return 0;
    } else {
        return a->sum / a->count;
    }
}

void test() {
    struct Averager avg;
    Averager_new(&avg);
    //@ assert ((avg).count == 0 ? 0 : (avg).sum / (avg).count) == 0;
}
