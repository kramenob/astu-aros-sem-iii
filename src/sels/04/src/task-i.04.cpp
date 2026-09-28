/**
 * @brief  Task 1 for self work №04
 */

#include "header.04.hpp"

namespace sw04
{

	void taskI()
	{
		// Define variables
		int a,
			b,
			x,
			yAsm,
			yCpp;

		// Ask user for values
		cout << "Введите через пробел a, b and x: ";
		cin  >> a >> b >> x;

		/**
		 * Assembler solving
		 */
		__asm
		{
			/**
			 * Load x into EAX.
			 * EAX is the 32-bit general-purpose register used for the integer value.
			 */
			mov    eax, x

			/**
			 * Check whether x is positive.
			 */
			cmp    eax, 0
			jg     x_positive

			/**
			 * Check whether x is negative.
			 */
			jl     x_negative

			/**
			 * x is zero, so y = 1.
			 */
			mov    eax, 1
			mov    yAsm, eax
			jmp    task_i_done

		x_positive:
			/**
			 * Calculate y = a + b * x.
			 * EAX = b * x.
			 */
			mov    eax, b
			imul   eax, x

			/**
			 * Add a to obtain y = a + b * x.
			 */
			add    eax, a
			mov    yAsm, eax
			jmp    task_i_done

		x_negative:
			/**
			 * Calculate y = x * x.
			 */
			mov    eax, x
			imul   eax, x
			mov    yAsm, eax

		task_i_done:
		}

		/**
		 * C++ solving
		 */
		if (x > 0)
			yCpp = a + b * x;
		else if (x < 0)
			yCpp = x * x;
		else
			yCpp = 1;


		cout                            << endl
			<< "Результаты вычислений:" << endl
			<< "  на Assembler:"        << endl
			<< "    y = " << yAsm       << endl
			<< "  на C++:"              << endl
			<< "    y = " << yCpp       << endl
			                            << endl;
	}

}