/**
 * @brief  Task 4 for self work №04
 */

#include "header.04.hpp"

namespace sw04
{

	void taskIV()
	{
		// Define variables
		int a,
			b,
			c,
			posCountAsm = 0,
			posCountCpp = 0;

		// Ask user for values
		cout << "Введите через пробел три целых числа, снова: ";
		cin  >> a >> b >> c;

		/**
		 * Assembler solving
		 */
		__asm
		{
			/**
			 * Clear EAX.
			 * EAX will contain the number of positive numbers.
			 */
			xor    eax, eax

			/**
			 * Check a.
			 */
			cmp    a, 0
			jle    check_b

			/**
			 * a is positive, so increase the counter.
			 */
			inc    eax

		check_b:
			/**
			 * Check b.
			 */
			cmp    b, 0
			jle    check_c

			/**
			 * b is positive, so increase the counter.
			 */
			inc    eax

		check_c:
			/**
			 * Check c.
			 */
			cmp    c, 0
			jle    store_count

			/**
			 * c is positive, so increase the counter.
			 */
			inc    eax

		store_count:
			/**
			 * Store the final number of positive values.
			 */
			mov    posCountAsm, eax
		}

		/**
		 * C++ solving
		 */
		if (a > 0)
		{
			posCountCpp++;
		}
		if (b > 0)
		{
			posCountCpp++;
		}
		if (c > 0)
		{
			posCountCpp++;
		}


		cout                                                   << endl
			<< "Результат поиска количества позитивных чисел:" << endl
			<< "  на Assembler: " << posCountAsm               << endl
			<< "  на C++:       " << posCountCpp               << endl
			                                                   << endl;
	}

}