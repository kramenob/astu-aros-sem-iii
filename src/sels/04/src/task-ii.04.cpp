/**
 * @brief  Task 2 for self work №04
 */

#include "header.04.hpp"

namespace sw04
{

	void taskII()
	{
		// Define variables
		int n,
			rAsm,
			rCpp;

		// Ask user for values
		cout << "Введите целое число: ";
		cin  >> n;

		/**
		 * Assembler solving
		 */
		__asm
		{
			/**
			 * Load n into EAX.
			 * EAX is the 32-bit general-purpose register used for the integer value.
			 */
			mov    eax, n

			/**
			 * Compare n with 0.
			 * CMP subtracts the second operand from the first only for flags.
			 */
			cmp    eax, 0

			/**
			 * If n <= 0, skip the increment and keep n unchanged.
			 */
			jle    not_positive

			/**
			 * n is positive, so increase it by 1.
			 * INC increments the destination integer by one.
			 */
			inc    eax

			/**
			 * Store the Assembly result in rAsm.
			 */
			mov    rAsm, eax
			jmp    result

		not_positive:
			/**
			 * n is zero or negative, so keep its original value.
			 */
			mov    rAsm, eax

		result:
		}

		/**
		 * C++ solving
		 */
		if (n > 0)
		{
			cout << "  Число положительно. Увеличим его на 1." << endl;
			n++;
		}
		else {
			cout << "  Число отрицательное. Не изменяем его." << endl;
		}
		rCpp = n;


		cout                              << endl
			<< "Результаты вычислений:"   << endl
			<< "  на Assembler: " << rAsm << endl
			<< "  на C++:       " << rCpp << endl
			                              << endl;
	}

}