#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef enum {
    Concert,
    Festival,
    Movie
} EventTag;

typedef struct {
    unsigned int attendees;
    unsigned int ticket_price;
} ConcertData;

typedef struct {
    unsigned int attendees;
    unsigned int ticket_price;
    unsigned int booths;
} FestivalData;

typedef struct {
    unsigned int tickets_sold;
    unsigned int ticket_price;
} MovieData;

typedef union {
    ConcertData Concert;
    FestivalData Festival;
    MovieData Movie;
} EventData;

typedef struct {
    EventTag tag;
    EventData data;
} Event;

/*@
    predicate is_well_attended(Event e) =
        (e.tag == Concert && e.data.Concert.attendees > 5000) ||
        (e.tag == Festival && e.data.Festival.attendees > 20000) ||
        (e.tag == Movie && e.data.Movie.tickets_sold > 10000);

    predicate is_profitable(Event e) =
        (e.tag == Concert && e.data.Concert.attendees * e.data.Concert.ticket_price > 100000) ||
        (e.tag == Festival && e.data.Festival.attendees * e.data.Festival.ticket_price > 50000) ||
        (e.tag == Movie && e.data.Movie.tickets_sold * e.data.Movie.ticket_price > 20000);
*/

bool plan_event(Event event) {
    bool planning_result;
    
    //@ assert is_well_attended(event) && is_profitable(event);
    
    if (event.tag == Concert) {
        //@ assert event.data.Concert.attendees > 5000;
    } else if (event.tag == Festival) {
        //@ assert event.data.Festival.attendees > 20000;
    } else if (event.tag == Movie) {
        //@ assert event.data.Movie.tickets_sold > 10000;
    }
    
    planning_result = true;
    //@ assert planning_result == true;
    return planning_result;
}

/*@
    predicate is_strictly_increasing(integer a, integer b, integer c, integer d) =
        a < b && b < c && c < d;
 */

bool check_increasing(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    bool result;

    if (a >= b || b >= c || c >= d)
    {
        //@ assert a >= b || b >= c || c >= d;
        result = false;
    }
    else
    {
        //@ assert a < b && b < c && c < d;
        result = true;
    }

    return result;
}

/*@
    predicate is_valid_index(integer i, integer len) =
        0 <= i && i < len;

    predicate vec_len_eq{L1, L2}(unsigned int *vec, integer len) =
        \forall integer i; 0 <= i < len ==> \at(vec[i], L1) == \at(vec[i], L2);
*/

unsigned int double_element(unsigned int *v, size_t len) {
    unsigned int x;
    unsigned int result;
    
    //@ assert len >= 1;
    x = v[0];
    
    //@ assert x <= 0x40000000 && x >= 0;
    //@ assert x * 2 <= 0x80000000;
    
    v[0] = x * 2;
    result = v[0];
    
    //@ assert result == v[0];
    //@ assert v[0] == x * 2;
    
    return result;
}

/*@
    predicate valid_params(integer n, integer x, integer y) =
        3 <= n <= 2000 &&
        1 <= x <= n &&
        1 <= y <= n &&
        x + 1 < y;

    logic integer compute_d(integer x, integer y) = y - x - 1;

    logic integer compute_result(integer d) =
        d > 0 ? (d * 2) - 1 : d * 2;
*/

int compute_distance(int n, int x, int y)
{
    int d;
    int d_abs;
    int result;
    int i;

    d = y - x - 1;

    //@ assert d == compute_d(x, y);

    if (d < 0)
    {
        d_abs = -d;
    }
    else
    {
        d_abs = d;
    }

    //@ assert d_abs >= 0;

    result = 0;
    i = 0;

    while (i < d_abs)
    {
        result += 2;
        i += 1;
    }

    if (d < 0)
    {
        result = -result;
    }

    if (d > 0)
    {
        result -= 1;
    }

    //@ assert result == compute_result(d);

    return result;
}

/*@
    predicate valid_event_planning(Event e, unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned int *v, size_t len, int n, int x, int y) =
        is_well_attended(e) && is_profitable(e) &&
        \valid(v + (0 .. len-1)) && len >= 1 &&
        \forall integer i; 0 <= i < len ==> v[i] <= 0x40000000 && v[i] >= 0 &&
        valid_params(n, x, y);
*/

bool process_event_data(Event event, unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned int *v, size_t len, int n, int x, int y) {
    bool planned;
    bool increasing;
    unsigned int doubled;
    int distance;
    unsigned int old_v0 = v[0];
    
    planned = plan_event(event);
    //@ assert planned == true;
    
    increasing = check_increasing(a, b, c, d);
    //@ assert increasing == true <==> is_strictly_increasing(a, b, c, d);
    
    doubled = double_element(v, len);
    //@ assert doubled == v[0];
    //@ assert v[0] == old_v0 * 2;
    
    distance = compute_distance(n, x, y);
    //@ assert distance == (y - x - 1) * 2 - 1 || distance == (y - x - 1) * 2;
    
    //@ assert planned == true && (increasing == true <==> is_strictly_increasing(a, b, c, d)) && doubled == v[0] && (distance == (y - x - 1) * 2 - 1 || distance == (y - x - 1) * 2);
    
    return true;
}
