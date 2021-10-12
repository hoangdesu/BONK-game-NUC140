/*
 *
 * RMIT University - School of Science and Technology
 * EEET2481 - Embedded System Design and Implementation
 * Assignment: Final Group Assignment
 * Submission date: Sep 24, 2021
 * Design 2: "BONK!" game
 * Team: We still thinking
 * 
 */ 

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"
#include <time.h>
#include <stdlib.h>
#include "sprites.h"
#include "Draw2D.h"


//------------------------------------------------------------------------------------------------------------------------------------
/* -------------------- Function headers --------------- */
//------------------------------------------------------------------------------------------------------------------------------------

// User-defined functions
int randInt(int max);
void displayWelcome();
void playGame();
void getReady();
void gameOver();
void displayTutorial();
void clearActiveSprite();
void drawGroundSprites();
void scanKeyPad();

// System functions
void System_Config(void);
void SPI3_Config(void);
void LCD_start(void);
void LCD_command(unsigned char temp);
void LCD_data(unsigned char temp);
void LCD_clear(void); 
void LCD_SetAddress(uint8_t PageAddr, uint8_t ColumnAddr);
void KeyPadEnable(void);
uint8_t KeyPadScanning(void);
void SysTickDelay(uint32_t SYSTICK_LVR);



//------------------------------------------------------------------------------------------------------------------------------------
/* -------------------- Global variables --------------- */
//------------------------------------------------------------------------------------------------------------------------------------

typedef enum
{
	WELCOME_SCR,
	TUTORIAL_SCR,
	READY_SCR,
	GAMEPLAY,
	GAMEOVER
} STATES;

STATES gameState;

int score = 0;
int lives = 5;
int spriteDelayTime = 4000000;
int randomIndex;
int highScore = 0;

char scoreChar[3];
char highScoreChar[3];
char livesChar[2];

int position_x = 0;
int position_y = 0;

uint8_t key_pad = 0;
int correctKeyPressed = 0;


//------------------------------------------------------------------------------------------------------------------------------------
/*********************************** [ MAIN PROGRAM ] ************************************/
//------------------------------------------------------------------------------------------------------------------------------------

int main(void)
{
	// start system configs
	System_Config();
	SPI3_Config();
	
	// start LCD configs
	LCD_start();
	LCD_clear();

	// set starting game state
	gameState = WELCOME_SCR;

	while (1)
	{
		switch (gameState)
		{
			case WELCOME_SCR:
				displayWelcome();
				break;

			case TUTORIAL_SCR:
				displayTutorial();
				break;

			case READY_SCR:
				getReady();
				break;

			case GAMEPLAY:
				playGame();
				break;

			case GAMEOVER:
				gameOver();
				break;
			
			default:
				break;
		}
	}

	return 0;
}



//------------------------------------------------------------------------------------------------------------------------------------
//* ------------------ Main state functions ------------- */
//------------------------------------------------------------------------------------------------------------------------------------


void displayWelcome()
{
	draw_Bmp64x64(30, 0, 1, 0, bonk_top);
	while (1)
	{
		key_pad = KeyPadScanning();

		// blinking animation
		draw_Bmp64x64(30, 0, 1, 0, bonk_bot);
		SysTickDelay(3000000);
		clear_LCD();
		key_pad = KeyPadScanning();
		draw_Bmp64x64(30, 0, 1, 0, bonk_top);
		SysTickDelay(3000000);

		if (key_pad > 0)
		{
			gameState = TUTORIAL_SCR;
			clear_LCD();
			break;
		}
	}
}


void displayTutorial()
{
	printS(0, 0, "1  2  3");
	printS(0, 25, "4  5  6");
	printS(0, 50, "7  8  9");
	SysTickDelay(1000000);
	printS_5x7(65, 8, "Press keypad");
	printS_5x7(65, 25, "when");
	draw_Bmp16x16(90, 17, 1, 0, cheem);
	printS_5x7(65, 42, "appears");

	while (1)
	{	
		key_pad = KeyPadScanning();
		
		if (key_pad > 0)
		{
			gameState = READY_SCR;
			clear_LCD();
			break;
		}

	}
}


void getReady()
{
	printS(30, 25, "GET READY!");
	SysTickDelay(7000000);
	LCD_clear();
	printS(60, 25, "3");
	SysTickDelay(6000000);
	printS(60, 25, "2");
	SysTickDelay(6000000);
	printS(60, 25, "1");
	SysTickDelay(6000000);
	LCD_clear();
	gameState = GAMEPLAY;
}


