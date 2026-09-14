/**
 * @brief  Self work №02
 */

#include "header.02.hpp"

namespace sw02
{

	void index()
	{

		// print message introduction in program
		message(CURRENT_WORK_TYPE, CURRENT_NUMBER, "intro");

		// define vars
		int x,
			Y;

		// run cycle while use want
		while (true)
		{
			cout << "Введите значение x: ";
			cin  >> x;

			// define var per fractional expression
			int numerator,
				denominator;

			// Calculate numerator: x^2 - 4x + 4
			__asm
			{
				mov  eax, x;
				imul eax, x; // eax = x^2

				mov  ebx, x;
				imul ebx, 4; // ebx = 4x

				sub eax, ebx; // eax = x^2 - 4x
				add eax,   4; // eax = x^2 - 4x + 4

				mov numerator, eax;
			}

			// Calculate denominator: (x + 5)^2 - 49
			__asm
			{
				mov  eax,   x;
				add  eax,   5; // eax =  x + 5
				imul eax, eax; // eax = (x + 5)^2
				sub  eax,  49; // eax = (x + 5)^2 - 49

				mov denominator, eax;
			}

			if (denominator == 0)
			{
				cout << "Ошибка: деление на 0.\n";
				continue;
			}

			Y = numerator / denominator;

			cout << "Y = " << Y << '\n';

			char answer;
			cout << "Попробуем ещё? (y/N): ";
			cin  >> answer;

			if (answer != 'y' && answer != 'Y')
			{
				break;
			}
		}

		// finish
		return;
	}

}