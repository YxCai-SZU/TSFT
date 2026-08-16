// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result == 1;
*/
int run(void)
{
  int sensor_x = 1;
  int charging_x = 0;
  int drone_x = 0;
  int battery = 100;
  int queue = 0;
  int battery_cost = 20;
  int t = 0;
  int choice = 0;
/*@
  loop invariant 0 <= t <= 100;
  loop invariant battery - queue > 0;
  loop invariant (drone_x == 0 || drone_x == 1);
  loop invariant (drone_x == 0 ==> battery == 100);
  loop invariant (drone_x == 1 ==> queue == 0);
  loop invariant battery >= 0;
  loop invariant queue >= 0;
  loop assigns t, choice, drone_x, battery, queue;
  loop variant 100 - t;
*/
  while ((t < 100))
    {
      choice = 0;
      if ((battery > 20))
      {
        choice = 1;
      }
      if ((choice == 0))
      {
        drone_x = 0;
        battery = 100;
        queue = (queue + 10);
      }
      else
      {
        drone_x = 1;
        battery = (battery - battery_cost);
        queue = 0;
      }
      t = (t + 1);
    }
  return 1;
}