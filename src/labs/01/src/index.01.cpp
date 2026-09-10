/**
 * @file   header.01.hpp
 * @brief  Lab work №01
 */

/*
 * <iostream>
 */
#include "header.01.hpp"

namespace lw01
{
	void index()
	{
		int a = 1; // объявляем переменную a и кладем туда значение 1
		int b = 2; // объявляем переменную a и кладем туда значение 2
		int c;	   // объявляем переменную c, но не инициализируем ее

		__asm__ volatile(
			"add %w[c], %w[a], %w[b]" // сложение a и b, результат в c
			: [c] "=r"(c)			  // выходной операнд: переменная c
			: [a] "r"(a), [b] "r"(b)  // входные операнды: переменные a и b
		);

		printf("\nРезультат вычисления на Assembly:\na + b = %x + %x = %x\n", a, b, c);
		printf("\nРезультат вычисления на C++:\na + b = %x + %x = %x\n", a, b, a + b);

		// finish
		return;
	}

}