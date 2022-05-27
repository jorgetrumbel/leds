#include "unity.h"
#include <stdint.h>
#include "leds.h"
#include "mock_errores.h"

/*
• Se pueden prender todos los LEDs de una vez.
• Se pueden apagar todos los LEDs de una vez.
• Se puede consultar el estado de un LED prendido.
• Se puede consultar el estado de un LED apagado.
*/

static uint16_t ledsVirtuales;
static gravedad_t gravedad_informada;

void RegistrarError(gravedad_t gravedad, const char * funcion, int linea, const char * mensaje, ...){
    gravedad_informada = gravedad;
}

void setUp(void){
    LedsInit(&ledsVirtuales, RegistrarError);
}

void tearDown(void){

}

//Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    LedsInit(&ledsVirtuales, RegistrarError);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

//Se puede prender un LED individual.
void test_TurnOnOneLed(void){
    LedTurnOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales);
}

//Se puede apagar un LED individual.
void test_TurnOffOneLed(void){
    LedTurnOn(5);
    LedTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

//Se pueden prender y apagar múltiples LED’s.
void test_TurnOnAndOffManyLeds(void){
    LedTurnOn(5);
    LedTurnOn(5);
    LedTurnOn(11);
    LedTurnOff(3);
    LedTurnOff(11);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales);
}

void test_InvalidUpperLimitTurnOnLed(void){
    LedTurnOn(17);
    TEST_ASSERT_EQUAL(ALERTA, gravedad_informada);
}