void playGame()
{
	// reset game stats
	clear_LCD();
	score = 0;
	lives = 5;
	spriteDelayTime = 4000000;

	// display game stats
	printS_5x7(85, 8, "Score:");
	printS(93, 20, "0");
	printS_5x7(85, 40, "Lives:");
	printS(93, 49, "5");

	while (1)
	{
		drawGroundSprites();
		SysTickDelay(spriteDelayTime);

		// get a random index
		randomIndex = randInt(9);

		// calculate a random cheem appear coordinates from random index
		position_x = randomIndex % 3;
		position_y = randomIndex / 3;

		// clear ground
		clearActiveSprite(); 

		// draw cheem at x,y coordinates
		draw_Bmp16x16(24*position_x+3, 22*position_y+1, 1, 1, cheem);
		
		scanKeyPad();			// scan 1
		SysTickDelay(spriteDelayTime);
		scanKeyPad();			// scan 2
		clearActiveSprite();	// clear cheem
		scanKeyPad();			// scan 3

		// update score and lives
		if (correctKeyPressed == 1)
		{
			++score;
		}
		else
		{
			--lives;
		}

		// convert game stats from int to char
		sprintf(scoreChar, "%d", score);
		sprintf(livesChar, "%d", lives);

		// display score and lives
		printS(93, 20, scoreChar);
		printS(93, 49, livesChar);

		// reset keyPressed flag
		correctKeyPressed = 0;	

		// game gets faster over time
		if (spriteDelayTime > 300000)
		{
			spriteDelayTime -= 60000; // 1.5% increase
		}
		else
		{
			spriteDelayTime = 4000000;
		}

		// lose condition
		if (lives == 0)
		{
			gameState = GAMEOVER;
			LCD_clear();
			break;
		}

		// update high score
		if (score > highScore)
		{
			highScore = score;
		}

	}
}


void gameOver()
{
	clear_LCD();
	// display score
	printS_5x7(0, 0, "Your score");
	printS_5x7(10, 10, scoreChar);
	sprintf(highScoreChar, "%d", highScore);
	printS_5x7(77, 0, "High score");
	printS_5x7(107, 10, highScoreChar);

	// BONK!!!
	draw_Bmp32x16(49, 18, 1, 0, bonk_end);

	while (1)
	{
		key_pad = KeyPadScanning();
		
		// blinking animation
		printS_5x7(25, 40, "Press any key to");
		printS_5x7(40, 50, "play again");
		SysTickDelay(2000000);
		clear_LCD();
		key_pad = KeyPadScanning();
		draw_Bmp32x16(49, 18, 1, 0, bonk_end);
		printS_5x7(0, 0, "Your score");
		printS_5x7(10, 10, scoreChar);
		sprintf(highScoreChar, "%d", highScore);
		printS_5x7(77, 0, "High score");
		printS_5x7(107, 10, highScoreChar);
		SysTickDelay(2000000);

		if (key_pad > 0)
		{
			gameState = READY_SCR;
			clear_LCD();
			break;
		}

	}
}



//------------------------------------------------------------------------------------------------------------------------------------
//* ------------------ Utility functions ------------- */
//------------------------------------------------------------------------------------------------------------------------------------

// Get a random integer from 0 -> max-1
int randInt(int max)
{
    return rand() % max;
}

void clearActiveSprite()
{
	for (int y = 0; y < 16; y++)
	{
		for (int x = 0; x < 16; x++)
		{
			draw_Pixel(24 * position_x + 3 + x, 22 * position_y + 1 + y, 0, 0);
		}
	}
}

void drawGroundSprites()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			draw_Bmp16x16(24 * x + 3, 22 * y + 1, 1, 0, ground);
		}
	}
}

void scanKeyPad()
{
	key_pad = KeyPadScanning();

	// detect correct key pressed
	if (key_pad - 1 == randomIndex)
	{
		correctKeyPressed = 1;
	}
}



//------------------------------------------------------------------------------------------------------------------------------------
//* ------------------ System functions ------------- */
//------------------------------------------------------------------------------------------------------------------------------------
void LCD_start(void)
{
	LCD_command(0xE2); // Set system reset
	LCD_command(0xA1); // Set Frame rate 100 fps
	LCD_command(0xEB); // Set LCD bias ratio E8~EB for 6~9 (min~max)
	LCD_command(0x81); // Set V BIAS potentiometer
	LCD_command(0xA0); // Set V BIAS potentiometer: A0 ()
	LCD_command(0xC0);
	LCD_command(0xAF); // Set Display Enable
}

void LCD_command(unsigned char temp)
{
	SPI3->SSR |= 1ul << 0;
	SPI3->TX[0] = temp;
	SPI3->CNTRL |= 1ul << 0;
	while (SPI3->CNTRL & (1ul << 0))
		;
	SPI3->SSR &= ~(1ul << 0);
}

void LCD_data(unsigned char temp)
{
	SPI3->SSR |= 1ul << 0;
	SPI3->TX[0] = 0x0100 + temp;
	SPI3->CNTRL |= 1ul << 0;
	while (SPI3->CNTRL & (1ul << 0))
		;
	SPI3->SSR &= ~(1ul << 0);
}

void LCD_clear(void)
{
	int16_t i;
	LCD_SetAddress(0x0, 0x0);
	for (i = 0; i < 132 * 8; i++)
	{
		LCD_data(0x00);
	}
}

