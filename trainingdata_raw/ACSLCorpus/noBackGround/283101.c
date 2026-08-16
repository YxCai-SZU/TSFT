#include <stdint.h>

struct Engine {
    uint32_t horsepower;
    uint32_t fuel_tank_size;
};

/*@
  requires ((engine).horsepower >= 0 && (engine).fuel_tank_size > 0);
  ensures \result.fuel_tank_size == engine.fuel_tank_size;
  ensures \result.horsepower == new_horsepower;
  ensures ((\result).horsepower >= 0 && (\result).fuel_tank_size > 0);
*/
struct Engine tune_engine(struct Engine engine, uint32_t new_horsepower)
{
    struct Engine ret;
    //@ assert ((engine).horsepower >= 0 && (engine).fuel_tank_size > 0);
    ret.fuel_tank_size = engine.fuel_tank_size;
    ret.horsepower = new_horsepower;
    //@ assert ret.fuel_tank_size == engine.fuel_tank_size;
    return ret;
}

int main(void)
{
    struct Engine engine;
    struct Engine tuned_engine;
    
    engine.horsepower = 200;
    engine.fuel_tank_size = 50;
    //@ assert ((engine).horsepower >= 0 && (engine).fuel_tank_size > 0);
    
    tuned_engine = tune_engine(engine, 300);
    //@ assert ((tuned_engine).horsepower / (tuned_engine).fuel_tank_size) == 6;
    
    return 0;
}
