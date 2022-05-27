#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdint.h>
#include <stdbool.h>
#include "errores.h"

/**
 * @brief Configura la biblioteca y apaga todos los leds
 * 
 * @param direccion Direccion del puerto GPIO que controla los leds
 */
void LedsInit(uint16_t* direccion, registro_errores_t registroErrores);

/**
 * @brief Prende un led
 * 
 * @param led Numero de led a prender (1 a 16)
 */
void LedTurnOn(uint8_t led);

/**
 * @brief Apaga un led
 * 
 * @param led Numero de led a apagar (1 a 16)
 */
void LedTurnOff(uint8_t led);

/**
 * @brief Prende todos los leds al mismo tiempo
 * 
 */
void LedTurnAllOn(void);

/**
 * @brief Apaga todos los leds al mismo tiempo
 * 
 */
void LedTurnAllOff(void);

/**
 * @brief Consulta el estado de un led
 * 
 * @param led Numero de led a consultar (1 a 16)
 * @return true Si el led esta encendido
 * @return false Si el led esta apagado
 */
bool LedConsultState(uint8_t led);
#endif