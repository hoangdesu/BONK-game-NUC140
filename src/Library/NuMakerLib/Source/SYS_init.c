//
// NUC140 SYS_Init
//
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

void SYS_Init(void)
{
    SYS_UnlockReg(); // Unlock protected registers

    // select Chip clock source & set clock source
    CLK_EnableXtalRC(MCU_CLOCK_SOURCE_MASK);    // Enable HXT external 12MHz crystal
    CLK_WaitClockReady(MCU_CLOCK_STABLE_MASK);	
    CLK_SetCoreClock(MCU_CLOCK_FREQUENCY);      // Set HCLK clock to 32MHz

    // Select IP clock source & enable module
    #ifdef MCU_INTERFACE_RTC
    CLK_EnableModuleClock(RTC_MODULE);	
    CLK_SetModuleClock(RTC_MODULE, CLK_CLKSEL2_RTC_SEL_10K_LXT, 0);	
    #endif
	
    #ifdef MCU_INTERFACE_WDT
    CLK_EnableModuleClock(WDT_MODULE);	
	    #ifdef WDT_CLOCK_SOURCE_LIRC
        CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDT_S_LIRC, 0);
	    #endif
	    #ifdef CLK_CLKSEL1_WDT_S_HCLK_DIV2048
        CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDT_S_HCLK_DIV2048, 0);	
	    #endif
	    #ifdef WDT_CLOCK_SOURCE_LXT
        CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDT_S_LXT, 0);	
			#endif
    #endif

    #ifdef MCU_INTERFACE_WWDT
    CLK_EnableModuleClock(WWDT_MODULE);	
	    #ifdef WWDT_CLOCK_SOURCE_HCLK_DIV2048
        CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL2_WWDT_S_HCLK_DIV2048, 0);	
	    #endif		
	    #ifdef WWDT_CLOCK_SOURCE_LIRC
        CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL2_WWDT_S_LIRC, 0);
	    #endif
    #endif
		

    #ifdef MCU_INTERFACE_TMR0
       CLK_EnableModuleClock(TMR0_MODULE);	
	     #ifdef TMR0_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);
			 #endif
	     #ifdef TMR0_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_LXT, 0);
			 #endif	
			 #ifdef TMR0_CLOCK_SOURCE_HCLK
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HCLK, 0);
			 #endif			
			 #ifdef TMR0_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_EXT_TRG, 0);
			 #endif				 
			 #ifdef TMR0_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_LIRC, 0);
			 #endif
			 #ifdef TMR0_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HIRC, 0);
			 #endif
	  #endif

    #ifdef MCU_INTERFACE_TMR1
       CLK_EnableModuleClock(TMR1_MODULE);	
	     #ifdef TMR1_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HXT, 0);
			 #endif
	     #ifdef TMR1_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_LXT, 0);
			 #endif	
			 #ifdef TMR1_CLOCK_SOURCE_HCLK
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HCLK, 0);
			 #endif			
			 #ifdef TMR1_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_EXT_TRG, 0);
			 #endif				 
			 #ifdef TMR1_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_LIRC, 0);
			 #endif
			 #ifdef TMR1_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HIRC, 0);
			 #endif
	  #endif

    #ifdef MCU_INTERFACE_TMR2
       CLK_EnableModuleClock(TMR2_MODULE);	
	     #ifdef TMR2_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_HXT, 0);
			 #endif
	     #ifdef TMR2_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_LXT, 0);
			 #endif	
			 #ifdef TMR2_CLOCK_SOURCE_HCLK
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_HCLK, 0);
			 #endif			
			 #ifdef TMR2_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_EXT_TRG, 0);
			 #endif				 
			 #ifdef TMR2_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_LIRC, 0);
			 #endif
			 #ifdef TMR2_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_HIRC, 0);
			 #endif
	  #endif
		
    #ifdef MCU_INTERFACE_TMR3
       CLK_EnableModuleClock(TMR3_MODULE);	
	     #ifdef TMR3_CLOCK_SOURCE_HXT
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_HXT, 0);
			 #endif
	     #ifdef TMR3_CLOCK_SOURCE_LXT
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_LXT, 0);
			 #endif	
			 #ifdef TMR3_CLOCK_SOURCE_HCLK
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_HCLK, 0);
			 #endif			
			 #ifdef TMR3_CLOCK_SOURCE_EXT
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_EXT_TRG, 0);
			 #endif				 
			 #ifdef TMR3_CLOCK_SOURCE_LIRC
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_LIRC, 0);
			 #endif
			 #ifdef TMR3_CLOCK_SOURCE_HIRC
			 CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_HIRC, 0);
			 #endif
	  #endif
		
	  #ifdef MCU_INTERFACE_ADC
		   CLK_EnableModuleClock(ADC_MODULE);
			 #ifdef ADC_CLOCK_SOURCE_HXT
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HXT, CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
			 #ifdef ADC_CLOCK_SOURCE_LXT
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_LXT, CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
			 #ifdef ADC_CLOCK_SOURCE_PLL
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_PLL, CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
			 #ifdef ADC_CLOCK_SOURCE_HIRC
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HIRC,CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif	
			 #ifdef ADC_CLOCK_SOURCE_HCLK
       CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HCLK,CLK_ADC_CLK_DIVIDER(ADC_CLOCK_DIVIDER));
			 #endif
	  #endif

	  #ifdef MCU_INTERFACE_I2C0
    CLK_EnableModuleClock(I2C0_MODULE);		
	  CLK_SetModuleClock(I2C0_MODULE, 0, 0);
	  #endif
	
	  #ifdef MCU_INTERFACE_I2C1
    CLK_EnableModuleClock(I2C1_MODULE);		
	  CLK_SetModuleClock(I2C1_MODULE, 0, 0);
	  #endif
 
    #ifdef MCU_INTERFACE_PWM0
	    #ifdef PWM0_CH01_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM01_MODULE, CLK_CLKSEL1_PWM01_S_HXT, 0);
			#endif
			#ifdef PWM0_CH01_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM01_MODULE, CLK_CLKSEL1_PWM01_S_LXT, 0);
			#endif
			#ifdef PWM0_CH01_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM01_MODULE, CLK_CLKSEL1_PWM01_S_HCLK, 0);
			#endif
			#ifdef PWM0_CH01_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM01_MODULE, CLK_CLKSEL1_PWM01_S_HIRC, 0);
			#endif
			CLK_EnableModuleClock(PWM01_MODULE);

	    #ifdef PWM0_CH23_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM23_MODULE, CLK_CLKSEL1_PWM23_S_HXT, 0);
			#endif
			#ifdef PWM0_CH23_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM23_MODULE, CLK_CLKSEL1_PWM23_S_LXT, 0);
			#endif
			#ifdef PWM0_CH23_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM23_MODULE, CLK_CLKSEL1_PWM23_S_HCLK, 0);
			#endif
			#ifdef PWM0_CH23_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM23_MODULE, CLK_CLKSEL1_PWM23_S_HIRC, 0);
			#endif
			CLK_EnableModuleClock(PWM23_MODULE);
		#endif

	  #ifdef MCU_INTERFACE_PWM1
	    #ifdef PWM1_CH45_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM45_MODULE, CLK_CLKSEL1_PWM45_S_HXT, 0);
			#endif
			#ifdef PWM1_CH45_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM45_MODULE, CLK_CLKSEL1_PWM45_S_LXT, 0);
			#endif
			#ifdef PWM1_CH45_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM45_MODULE, CLK_CLKSEL1_PWM45_S_HCLK, 0);
			#endif
			#ifdef PWM1_CH45_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM45_MODULE, CLK_CLKSEL1_PWM45_S_HIRC, 0);
			#endif
			CLK_EnableModuleClock(PWM45_MODULE);

	    #ifdef PWM1_CH67_CLOCK_SOURCE_HXT
			  CLK_SetModuleClock(PWM67_MODULE, CLK_CLKSEL1_PWM67_S_HXT, 0);
			#endif
			#ifdef PWM1_CH67_CLOCK_SOURCE_LXT
			  CLK_SetModuleClock(PWM67_MODULE, CLK_CLKSEL1_PWM67_S_LXT, 0);
			#endif
			#ifdef PWM1_CH67_CLOCK_SOURCE_HCLK
			  CLK_SetModuleClock(PWM67_MODULE, CLK_CLKSEL1_PWM67_S_HCLK, 0);
			#endif
			#ifdef PWM1_CH67_CLOCK_SOURCE_HIRC
			  CLK_SetModuleClock(PWM67_MODULE, CLK_CLKSEL1_PWM67_S_HIRC, 0);
			#endif
			CLK_EnableModuleClock(PWM67_MODULE);
    #endif
		
		#ifdef MCU_INTERFACE_UART0
		  CLK_EnableModuleClock(UART0_MODULE);
		  #ifdef UART_CLOCK_SOURCE_HXT
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
			#ifdef UART_CLOCK_SOURCE_PLL
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_HIRC
		  CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
		#endif

		#ifdef MCU_INTERFACE_UART1
		  CLK_EnableModuleClock(UART1_MODULE);
		  #ifdef UART_CLOCK_SOURCE_HXT
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
			#ifdef UART_CLOCK_SOURCE_PLL
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_HIRC
		  CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
		#endif

		#ifdef MCU_INTERFACE_UART2
		  CLK_EnableModuleClock(UART2_MODULE);
		  #ifdef UART_CLOCK_SOURCE_HXT
		  CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif		
			#ifdef UART_CLOCK_SOURCE_PLL
		  CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif
		  #ifdef UART_CLOCK_SOURCE_HIRC
		  CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_UART_CLK_DIVIDER(UART_CLOCK_DIVIDER));
			#endif			
		#endif
		
    #ifdef MCU_INTERFACE_SPI0
      CLK_EnableModuleClock(SPI0_MODULE);
			#ifdef SPI0_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL1_SPI0_S_PLL, 0);
			#endif
			#ifdef SPI0_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL1_SPI0_S_HCLK, 0);
			#endif			
		#endif 

    #ifdef MCU_INTERFACE_SPI1
      CLK_EnableModuleClock(SPI1_MODULE);
			#ifdef SPI1_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL1_SPI1_S_PLL, 0);
			#endif
			#ifdef SPI1_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL1_SPI1_S_HCLK, 0);
			#endif			
		#endif 
		
    #ifdef MCU_INTERFACE_SPI2
      CLK_EnableModuleClock(SPI2_MODULE);
			#ifdef SPI2_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI2_MODULE, CLK_CLKSEL1_SPI2_S_PLL, 0);
			#endif
			#ifdef SPI2_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI2_MODULE, CLK_CLKSEL1_SPI2_S_HCLK, 0);
			#endif			
		#endif 
		
    #ifdef MCU_INTERFACE_SPI3
      CLK_EnableModuleClock(SPI3_MODULE);
			#ifdef SPI3_CLOCK_SOURCE_HCLK
      CLK_SetModuleClock(SPI3_MODULE, CLK_CLKSEL1_SPI3_S_HCLK, 0);
			#endif			
			#ifdef SPI3_CLOCK_SOURCE_PLL
      CLK_SetModuleClock(SPI3_MODULE, CLK_CLKSEL1_SPI3_S_PLL, 0);
			#endif
		#endif 
		
		#ifdef MCU_INTERFACE_ACMP
		   CLK_EnableModuleClock(ACMP_MODULE);
		   CLK_SetModuleClock(ACMP_MODULE, 0, 0);
    #endif

    #ifdef MCU_INTERFACE_USB
		   CLK_EnableModuleClock(USBD_MODULE);		
       CLK_SetModuleClock(USBD_MODULE, 0, CLK_CLKDIV_USB(USB_CLOCK_DIVIDER));
		#endif
		
    #ifdef MCU_INTERFACE_CAN
		   CLK_EnableModuleClock(CAN0_MODULE);		
		#endif		

    #ifdef MCU_INTERFACE_CLKO		
        //CKO frequency = (Clock source frequency) / 2^(u32ClkDiv + 1);				
		    CLK_EnableModuleClock(FDIV_MODULE);
				CLK->FRQDIV = CLK_FRQDIV_DIVIDER_EN_Msk | CLKO_CLOCK_DIVIDER;
				CLK->APBCLK |= CLK_APBCLK_FDIV_EN_Msk;

				#ifdef CLK_FRQDIV_SOURCE_HXT
				CLK_SetModuleClock(FDIV_MODULE, CLK_CLKSEL2_FRQDIV_S_HXT, 0);
				#endif
				#ifdef CLK_FRQDIV_SOURCE_LXT
				CLK_SetModuleClock(FDIV_MODULE, CLK_CLKSEL2_FRQDIV_S_LXT, 0);
				#endif
				#ifdef CLK_FRQDIV_SOURCE_HCLK
				CLK_SetModuleClock(FDIV_MODULE, CLK_CLKSEL2_FRQDIV_S_HCLK, 0);
				#endif
				#ifdef CLK_FRQDIV_SOURCE_HIRC
				CLK_SetModuleClock(FDIV_MODULE, CLK_CLKSEL2_FRQDIV_S_HIRC, 0);
				#endif								
		#endif
		
    // Init I/O Multi-function 
    // Set multi-function pins for ACMP
		#ifdef PIN_ACMP0_P_PC6
		SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_GPC_MFP_PC6_Msk) | SYS_GPC_MFP_PC6_ACMP0_P;
    SYS->ALT_MFP1= (SYS->ALT_MFP1& ~SYS_ALT_MFP_PC6_Msk) | SYS_ALT_MFP1_PC6_ACMP0_P;
		GPIO_DISABLE_DIGITAL_PATH(PC, BIT6);
		#endif

		#ifdef PIN_ACMP0_N_PC7
		SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_GPC_MFP_PC7_Msk) | SYS_GPC_MFP_PC7_ACMP0_N;
    SYS->ALT_MFP1= (SYS->ALT_MFP1& ~SYS_ALT_MFP_PC7_Msk) | SYS_ALT_MFP1_PC7_ACMP0_N;
		GPIO_DISABLE_DIGITAL_PATH(PC, BIT7);
		#endif

		#ifdef PIN_ACMP1_P_PC14
		SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_GPC_MFP_PC14_Msk) | SYS_GPC_MFP_PC14_ACMP1_P;
    SYS->ALT_MFP1= (SYS->ALT_MFP1& ~SYS_ALT_MFP_PC14_Msk) | SYS_ALT_MFP1_PC14_ACMP1_P;
		GPIO_DISABLE_DIGITAL_PATH(PC, BIT14);
		#endif

		#ifdef PIN_ACMP1_N_PC15
		SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_GPC_MFP_PC15_Msk) | SYS_GPC_MFP_PC15_ACMP1_N;
    SYS->ALT_MFP1= (SYS->ALT_MFP1& ~SYS_ALT_MFP_PC15_Msk) | SYS_ALT_MFP1_PC15_ACMP1_N;
		GPIO_DISABLE_DIGITAL_PATH(PC, BIT15);
		#endif

		#ifdef PIN_ACMP0_O_PB12
		SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_GPB_MFP_PB12_Msk) | SYS_GPB_MFP_PB12_ACMP0_O;
    SYS->ALT_MFP1= (SYS->ALT_MFP1& ~SYS_ALT_MFP_PB12_Msk) | SYS_ALT_MFP1_PB12_ACMP0_O;
		GPIO_DISABLE_DIGITAL_PATH(PB, BIT12);
		#endif

		#ifdef PIN_ACMP1_O_PB13
		SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_GPB_MFP_PB13_Msk) | SYS_GPB_MFP_PB13_ACMP1_O;
    SYS->ALT_MFP1= (SYS->ALT_MFP1& ~SYS_ALT_MFP_PB13_Msk) | SYS_ALT_MFP1_PB13_ACMP1_O;
		GPIO_DISABLE_DIGITAL_PATH(PB, BIT13);
		#endif
		
    // Set PA multi-function pins for ADC		
	  #ifdef PIN_ADC_0
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA0_MFP_Msk) | SYS_PA_L_MFP_PA0_MFP_ADC_CH0;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT0);
	  #endif
	  #ifdef PIN_ADC_1
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA1_MFP_Msk) | SYS_PA_L_MFP_PA1_MFP_ADC_CH1;		
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT1);
	  #endif
	  #ifdef PIN_ADC_2
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA2_MFP_Msk) | SYS_PA_L_MFP_PA2_MFP_ADC_CH2;	
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT2);
	  #endif
	  #ifdef PIN_ADC_3
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA3_MFP_Msk) | SYS_PA_L_MFP_PA3_MFP_ADC_CH3;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT3);
	  #endif
	  #ifdef PIN_ADC_4
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA4_MFP_Msk) | SYS_PA_L_MFP_PA4_MFP_ADC_CH4;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT4);
	  #endif
		#ifdef PIN_ADC_5
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA5_MFP_Msk) | SYS_PA_L_MFP_PA5_MFP_ADC_CH5;	
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT5);
	  #endif
		#ifdef PIN_ADC_6
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA6_MFP_Msk) | SYS_PA_L_MFP_PA6_MFP_ADC_CH6;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT6);
	  #endif
		#ifdef PIN_ADC_7
    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA7_MFP_Msk) | SYS_PA_L_MFP_PA7_MFP_ADC_CH7;
		GPIO_DISABLE_DIGITAL_PATH(PA, BIT7);
	  #endif

    #ifdef MCU_INTERFACE_INT0_PB14
    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB14_MFP_Msk) | SYS_PB_H_MFP_PB14_MFP_EINT0;
		#endif
    #ifdef MCU_INTERFACE_INT1_PB15
    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB15_MFP_Msk) | SYS_PB_H_MFP_PB15_MFP_EINT1;
		#endif

    #ifdef MCU_INTERFACE_I2C0
     #ifdef PIN_I2C0_SCL_PA9
		 SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA9_MFP_Msk) | SYS_PA_H_MFP_PA9_MFP_I2C0_SCL;
		 #endif
		 #ifdef PIN_I2C0_SDA_PA8
		 SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA8_MFP_Msk) | SYS_PA_H_MFP_PA8_MFP_I2C0_SDA;
		 #endif
		#endif

    #ifdef MCU_INTERFACE_I2C1
     #ifdef PIN_I2C1_SCL_PA11
		 SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA11_MFP_Msk) | SYS_PA_H_MFP_PA11_MFP_I2C1_SCL;
		 #endif
		 #ifdef PIN_I2C1_SDA_PA10
		 SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA10_MFP_Msk) | SYS_PA_H_MFP_PA10_MFP_I2C1_SDA;
		 #endif
		#endif

    #ifdef MCU_INTERFACE_I2S
     #ifdef PIN_I2S_LRCLK_PC0
		 SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC0_MFP_Msk) | SYS_PC_L_MFP_PC0_MFP_I2S_LRCLK;
		 #endif
		 #ifdef PIN_I2S_BCLK_PC1
		 SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC1_MFP_Msk) | SYS_PC_L_MFP_PC1_MFP_I2S_BCLK;
		 #endif
		 #ifdef PIN_I2S_DI_PC2
		 SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC2_MFP_Msk) | SYS_PC_L_MFP_PC2_MFP_I2S_DI;
		 #endif	
		 #ifdef PIN_I2S_DI_PC3
		 SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC3_MFP_Msk) | SYS_PC_L_MFP_PC3_MFP_I2S_DO;
		 #endif	
		#endif
		
		#ifdef MCU_INTERFACE_PWM0
		 #ifdef PIN_PWM0_CH0_PA12
     SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA12_MFP_Msk) | SYS_PA_H_MFP_PA12_MFP_PWM_CH0;
		 #endif
		 #ifdef PIN_PWM0_CH1_PA13
     SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA13_MFP_Msk) | SYS_PA_H_MFP_PA13_MFP_PWM_CH1;
		 #endif
		 #ifdef PIN_PWM0_CH2_PA14
     SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA14_MFP_Msk) | SYS_PA_H_MFP_PA14_MFP_PWM_CH2;
		 #endif
		 #ifdef PIN_PWM0_CH3_PA15
     SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_H_MFP_PA15_MFP_Msk) | SYS_PA_H_MFP_PA15_MFP_PWM_CH3;
		 #endif
    #endif
		
		#ifdef MCU_INTERFACE_PWM1		
		 #ifdef PIN_PWM1_CH4_PB11
     SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB11_MFP_Msk) | SYS_PB_H_MFP_PB11_MFP_PWM_CH4;
		 #endif
		 #ifdef PIN_PWM1_CH5_PE5
     SYS->GPE_MFP = (SYS->GPE_MFP & ~SYS_PE_L_MFP_PE5_MFP_Msk) | SYS_PE_L_MFP_PE5_MFP_PWM_CH5;
		 #endif
		 #ifdef PIN_PWM1_CH6_PE0
     SYS->GPE_MFP = (SYS->GPE_MFP & ~SYS_PE_L_MFP_PE0_MFP_Msk) | SYS_PE_L_MFP_PE0_MFP_PWM_CH6;
		 #endif
		 #ifdef PIN_PWM1_CH7_PE1
     SYS->GPE_MFP = (SYS->GPE_MFP & ~SYS_PE_L_MFP_PE1_MFP_Msk) | SYS_PE_L_MFP_PE1_MFP_PWM_CH7;
		 #endif	
		#endif

		#ifdef MCU_INTERFACE_UART0
		 #ifdef PIN_UART0_RX_PB0
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB0_MFP_Msk)  | SYS_PB_L_MFP_PB0_MFP_UART0_RX;
		 #endif
		 #ifdef PIN_UART0_TX_PB1
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB1_MFP_Msk)  | SYS_PB_L_MFP_PB1_MFP_UART0_TX;
		 #endif		
		 #ifdef PIN_UART0_RTS_PB2
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB2_MFP_Msk)  | SYS_PB_L_MFP_PB2_MFP_UART0_nRTS;
		 #endif
		 #ifdef PIN_UART0_CTS_PB3
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB3_MFP_Msk)  | SYS_PB_L_MFP_PB3_MFP_UART0_nCTS;
		 #endif		 
		#endif	
		
		#ifdef MCU_INTERFACE_UART1
		 #ifdef PIN_UART1_RX_PB4
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB4_MFP_Msk)  | SYS_PB_L_MFP_PB4_MFP_UART1_RX;
		 #endif
		 #ifdef PIN_UART1_TX_PB5
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB5_MFP_Msk)  | SYS_PB_L_MFP_PB5_MFP_UART1_TX;
		 #endif		
		 #ifdef PIN_UART1_RTS_PB6
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB6_MFP_Msk)  | SYS_PB_L_MFP_PB6_MFP_UART1_nRTS;
		 #endif
		 #ifdef PIN_UART1_CTS_PB7
		 SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB7_MFP_Msk)  | SYS_PB_L_MFP_PB7_MFP_UART1_nCTS;
		 #endif		 
		#endif	

		#ifdef MCU_INTERFACE_UART2
		 #ifdef PIN_UART2_RX_PD14
		 SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD14_MFP_Msk)  | SYS_PD_H_MFP_PD14_MFP_UART2_RX;
		 #endif
		 #ifdef PIN_UART2_TX_PD15
		 SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD15_MFP_Msk)  | SYS_PD_H_MFP_PD15_MFP_UART2_TX;
		 #endif				 
		#endif
		
    #ifdef MCU_INTERFACE_TMR0
		 #ifdef PIN_TC0_PB15
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB15_MFP_Msk) | SYS_GPB_MFP_PB15_TC0;
        SYS->ALT_MFP = (SYS->ALT_MFP & ~SYS_ALT_MFP_PB15_Msk)| SYS_ALT_MFP_PB15_TM0_EXT;				
		 #endif
		 #ifdef PIN_TMR0_CNT_PB8
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB8_MFP_Msk) | SYS_GPB_MFP_PB8_TM0;
		 #endif		 
		#endif
		
    #ifdef MCU_INTERFACE_TMR1
		 #ifdef PIN_TC1_PE5
		    SYS->GPE_MFP = (SYS->GPE_MFP & ~SYS_PE_L_MFP_PE5_MFP_Msk) | SYS_GPE_MFP_PE5_TC1;
        SYS->ALT_MFP = (SYS->ALT_MFP & ~SYS_ALT_MFP_PE5_Msk)| SYS_ALT_MFP_PE5_TM1_EXT;					
		 #endif		
		 #ifdef PIN_TMR1_CNT_PB9
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB9_MFP_Msk) | SYS_GPB_MFP_PB9_TM1;
		 #endif
		#endif
		
    #ifdef MCU_INTERFACE_TMR2
		 #ifdef PIN_TC2_PB2
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB2_MFP_Msk) | SYS_GPB_MFP_PB2_TC2;
        SYS->ALT_MFP = (SYS->ALT_MFP & ~SYS_ALT_MFP_PB2_Msk)| SYS_ALT_MFP_PB2_TM2_EXT;			
		 #endif		
		 #ifdef PIN_TMR2_CNT_PB10
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB10_MFP_Msk) | SYS_GPB_MFP_PB10_TM2;
		 #endif
		#endif
		
    #ifdef MCU_INTERFACE_TMR3
		 #ifdef PIN_TC3_PB3
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_L_MFP_PB3_MFP_Msk) | SYS_GPB_MFP_PB3_TC3;
				SYS->ALT_MFP = (SYS->ALT_MFP & ~SYS_ALT_MFP_PB3_Msk)| SYS_ALT_MFP_PB3_TM3_EXT;	
		 #endif			
		 #ifdef PIN_TMR3_CNT_PB11
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB11_MFP_Msk) | SYS_GPB_MFP_PB11_TM3;
		 #endif
		#endif
		
    #ifdef MCU_INTERFACE_SPI0
     #ifdef PIN_SPI0_SS1_PB10
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB10_MFP_Msk) | SYS_PB_H_MFP_PB10_MFP_SPI0_SS1;
		 #endif
     #ifdef PIN_SPI0_SS0_PC0
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC0_MFP_Msk) | SYS_PC_L_MFP_PC0_MFP_SPI0_SS0;
		 #endif
		 #ifdef PIN_SPI0_SCLK_PC1
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC1_MFP_Msk) | SYS_PC_L_MFP_PC1_MFP_SPI0_SCLK;
		 #endif
		 #ifdef PIN_SPI0_MISO0_PC2
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC2_MFP_Msk) | SYS_PC_L_MFP_PC2_MFP_SPI0_MISO0;
		 #endif
		 #ifdef PIN_SPI0_MOSI0_PC3
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC3_MFP_Msk) | SYS_PC_L_MFP_PC3_MFP_SPI0_MOSI0;
		 #endif
		 #ifdef PIN_SPI0_MISO1_PC4
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC4_MFP_Msk) | SYS_PC_L_MFP_PC4_MFP_SPI0_MISO1;
		 #endif
		 #ifdef PIN_SPI0_MOSI1_PC5
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_L_MFP_PC5_MFP_Msk) | SYS_PC_L_MFP_PC5_MFP_SPI0_MOSI1;
		 #endif
		#endif

    #ifdef MCU_INTERFACE_SPI1
      #ifdef PIN_SPI1_SS1_PB9
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB9_MFP_Msk) | SYS_PB_H_MFP_PB9_MFP_SPI1_SS1;
		  #endif
      #ifdef PIN_SPI1_SS0_PC8
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_H_MFP_PC8_MFP_Msk) | SYS_PC_H_MFP_PC8_MFP_SPI1_SS0;
		  #endif
		  #ifdef PIN_SPI1_SCLK_PC9
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_H_MFP_PC9_MFP_Msk) | SYS_PC_H_MFP_PC9_MFP_SPI1_SCLK;
		  #endif
		  #ifdef PIN_SPI1_MISO0_PC10
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_H_MFP_PC10_MFP_Msk) | SYS_PC_H_MFP_PC10_MFP_SPI1_MISO0;
		  #endif
	    #ifdef PIN_SPI1_MOSI0_PC11
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_H_MFP_PC11_MFP_Msk) | SYS_PC_H_MFP_PC11_MFP_SPI1_MOSI0;
		  #endif
		  #ifdef PIN_SPI1_MISO1_PC12
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_H_MFP_PC12_MFP_Msk) | SYS_PC_H_MFP_PC12_MFP_SPI1_MISO1;
		  #endif
		  #ifdef PIN_SPI1_MOSI1_PC13
		    SYS->GPC_MFP = (SYS->GPC_MFP & ~SYS_PC_H_MFP_PC13_MFP_Msk) | SYS_PC_H_MFP_PC13_MFP_SPI1_MOSI1;
			#endif
		#endif	
		
    #ifdef MCU_INTERFACE_SPI2
      #ifdef PIN_SPI2_SS1_PA7
		    SYS->GPA_MFP = (SYS->GPA_MFP & ~SYS_PA_L_MFP_PA7_MFP_Msk) | SYS_PA_L_MFP_PA7_MFP_SPI2_SS1;
		  #endif
      #ifdef PIN_SPI2_SS0_PD0
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD0_MFP_Msk) | SYS_PD_L_MFP_PD0_MFP_SPI2_SS0;
		  #endif
		  #ifdef PIN_SPI2_SCLK_PD1
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD1_MFP_Msk) | SYS_PD_L_MFP_PD1_MFP_SPI2_SCLK;
		  #endif
		  #ifdef PIN_SPI2_MISO0_PD2
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD2_MFP_Msk) | SYS_PD_L_MFP_PD2_MFP_SPI2_MISO0;
		  #endif
	    #ifdef PIN_SPI2_MOSI0_PD3
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD3_MFP_Msk) | SYS_PD_L_MFP_PD3_MFP_SPI2_MOSI0;
		  #endif
		  #ifdef PIN_SPI2_MISO1_PD4
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD4_MFP_Msk) | SYS_PD_L_MFP_PD4_MFP_SPI2_MISO1;
		  #endif
		  #ifdef PIN_SPI2_MOSI1_PD5
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD5_MFP_Msk) | SYS_PD_L_MFP_PD5_MFP_SPI2_MOSI1;
			#endif
		#endif

    #ifdef MCU_INTERFACE_SPI3
      #ifdef PIN_SPI3_SS1_PB14
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB14_MFP_Msk) | SYS_PB_H_MFP_PB14_MFP_SPI3_SS1;
		  #endif
      #ifdef PIN_SPI3_SS0_PD8
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD8_MFP_Msk) | SYS_PD_H_MFP_PD8_MFP_SPI3_SS0;
		  #endif
		  #ifdef PIN_SPI3_SCLK_PD9
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD9_MFP_Msk) | SYS_PD_H_MFP_PD9_MFP_SPI3_SCLK;
		  #endif
		  #ifdef PIN_SPI3_MISO0_PD10
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD10_MFP_Msk) | SYS_PD_H_MFP_PD10_MFP_SPI3_MISO0;
		  #endif
	    #ifdef PIN_SPI3_MOSI0_PD11
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD11_MFP_Msk) | SYS_PD_H_MFP_PD11_MFP_SPI3_MOSI0;
		  #endif
		  #ifdef PIN_SPI3_MISO1_PD12
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD12_MFP_Msk) | SYS_PD_H_MFP_PD12_MFP_SPI3_MISO1;
		  #endif
		  #ifdef PIN_SPI3_MOSI1_PD13
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_H_MFP_PD13_MFP_Msk) | SYS_PD_H_MFP_PD13_MFP_SPI3_MOSI1;
			#endif
		#endif
		
		#ifdef PIN_CAN0_RX_PD6
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD6_MFP_Msk) | SYS_PD_L_MFP_PD6_MFP_CAN0_RX;
    #endif
		#ifdef PIN_CAN0_TX_PD7
		    SYS->GPD_MFP = (SYS->GPD_MFP & ~SYS_PD_L_MFP_PD7_MFP_Msk) | SYS_PD_L_MFP_PD7_MFP_CAN0_TX;
    #endif
		
		#ifdef PIN_CLKO_PB12
		    SYS->GPB_MFP = (SYS->GPB_MFP & ~SYS_PB_H_MFP_PB12_MFP_Msk) |SYS_GPB_MFP_PB12_CLKO;
        SYS->ALT_MFP = (SYS->ALT_MFP & ~SYS_ALT_MFP_PB12_Msk) | SYS_ALT_MFP_PB12_CLKO;
		#endif
		
    SYS_LockReg();  // Lock protected registers
}
