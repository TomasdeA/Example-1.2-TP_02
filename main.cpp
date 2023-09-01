/**
 * @brief Al ejemplo de ARM https://github.com/armBookCodeExamples/example_1-3
 *  
 * @arg none
 * @param gasDetector El pin al que se conecta el sensor de gas (ahora un switch a 3v3)
 * @param overTempDetector El pin al que se conecta el sensor de temperatura (ahora un switch a 3v3)
 * @param alarmLed El LED el cual se usa como alarma.
 *
 * @note Asegúrese de que esté el button/switch conectado a 3v3 y a los pines D2 y D3.
 * @note Se utiliza un pull down por ende se debe conectar a 3v3. 
 * Si se pone Pull up, conectar a GND
 * 
 * @retval none.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
   DigitalIn gasDetector(D2);
   DigitalIn overTempDetector(D3);
   
   DigitalOut alarmLed(LED1);
   
   gasDetector.mode(PullDown);   
   overTempDetector.mode(PullDown);

   while (true) {
      
      if ( gasDetector || overTempDetector ) {
         alarmLed = ON;
      } else {
         alarmLed = OFF;
      }
   }
}