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
		message(CURRENT_NUMBER, "intro");

		int a = 1; // define a
		int b = 2; // define b
		int c = 3; // define c
		int d = 4; // define d
		int Y;	   // define Y

		// Variant 14: Y=d+a-b+c
		__asm__ volatile(
			"add %w[Y], %w[d], %w[a]\n"
			"sub %w[Y], %w[Y], %w[b]\n"
			"add %w[Y], %w[Y], %w[c]"
			: [Y] "=r"(Y)
			: [d] "r"(d),
			  [a] "r"(a),
			  [b] "r"(b),
			  [c] "r"(c));

		// print results
		printf("\nРезультат вычисления на Assembly:\nd + a - b + c = %x + %x - %x + %x = %x\n", d, a, b, c, Y);
		printf("\nРезультат вычисления на C++:\nd + a - b + c = %x + %x - %x + %x = %x\n", d, a, b, c, (d + a - b + c));

		// finish
		return;
	}

}