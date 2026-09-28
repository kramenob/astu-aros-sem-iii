/**
 * @brief  Task 3 for self work №04
 */

#include "header.04.hpp"

namespace sw04
{

	void taskIII()
	{
		// Define variables
		int a,
			b,
			c,
			minAsm,
			minCpp;

		// Ask user for values
		cout << "Введите через пробел три целых числа: ";
		cin  >> a >> b >> c;

		/**
		 * Assembler solving
		 */
		__asm
		{
			/**
			 * Load a into EAX.
			 * EAX will contain the current minimum value.
			 */
			mov    eax, a

			/**
			 * Compare b with the current minimum.
			 *
			 * CMP updates CPU flags without changing EAX or EBX.
			 */
			mov    ebx, b
			cmp    ebx, eax

			/**
			 * If b >= a, keep a as the current minimum.
			 * If b < a, replace the current minimum with b.
			 */
			jge    check_c
			mov    eax, ebx

		check_c:
			/**
			 * Compare c with the current minimum.
			 */
			mov    ecx, c
			cmp    ecx, eax

			/**
			 * If c >= current minimum, keep the current minimum.
			 * If c < current minimum, replace it with c.
			 */
			jge    store_min
			mov    eax, ecx

		store_min:
			/**
			 * Store the final minimum from EAX into minAsm.
			 */
			mov    minAsm, eax
		}

		/**
		 * C++ solving
		 */
		minCpp = a;

		if (b < minCpp)
		{
			minCpp = b;
		}

		if (c < minCpp)
		{
			minCpp = c;
		}


		cout                                          << endl
			<< "Результат поиска минимального числа:" << endl
			<< "  на Assembler: " << minAsm           << endl
			<< "  на C++:       " << minCpp           << endl
			                                          << endl;
	}

}