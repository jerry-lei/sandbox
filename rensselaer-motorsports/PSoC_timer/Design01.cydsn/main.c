/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void int_to_string(int input, char *readto){
    char const digits[] = "0123456789";
    int c1 = 0;
    while(c1 < 9){
        (*(readto+c1)) = ' ';
        c1 += 1;
    }
    while(input > 0 && c1 > 0){
        (*(readto+c1)) = digits[input%10];
        input = input/10;
        c1 -= 1;
    }
}
void float_to_string(double input, char *readto){
    char const digits[] = "0123456789";
    int c1 = 0;
    while(c1 < 9){
        (*(readto+c1)) = ' ';
        c1 += 1;
    }
    double fractpart, intpart;
    fractpart = modf(input, &intpart);
    fractpart *= 10 * 10 * 10 * 10 * 10;
    int frac_rep = (int)fractpart;
    int int_rep = (int)intpart;
    while(c1 > 4){
        (*(readto+c1)) = digits[frac_rep%10];
        frac_rep = frac_rep/10;
        c1-=1;
    }
    (*(readto+c1)) = '.';
    c1-=1;
    while(int_rep > 0 && c1 > 1){
        (*(readto+c1)) = digits[int_rep%10];
        int_rep = int_rep/10;
        c1-=1;
    }
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    TCPWM_1_Start();
    SCB_1_Start();
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */

    //rand for testing only
    srand(time(NULL));
    for(;;)
    {
        int read_period = TCPWM_1_ReadPeriod();
        int read_capture = TCPWM_1_ReadCapture();
        char print_array[10];
        //SCB_1_UartPutString("Period   |");
        //int_to_string(read_period, print_array);
        //SCB_1_UartPutString(print_array);
        //SCB_1_UartPutChar('\n');
        //SCB_1_UartPutString("Capture  |");
        //int_to_string(read_capture, print_array);
        //SCB_1_UartPutString(print_array);
        SCB_1_UartPutChar('\n');
        
        //reading counters test
        SCB_1_UartPutString("Delay ms  | Calculated second value");
        int read_counter = TCPWM_1_ReadCounter();
        //int_to_string(read_counter, print_array);
        //SCB_1_UartPutString(print_array);
        SCB_1_UartPutChar('\n');
        int c1 = 0;
        int old_counter = 0;
        char random_time[10];
        while(c1<100){
            int rand_delay = rand() % 1750;
            old_counter = read_counter;
            read_counter = TCPWM_1_ReadCounter();
            double value;
            if(read_counter > old_counter){
                value = (read_counter - old_counter) * 2.0 / read_period;
            }
            //case where the counter resets because it is over period count
            else{
                value = (read_period - old_counter + read_counter) * 2.0 / read_period;
            }
            float_to_string(value,print_array);
            SCB_1_UartPutString(print_array);
            SCB_1_UartPutChar('\n');
            int_to_string(rand_delay,random_time);
            SCB_1_UartPutString(random_time);
            SCB_1_UartPutChar('|');
            CyDelay(rand_delay);
            c1++;
        }
        break;
    }
    SCB_1_UartPutChar('~');
    return 0;
}

/* [] END OF FILE */
