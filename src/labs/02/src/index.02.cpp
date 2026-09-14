/**
 * @file   header.02.hpp
 * @brief  Lab work №02
 */

#include "header.02.hpp"

namespace lw02
{

	void index()
	{

		// print message introduction in program
		message(CURRENT_WORK_TYPE, CURRENT_NUMBER, "intro");

		// #include <iostream>
		// #include <conio.h>

		setlocale(LC_ALL, "Russian"); // установка русского алфавита

		// Вычислить: xy - (x^3 - y^3) / (x^2 + 2xy + y^2)

		// -- тестовые значения --
		// для x = 5, y = 0 ожидается ответ -5
		// для x = 2, y = -1 ожидается ответ -11
		// для x = 1, y = 1 ожидается ответ 1
		// для x = 10, y = 1 ожидается ответ 2

		int x, y;

		int chisl = 0, // переменная для хранения числителя дроби, равного x^3 - y^3
			zn    = 0, // переменная для хранения знаменателя дроби, равного x^2 + 2xy + y^2
			x2,		   // переменная для хранения x^2
			y2,		   // переменная для хранения y^2
			xy,		   // переменная для хранения x*y
			resa = 0;  // результат вычисления выражения на Ассемблере

		int resc; // результат вычисления выражения на C++

		cout << "Введите x: ";
		cin >> x;

		cout << "Введите y: ";
		cin >> y;

		__asm
		{
			mov eax, x   // поместили x в регистр eax
			mov ebx, eax // сохранили x в регистре ebx

			imul eax, y // содержимое регистра eax умножили на y
			mov xy, eax // содержимое регистра eax занесли в ячейку xy

			mov eax, ebx // содержимое регистра ebx (значение переменной x)
					     // скопировали в регистр eax

			imul eax, ebx // значение регистра eax умножили на значение регистра ebx
					      // (т. е. x*x = x^2)

			mov x2, eax // содержимое регистра eax занесли в ячейку x2

			mov eax, y  // поместили y в регистр eax
			imul eax, y // умножили содержимое регистра eax на y, получили y^2
			mov y2, eax // содержимое регистра eax занесли в ячейку y2

			add eax, x2 // eax := eax + значение переменной x2
					    // получили x^2 + y^2

			add eax, xy
			add eax, xy // eax := eax + значение переменной xy
					    // получили x^2 + 2xy + y^2

			mov zn, eax // содержимое регистра eax занесли в ячейку zn
					    // (знаменатель)

			mov eax, x2   // поместили в регистр eax содержимое ячейки x2
			imul eax, ebx // умножили содержимое регистра eax на x, получили x^3

			mov ebx, y2 // поместили в регистр ebx содержимое ячейки y2
			imul ebx, y // умножили содержимое регистра ebx на y, получили y^3

			sub eax, ebx // eax := eax - ebx, разность x^3 - y^3

			mov chisl, eax // содержимое регистра eax занесли в ячейку chisl
					       // (числитель)

			cdq // преобразовали двойное слово в учетверённое
				// -- без этого происходит переполнение !!!

			idiv zn // edx:eax := eax:edx / zn с учётом знака

			mov ebx, xy // поместили в регистр ebx содержимое ячейки xy

			sub ebx, eax // вычли из содержимого регистра ebx содержимое
						 // регистра eax

			// -- ответ готов --

			mov resa, ebx // содержимое регистра ebx занесли в ячейку resa
		}

		cout << "Иванов Иван. Лабораторная работа № 4. Вариант №0."
			 << endl;

		cout << "Результаты вычислений на Assembler:" << endl;

		cout << "Слагаемое xy = "    << xy    << endl;
		cout << "Числитель chisl = " << chisl << endl;
		cout << "Знаменатель zn = "  << zn    << endl;
		cout << "Результат res = "   << resa  << endl
			 << endl;

		// -- здесь вычисление формулы на C++ --

		xy    = x * y;
		chisl = x * x * x - y * y * y;
		zn    = x * x + 2 * x * y + y * y;

		resc = xy - chisl / zn;

		cout << "Результаты вычислений на C++:" << endl;

		cout << "Слагаемое xy = "    << xy    << endl;
		cout << "Числитель chisl = " << chisl << endl;
		cout << "Знаменатель zn = "  << zn    << endl;
		cout << "Результат res = "   << resc  << endl;

		// system("pause");
		// return 0;

		// finish
		return;
	}

}