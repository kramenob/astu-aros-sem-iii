/**
 * @brief  Self work №03
 */

#include "header.03.hpp"

namespace sw03
{

	void index()
	{

		// print message introduction in program
		message(CURRENT_WORK_TYPE, CURRENT_NUMBER, "intro");
		message(CURRENT_WORK_TYPE, CURRENT_NUMBER, "knowledge");

		// define vars
		double x,
			   Y;

		// constants
		double four      =  4.0,
			   five      =  5.0,
			   fortyNine = 49.0;

		// run cycle while user wants
		while (true)
		{
			cout << "Введите значение x: ";
			cin  >> x;

			// define vars per fractional expression
			double numerator,
			  	   denominator;

			// Calculate numerator: x^2 - 4x + 4
			__asm
			{
				fld  x;                // ST(0) = x
				fmul x;                // ST(0) = x^2

				fld  x;                // ST(0) = x, ST(1) = x^2
				fmul four;             // ST(0) = 4x

				fsubp st(1), st(0);    // ST(0) = x^2 - 4x

				fld  four;             // ST(0) = 4
				faddp st(1), st(0);    // ST(0) = x^2 - 4x + 4

				fstp numerator;        // numerator = result
			}

			// Calculate denominator: (x + 5)^2 - 49
			__asm
			{
				fld  x;                // ST(0) = x
				fadd five;             // ST(0) = x + 5
				fmul st(0), st(0);     // ST(0) = (x + 5)^2
				fsub fortyNine;        // ST(0) = (x + 5)^2 - 49

				fstp denominator;      // denominator = result
			}

			if (denominator == 0.0)
			{
				cout << "Ошибка: деление на 0.\n";
				continue;
			}

			// Calculate Y = numerator / denominator
			__asm
			{
				fld  numerator;        // ST(0) = numerator
				fld  denominator;      // ST(0) = denominator
				fdivp st(1), st(0);    // ST(0) = numerator / denominator

				fstp Y;                // Y = result
			}

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