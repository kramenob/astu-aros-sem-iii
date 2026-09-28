/**
 * @brief  Task 5 for self work №04
 */

#include "header.04.hpp"

namespace sw04
{

	void taskV()
	{
		// Define variables
		int a,
			b,
			c,

			distBAsm,
			distCAsm,

			distBCpp,
			distCCpp;

		char pointAsm,
			 pointCpp;

		// Ask user for values
		cout << "Введите координаты через пробел A, B и C: ";
		cin  >> a >> b >> c;

		/**
		 * Assembler solving
		 */
		__asm
		{
			/**
			 * Load B into EAX.
			 *
			 * EAX = B.
			 */
			mov    eax, b

			/**
			 * Subtract A from B.
			 *
			 * EAX = B - A.
			 */
			sub    eax, a

			/**
			 * Check whether B - A is negative.
			 */
			cmp    eax, 0
			jge    distance_b_ready

			/**
			 * Change the sign of B - A.
			 *
			 * EAX = |B - A|.
			 */
			neg    eax

		distance_b_ready:

			/**
			 * Store |B - A| in distBAsm.
			 */
			mov    distBAsm, eax

			/**
			 * Load C into EAX.
			 *
			 * EAX = C.
			 */
			mov    eax, c

			/**
			 * Subtract A from C.
			 *
			 * EAX = C - A.
			 */
			sub    eax, a

			/**
			 * Check whether C - A is negative.
			 */
			cmp    eax, 0
			jge    distance_c_ready

			/**
			 * Change the sign of C - A.
			 *
			 * EAX = |C - A|.
			 */
			neg    eax

		distance_c_ready:

			/**
			 * Store |C - A| in distCAsm.
			 */
			mov    distCAsm, eax

			/**
			 * Compare the two Assembly distances.
			 *
			 * EAX = distBAsm.
			 */
			mov    eax, distBAsm
			cmp    eax, distCAsm

			/**
			 * If distBAsm >= distCAsm,
			 * C is closer to A or the distances are equal.
			 */
			jge    point_c_asm

			/**
			 * B is closer to A.
			 */
			mov    pointAsm, 'B'
			jmp    point_asm_ready

		point_c_asm:

			/**
			 * C is closer to A or both distances are equal.
			 */
			mov    pointAsm, 'C'

		point_asm_ready:
		}

		/**
		 * C++ solving
		 */
		distBCpp = abs(b - a);
		distCCpp = abs(c - a);

		if (distBCpp < distCCpp)
			pointCpp = 'B';
		else
			pointCpp = 'C';


		cout                                                                                            << endl
			<< "Результат поиска ближайшей точки:"                                                      << endl
			<< "  на Assembler: " << pointAsm << " (" << (pointAsm == 'B' ? distBAsm : distCAsm) << ")" << endl
			<< "  на C++:       " << pointCpp << " (" << (pointCpp == 'B' ? distBCpp : distCCpp) << ")" << endl
		                                                                                                << endl;
	}

}