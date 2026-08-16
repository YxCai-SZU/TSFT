#include <stdbool.h>
#include <stdint.h>

enum Event {
    Marathon,
    Sprint,
    Relay
};

struct MarathonEvent {
    uint32_t time;
    char* location;
};

struct SprintEvent {
    uint32_t time;
    char* location;
};

struct RelayEvent {
    uint8_t team_size;
    uint32_t time;
};

union EventData {
    struct MarathonEvent marathon;
    struct SprintEvent sprint;
    struct RelayEvent relay;
};

struct EventWrapper {
    enum Event tag;
    union EventData data;
};

/*@
    predicate is_marathon(struct EventWrapper *e) = e->tag == Marathon;
    predicate team_size_ok(struct EventWrapper *e) = e->tag == Relay && e->data.relay.team_size == 4;
    logic integer marathon_time(struct EventWrapper *e) = e->tag == Marathon ? e->data.marathon.time : 0;
    logic integer sprint_time(struct EventWrapper *e) = e->tag == Sprint ? e->data.sprint.time : 0;
    logic integer relay_time(struct EventWrapper *e) = e->tag == Relay ? e->data.relay.time : 0;
*/

/*@
    lemma check_marathon:
        \forall struct EventWrapper *e; is_marathon(e) ==> e->tag != Sprint;
    lemma prove_marathon_time:
        \forall struct EventWrapper *e, integer t; 
            is_marathon(e) && t == marathon_time(e) && t > 7200 ==> marathon_time(e) > 7200;
*/

/*@
    requires e->tag == Marathon;
    ensures \result == true ==> e->data.marathon.time > 7200;
    ensures \result == false ==> e->data.marathon.time <= 7200;
*/
bool check_marathon_func(struct EventWrapper* e) {
    //@ assert e->tag == Marathon;
    //@ assert e->tag != Sprint;
    return e->data.marathon.time > 7200;
}

/*@
    requires e->tag == Marathon;
    requires time == e->data.marathon.time;
    requires time > 7200;
    ensures e->data.marathon.time > 7200;
*/
void prove_marathon_time_func(struct EventWrapper* e, uint32_t time) {
    //@ assert time > 7200;
    //@ assert e->data.marathon.time > 7200;
}

int main() {
    return 0;
}
