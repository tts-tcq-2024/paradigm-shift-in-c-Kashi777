#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#define OK 1
#define NOT_OK 0
#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8


bool isTemperatureOk(float temperature)
{
    return (temperature >= TEMP_MIN  && temperature <= TEMP_MAX);
}

bool isStateOfChargeOk(float soc)
{
    return (soc >= SOC_MIN && soc <= SOC_MAX);
}

bool isChargeRateOk(float chargeRate)
{
   return (chargeRate <= CHARGE_RATE_MAX);
}

bool checkParameter(bool temp_ok, bool state_of_charge_ok, bool charge_rate_ok)
{
    return (temp_ok & state_of_charge_ok & charge_rate_ok);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
    bool temp_ok = isTemperatureOk(temperature);
    bool state_of_charge_ok = isStateOfChargeOk(soc);
    bool charge_rate_ok = isChargeRateOk(chargeRate);
    
    bool all_param_ok = checkParameter(temp_ok, state_of_charge_ok, charge_rate_ok);
    if(all_param_ok)
    {
        return OK;
    }
    printf("Batery parameter out of range  !\n");
    return NOT_OK;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(-50, 80, 0));
  assert(!batteryIsOk(5, 85, 0));
  assert(!batteryIsOk(5, 70, 0.9));
  assert(!batteryIsOk(5, -70, 0.5));
  
}
