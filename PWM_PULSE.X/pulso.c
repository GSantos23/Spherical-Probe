/*
 * File:   pwm.c
 * Author: Gerson Santos Medina
 * Program to control PWM with Plib Functions
 * Created on October 14, 2015, 4:15 PM
 */

// Header Files ***************************************************************
#define _SUPPRESS_PLIB_WARNING
#include <p32xxxx.h>
#include <plib.h>
#include <xc.h>
#include <stdint.h> 
#include <stdbool.h>

// Configuration Bits *********************************************************
#pragma config FPLLMUL  = MUL_20        // PLL Multiplier   
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider    
#pragma config FPLLODIV = DIV_1         // PLL Output Divider   
#pragma config FPBDIV   = DIV_8         // Peripheral Clock Divider
#pragma config FWDTEN   = OFF           // Watchdog Timer   
#pragma config WDTPS    = PS1           // Watchdog Timer Postscale
#pragma config FCKSM    = CSDCMD        // Clock Switching & Fail Safe Clock Monitor
#pragma config OSCIOFNC = OFF           // CLKO Enable
#pragma config POSCMOD  = HS            // Primary Oscillator
#pragma config IESO     = OFF           // Internal/External Switch-over
#pragma config FSOSCEN  = OFF           // Secondary Oscillator Enable (KLO was off)
#pragma config FNOSC    = PRIPLL        // Oscillator Selection 
#pragma config CP       = OFF           // Code Protect
#pragma config BWP      = OFF           // Boot Flash Write Protect
#pragma config PWP      = OFF           // Program Flash Write Protect
#pragma config ICESEL   = ICS_PGx2      // ICE/ICD Comm Channel Select
#pragma config DEBUG    = OFF           // Background Debugger Enable

// Global Variables ***********************************************************
#define SYSCLK (80000000L)              // Clock Frequency
#define F_PB           20000000L
#define DELAY           4*SYSCLK/2      // Delay de 5s Delay = T*SYSCLK/2
#define COUNTS      1000
#define UART_BAUD_RATE    115200
//#define UART_USED          UART1

 int PWMvalue1;
 int PWMvalue2;
 int PWM_High;
 int i,j;

 // Function Prototype  *******************************************************

 void ms_delay(int ms);         // MiliSeconds (ms) Delay
 void throttle_range(void);     // Set up ESC throttle range
 void speed_test(void);         // Speed increment/decrement
 void lipo_test(void);          // Constant speed
 void pole_test(void);          // 50% Throttle to 80% Throttle
 void dif_vel(void);            // V1 < V2 Thrrotle
 void gyro(void);               // Gyro test -> Low Speed 

 // ***************************************************************************

 void main()
 {
     //SYSTEMConfigPerformance(72000000L);  // Sets the PB-Div to 1. 
                                            // Also optimises cache for 72Mhz.
    //mOSCSetPBDIV(OSC_PB_DIV_8);           // Configure the PB bus to run at
                                            // 1/8 CPU Frequency
    INTEnableSystemMultiVectoredInt();      // make separate interrupts possible


    OpenOC3(OC_ON | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE,1560,1560); // init OC1 module, T2 =source
    OpenOC4(OC_ON | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE,1560,1560); // init OC1 module, T2 =source
    OpenTimer2(T2_ON | T2_PS_1_8 | T2_SOURCE_INT,3125);

    //PR2 = FPB/samplerate-1;
    // PR2 for different frequencies 
    // PR2 = 24999  // 50Hz
    // PR2 = 12499  // 100Hz
    // PR2 = 6249   // 200Hz
    // PR2 = 3124   // 400Hz*
    PR2 = 3124;

    mT2ClearIntFlag();     // Clear the TMR2 interrupt flag
    mT2SetIntPriority(7);  // Set TMR2 interrupt priority to 7
    mT2IntEnable(1);       // Enable TMR2 interruot
    mT2ClearIntFlag();     // Clear the TMR2 interrupt flag

    PWM_High = 3000;    // 2.4 ms
    PWMvalue1 = 875;    // 700 us
    PWMvalue2 = 875;

    while(1)
    {
        // :) Select your function
        //throttle_range();
        //lipo_test();
        //pole_test();
        //dif_vel();
        //gyro();
        speed_test();
    }
 }
 
 // Functions *****************************************************************

 void __ISR( _TIMER_2_VECTOR, ipl7) T2Interrupt(void) // Interrup Service Rutine
 {
    SetDCOC3PWM(PWMvalue1);     // Configures OCxRS when the module is in PWM mode.
    SetDCOC4PWM(PWMvalue1);     // Configures OCxRS when the module is in PWM mode.
    //SetDCOC4PWM(PWMvalue2);     // Configures OCxRS when the module is in PWM mode.
                               
    mT2ClearIntFlag();           // clear this interrupt .
 }

 void ms_delay(int ms)
 {
     int z;
     while(ms--)
     {
         for(z=0; z<COUNTS; z++)
         {
            // do nothing
         }
     }

 }

 void throttle_range(void)
 {
        // Throttle range
       WriteCoreTimer(0);
        while(ReadCoreTimer()< DELAY)

           PWMvalue1 = PWM_High;

        WriteCoreTimer(0);
        while(ReadCoreTimer()< DELAY)

           PWMvalue1 = 875;

        while(1);
        
 }

 void speed_test(void)
 {
    // Increment of speed
     int k,l;

     for(k=0; k<=135; k+=5)
     {
       PWMvalue1 = PWMvalue1+k;
       ms_delay(3000);   // retardo de 3seg
     }
     // 2060 ms

     ms_delay(3000);

     PWMvalue1 = 2100;
     ms_delay(3000);

     for(l=100; l>0; l-=5)
     {
         PWMvalue1 = PWMvalue1-l;
         ms_delay(3000);
     }

       while(1);
 }

 void lipo_test(void)
 {
     PWMvalue1;
     ms_delay(5000);

     PWMvalue1 = 2500;

     while(1);
 }

 void pole_test(void)
 {
     // Increment of speed
     int a;
     
     PWMvalue1;

     ms_delay(7000);

     PWMvalue1 = 1500;

     for(a=0; a<230; a+=20)
     {
       PWMvalue1 = PWMvalue1+a;
       ms_delay(5000);   // retardo de 5seg
     }

       while(1);
 }

 void dif_vel(void)
 {
     int a;

     PWMvalue1;
     PWMvalue2;

     ms_delay(5000);

     PWMvalue1 = 1000;
     PWMvalue2 = 1000;

     for(a=0; a<200; a+=20)
     {
       PWMvalue1 = PWMvalue1 + (a/2);
       PWMvalue2 = PWMvalue2 + a;
       ms_delay(5000);   // retardo de 5seg
     }

     while(1);
 }

 void gyro()
 {
    //int a;

     PWMvalue1;
     PWMvalue2;

     ms_delay(5000);

     PWMvalue1 = 1000;
     PWMvalue2 = 1000;

     printf(":)");

     while(1);
 }