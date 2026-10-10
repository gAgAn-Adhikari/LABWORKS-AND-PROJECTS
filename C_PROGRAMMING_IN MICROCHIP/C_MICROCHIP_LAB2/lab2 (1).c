/** @file lab2.c
 *
 * @brief lab2 on car statuses
 * Author :
 */

#include <avr/io.h>

// set CPU clock to be 16MHz
//
#define F_CPU 16000000

#include <util/delay.h>

// prototype
//
void display_statuses_and_results( uint8_t stat );

int main(void)
{
    // set whole PORTD for output (displaying statuses + condition results)


    while (1)
    {
        //the first test case
        uint8_t stat = 0B01101101;

        //display the statuses and results in LEDs by calling the function
        display_statuses_and_results (stat);

        
        //the second test case
        stat = 0B01010111;

         //display the statuses and results in LEDs by calling the function
        display_statuses_and_results (stat);


        //the third test case
        stat = 0B00000000;

        //display the statuses and results in LEDs by calling the function
        display_statuses_and_results (stat);

    }
}

/*!
 * @brief display the car statuses and condition results in 4 and 4 LEDs
 * @param[in]  stat The statuses used to check 4 conditions
 * @return nothing
 */
void display_statuses_and_results( uint8_t stat )
{
    // implement your code to check 4 conditions and output the result to 4 LEDs via PORTD
    // to do

} /* display_statuses_and_results */

/*** end of file ***/
