#include <stdbool.h>

struct Ticket {
    unsigned int points;
};

/*@
    requires \valid(ticket);
    ensures ((\result) == ((\old(ticket->points)) >= (amount)) &&
        ((\result) ==> (ticket->points) == (\old(ticket->points)) - (amount)));
*/
bool use_points(struct Ticket* ticket, unsigned int amount) {
    unsigned int old_points;
    bool ret;
    
    // Declare all variables at the top
    old_points = ticket->points;
    ret = false;
    
    if (ticket->points >= amount) {
        //@ assert ticket->points >= amount;
        //@ assert ticket->points - amount >= 0;
        ticket->points = ticket->points - amount;
        ret = true;
    } else {
        ret = false;
    }
    
    return ret;
}

int main() {
    return 0;
}
