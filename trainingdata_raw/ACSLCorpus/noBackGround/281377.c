#include <stdbool.h>

typedef struct {
    int tag;
    union {
        unsigned int attendees;
        unsigned int tickets_sold;
    } data;
} Event;

/*@
    requires \valid(e);
    assigns e->tag, e->data.attendees;
    ensures ((e->tag) == 0 && (e->data.attendees) > 5000);
    ensures ((e->tag) == 0 ? (e->data.attendees) :
        (e->tag) == 1 ? (e->data.attendees) :
        (e->data.tickets_sold)) == 8000;
*/
void test_event(Event *e) {
    //@ ghost int tag = 0;
    //@ ghost unsigned int attendees = 8000;
    //@ ghost unsigned int tickets_sold = 0;
    
    e->tag = 0;
    e->data.attendees = 8000;
    
    //@ assert ((tag) == 0 && (attendees) > 5000);
    //@ assert ((tag) == 0 ? (attendees) :         (tag) == 1 ? (attendees) :         (tickets_sold)) == 8000;
}
