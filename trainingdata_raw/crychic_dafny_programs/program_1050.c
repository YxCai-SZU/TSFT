// Generated C + ACSL

#include <stddef.h>

#define None -1
#define Some(x) (x)

// Global state variables
int targetName = None;
int targetVehicle = None;
int targetHealth = None;
int targetID = None;
int visible = 0;

// Vehicle structure
typedef struct {
    int name;
    int vehicleType;
    int health;
    int id;
} Vehicle;

/*@
    assigns targetName, targetVehicle, targetHealth, targetID;
    ensures targetName == -1;
    ensures targetVehicle == -1;
    ensures targetHealth == -1;
    ensures targetID == -1;
*/
void ResetTarget(void)
{
  targetName = None;
  targetVehicle = None;
  targetHealth = None;
  targetID = None;
}

/*@
    requires \valid(vehicle);
    assigns targetName, targetVehicle, targetHealth, targetID;
*/
void SetTarget(Vehicle *vehicle)
{
  targetName = Some(vehicle->name);
  targetVehicle = Some(vehicle->vehicleType);
  targetHealth = Some(vehicle->health);
  targetID = Some(vehicle->id);
}

/*@
    requires newHealth >= 0;
    assigns targetID, targetHealth, targetName, targetVehicle;
*/
void UpdateTargetHealth(int vehicleID, int newHealth)
{
  if ((targetID == Some(vehicleID)))
  {
    if ((newHealth > 0))
    {
      targetHealth = Some(newHealth);
    }
    else
    {
      ResetTarget();
    }
  }
}

/*@
    assigns visible;
    ensures visible == isVisible;
*/
void SetVisibility(int isVisible)
{
  visible = isVisible;
}

/*@
    assigns \nothing;
    ensures \result == (visible ? targetName : -1);
*/
int GetTargetName(void)
{
  if (visible)
  {
    return targetName;
  }
  else
  {
    return None;
  }
}

/*@
    assigns \nothing;
    ensures \result == (visible ? targetVehicle : -1);
*/
int GetTargetVehicle(void)
{
  if (visible)
  {
    return targetVehicle;
  }
  else
  {
    return None;
  }
}

/*@
    assigns \nothing;
    ensures \result == (visible ? targetHealth : -1);
*/
int GetTargetHealth(void)
{
  if (visible)
  {
    return targetHealth;
  }
  else
  {
    return None;
  }
}