/**
 * @brief  Self work №01
 */

/*
 * <iostream>
 */
#include "header.01.hpp"

namespace sw01
{

	void index()
	{

		// print message introduction in program
		message(CURRENT_WORK_TYPE, CURRENT_NUMBER, "intro");

		int a = 1; // define a
		int b = 2; // define b
		int c = 3; // define c
		int d = 4; // define d
		int Y;	   // define Y

		// Variant 14: Y=d+a-b+c
		__asm // assembly insertion
		{
			// eax - x86 32-bit register
			mov eax, d; // load d into eax
			add eax, a; // eax = d + a
			sub eax, b; // eax = d + a - b
			add eax, c; // eax = d + a - b + c
			mov Y, eax; // store the result in Y
		}

		// print results
		printf("\nРезультат вычисления на Assembly:\nd + a - b + c = %x + %x - %x + %x = %x\n", d, a, b, c, Y);
		printf("\nРезультат вычисления на C++:\nd + a - b + c = %x + %x - %x + %x = %x\n", d, a, b, c, (d + a - b + c));

		// finish
		return;
	}

}