#include <stdbool.h>
#include <string.h>

typedef struct {
    unsigned int area;
    char* name;
} Country;

/*@
    requires \valid(c);
    requires \valid_read(new_name);
    ensures \result.area == c->area;
    ensures ((*c).area > 500000) <==> ((\result).area > 500000);
    assigns \nothing;
*/
Country change_name(const Country* c, char* new_name) {
    Country result;
    result.area = c->area;
    result.name = new_name;
    return result;
}

/*@
    assigns \nothing;
*/
void create_and_evaluate() {
    Country country;
    Country renamed;
    
    country.area = 600000;
    country.name = "Terraverus";
    
    //@ assert ((country).area > 500000);
    
    renamed = change_name(&country, "Verus");
    
    //@ assert ((renamed).area > 500000);
}

