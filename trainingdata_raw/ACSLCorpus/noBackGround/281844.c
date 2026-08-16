#include <string.h>
#include <stdbool.h>

typedef struct {
    char* name;
    char* cuisine;
    unsigned int rating;
} Restaurant;

/*@
    requires \valid(r);
    requires \valid(new_cuisine);
    assigns \nothing;
    ensures \result.name == r->name;
    ensures \result.rating == r->rating;
    ensures ((\result).rating > 4) <==> ((*r).rating > 4);
*/
Restaurant change_cuisine(const Restaurant* r, const char* new_cuisine) {
    Restaurant ret;
    char* tmp_name;
    char* tmp_cuisine;
    
    tmp_name = r->name;
    tmp_cuisine = (char*)new_cuisine;
    
    //@ assert r->name == tmp_name;
    
    ret.name = tmp_name;
    ret.cuisine = tmp_cuisine;
    ret.rating = r->rating;
    
    return ret;
}

/*@
    requires r1.name == r2.name;
    requires r1.cuisine == r2.cuisine;
    requires r1.rating == r2.rating;
    ensures \result == true;
*/
bool is_same_restaurant(Restaurant r1, Restaurant r2) {
    bool ret;
    ret = true;
    return ret;
}

int main() {
    return 0;
}
