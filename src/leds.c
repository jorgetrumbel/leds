#include "leds.h"

#define LED_TO_BIT_OFFSET 1
#define BIT_MASK 1
#define LEDS_ALL_OFF 0
#define LEDS_ALL_ON 0xFFFF
#define LED_ON 1
#define LED_OFF 0

static uint16_t * puerto;
static registro_errores_t RegistroErrores;

static uint16_t LedToMask(uint8_t led){
    return (BIT_MASK << (led - LED_TO_BIT_OFFSET));
}

void LedsInit(uint16_t* direccion, registro_errores_t FuncionRegistro){
    puerto = direccion;
    RegistroErrores = FuncionRegistro;
    *puerto = LEDS_ALL_OFF;
}

void LedTurnOn(uint8_t led){
    if(led > 16) {
            RegistroErrores(ALERTA, __FUNCTION__, __LINE__, "Numero de led invalido");
    }else{
        *puerto |= LedToMask(led);
    }
    
}

void LedTurnOff(uint8_t led){
    *puerto &= ~LedToMask(led);
}

void LedTurnAllOn(void){
    *puerto = LEDS_ALL_ON;
}

void LedTurnAllOff(void){
    *puerto = LEDS_ALL_OFF;
}

bool LedConsultState(uint8_t led){
    return ((*puerto & LedToMask(led)) != LED_OFF ? LED_ON : LED_OFF);
}