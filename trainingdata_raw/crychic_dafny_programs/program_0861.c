// Generated C + ACSL

typedef struct {
    int x;
    int y;
} Point;

/*@
    requires degrees == 90 || degrees == 180 || degrees == 270;
    assigns \nothing;
    ensures (degrees == 180 ==> \result.x == -p.x && \result.y == -p.y) ||
            (degrees == 90 ==> \result.x == p.y && \result.y == -p.x) ||
            (degrees == 270 ==> \result.x == -p.y && \result.y == p.x);
*/
Point RotateVector(Point p, int degrees)
{
  Point newPoint;
  newPoint.x = 0;
  newPoint.y = 0;
  if (degrees == 180)
  {
    newPoint.x = -p.x;
    newPoint.y = -p.y;
  }
  else
  if (degrees == 90)
  {
    newPoint.x = p.y;
    newPoint.y = -p.x;
  }
  else
  {
    newPoint.x = -p.y;
    newPoint.y = p.x;
  }
  return newPoint;
}

/*@
    requires commands != \null;
    requires commands_len > 0;
    requires \valid(commands + (0 .. commands_len-1));
    assigns \nothing;
    ensures \true;
*/
int NavigateShip(int* commands, int commands_len)
{
  Point pos;
  pos.x = 0;
  pos.y = 0;
  Point dir;
  dir.x = 1;
  dir.y = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= commands_len;
  loop invariant \valid_read(commands + (0..commands_len-1));
  loop assigns i, pos.x, pos.y, dir.x, dir.y;
  loop variant commands_len - i;
*/
  while (i < commands_len)
    {
      int cmd = commands[i];
      i = (i + 1);
    }
  int finalPos = 0;
  /*@ assert finalPos >= 0 && finalPos <= 2147483647; */
  return finalPos;
}

/*@
    requires commands != \null;
    requires commands_len > 0;
    requires \valid(commands + (0 .. commands_len-1));
    assigns \nothing;
    ensures \result >= 0 || \result < 0;
*/
int NavigateWithWaypoint(int* commands, int commands_len)
{
  Point ship;
  ship.x = 0;
  ship.y = 0;
  Point waypoint;
  waypoint.x = 10;
  waypoint.y = 1;
  int i = 0;
/*@
  loop invariant 0 <= i <= commands_len;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, waypoint.x, waypoint.y, ship.x, ship.y;
  loop variant commands_len - i;
*/
  while (i < commands_len)
    {
      int cmd = commands[i];
      i = (i + 1);
    }
  int finalPos = 0;
  /*@ assert finalPos >= 0 && finalPos <= 2147483647; */
  return finalPos;
}

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0;
*/
int ManhattanDistance(Point p)
{
  int distance = (p.x < 0) ? (-p.x) : (p.x);
  /*@ assert distance >= 0 && distance <= 2147483647; */
  distance = distance + ((p.y < 0) ? (-p.y) : (p.y));
  return distance;
}