void LCD_SetAddress(uint8_t PageAddr, uint8_t ColumnAddr)
{
	LCD_command(0xB0 | PageAddr);
	LCD_command(0x10 | (ColumnAddr >> 4) & 0xF);
	LCD_command(0x00 | (ColumnAddr & 0xF));
}

void KeyPadEnable(void)
{
	GPIO_SetMode(PA, BIT0, GPIO_MODE_QUASI);
	GPIO_SetMode(PA, BIT1, GPIO_MODE_QUASI);
	GPIO_SetMode(PA, BIT2, GPIO_MODE_QUASI);
	GPIO_SetMode(PA, BIT3, GPIO_MODE_QUASI);
	GPIO_SetMode(PA, BIT4, GPIO_MODE_QUASI);
	GPIO_SetMode(PA, BIT5, GPIO_MODE_QUASI);
}

uint8_t KeyPadScanning(void)
{
	PA0 = 1;
	PA1 = 1;
	PA2 = 0;
	PA3 = 1;
	PA4 = 1;
	PA5 = 1;
	if (PA3 == 0)
		return 1;
	if (PA4 == 0)
		return 4;
	if (PA5 == 0)
		return 7;
	PA0 = 1;
	PA1 = 0;
	PA2 = 1;
	PA3 = 1;
	PA4 = 1;
	PA5 = 1;
	if (PA3 == 0)
		return 2;
	if (PA4 == 0)
		return 5;
	if (PA5 == 0)
		return 8;
	PA0 = 0;
	PA1 = 1;
	PA2 = 1;
	PA3 = 1;
	PA4 = 1;
	PA5 = 1;
	if (PA3 == 0)
		return 3;
	if (PA4 == 0)
		return 6;
	if (PA5 == 0)
		return 9;
	return 0;
}

void System_Config(void)
{
	SYS_UnlockReg(); // Unlock protected registers
	CLK->PWRCON |= (0x01ul << 0);
	while (!(CLK->CLKSTATUS & (1ul << 0)))
		;
	//PLL configuration starts
	CLK->PLLCON &= ~(1ul << 19); //0: PLL input is HXT
	CLK->PLLCON &= ~(1ul << 16); //PLL in normal mode
	CLK->PLLCON &= (~(0x01FFul << 0));
	CLK->PLLCON |= 48;
	CLK->PLLCON &= ~(1ul << 18); //0: enable PLLOUT
	while (!(CLK->CLKSTATUS & (0x01ul << 2)))
		;
	//PLL configuration ends
	//clock source selection
	CLK->CLKSEL0 &= (~(0x07ul << 0));
	CLK->CLKSEL0 |= (0x02ul << 0);
	//clock frequency division
	CLK->CLKDIV &= (~0x0Ful << 0);
	//STCLK as SysTick clock source
	SysTick->CTRL &= ~(0x01ul << 2);
	//STCLK = HCLK/2 = 1MHz
	CLK->CLKSEL0 &= ~(0x07ul << 3);
	CLK->CLKSEL0 |= (0x02ul << 3);
	//enable clock of SPI3
	CLK->APBCLK |= 1ul << 15;
	SYS_LockReg(); // Lock protected registers
}

void SPI3_Config(void)
{
	SYS->GPD_MFP |= 1ul << 11;	 //1: PD11 is configured for alternative function
	SYS->GPD_MFP |= 1ul << 9;	 //1: PD9 is configured for alternative function
	SYS->GPD_MFP |= 1ul << 8;	 //1: PD8 is configured for alternative function
	SPI3->CNTRL &= ~(1ul << 23); //0: disable variable clock feature
	SPI3->CNTRL &= ~(1ul << 22); //0: disable two bits transfer mode
	SPI3->CNTRL &= ~(1ul << 18); //0: select Master mode
	SPI3->CNTRL &= ~(1ul << 17); //0: disable SPI interrupt
	SPI3->CNTRL |= 1ul << 11;	 //1: SPI clock idle high
	SPI3->CNTRL &= ~(1ul << 10); //0: MSB is sent first
	SPI3->CNTRL &= ~(3ul << 8);	 //00: one transmit/receive word will be executed in one data transfer
	SPI3->CNTRL &= ~(31ul << 3); //Transmit/Receive bit length
	SPI3->CNTRL |= 9ul << 3;	 //9: 9 bits transmitted/received per data transfer
	SPI3->CNTRL |= (1ul << 2);	 //1: Transmit at negative edge of SPI CLK
	SPI3->DIVIDER = 0;			 // SPI clock divider. SPI clock = HCLK / ((DIVIDER+1)*2). HCLK = 50 MHz
}

void SysTickDelay(uint32_t SYSTICK_LVR)
{
	//SysTick Reload Value
	SysTick->LOAD = SYSTICK_LVR - 1;
	//SysTick to count from LVR
	SysTick->VAL = 0;
	//Start SysTick
	SysTick->CTRL |= (0x01ul << 0);
	while (!(SysTick->CTRL & (0x01ul << 16)))
		;
}
