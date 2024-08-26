#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#define OK 1
#define NOT_OK 0
#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE 0.8


bool isTemperatureOk(float temperature)
{
    if(temperature < TEMP_MIN || temperature > TEMP_MAX)
    {
        return NOT_OK;
    }
    return OK;
}

bool isSocOk(float soc)
{
    if(soc < SOC_MIN || soc > SOC_MAX)
    {
        return NOT_OK;
    }
    return OK;
}

bool isChargeRateOk(float chargeRate)
{
    if(chargeRate > CHARGE_RATE)
    {
        return NOT_OK;
    }
    return OK;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    if(!isTemperatureOk(temperature))
    {
        printf("Temperature out of range!\n");
        return NOT_OK;
    }
    if(!isSocOk(soc))
    {
        printf("State of Charge out of range!\n");
        return NOT_OK;
    }
    if(!isChargeRateOk(chargeRate))
    {
        printf("Charge Rate out of range!\n");
        return NOT_OK;
    }
  return OK;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(-50, 80, 0));
  assert(!batteryIsOk(5, 85, 0));
  assert(!batteryIsOk(5, 70, 0.8));
  assert(!batteryIsOk(5, -70, 0.5));
}
