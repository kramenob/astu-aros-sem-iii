/**
 *
 * @brief   Entrypoint file. Magic starts here.
 *
 */

/** Everything defined here */
#include "bootstrap.hpp"

/** Main function */
int main()
{

	/**
	 * Set locale to the user's default environment locale.
	 * Using to support UTF-8 characters in the console output, primary for russian text.
	 */
	setlocale(LC_ALL, "");

	/**
	 * Map of available works. Key is the work number, value is the handler function.
	 * The handler function is a function that will be called when the work is selected.
	 */

	/* Laboratory works */
	map<int, Handler> labs = {};

	/* Self works */
	map<int, Handler> sels = {};

	cout << "Доступные виды работ:" << endl
		 << " 1. Лабораторная (" << labs.size() << ");" << endl
		 << " 2. Самостоятельная (" << sels.size() << ");" << endl
		 << endl;

	/**
	 * Prompt the user to select a work type.
	 * If the user enters an invalid number, prompt again.
	 */
	int mode = 0;
	while (mode < 1 || mode > 2)
	{
		cout << "Выберите вид работы [1-2]: ";
		cin >> mode;
	}

	auto &work = (mode == 1)
					 ? labs
					 : sels;

	if (work.empty())
	{
		cout << "Нет доступных работ." << endl;
		return 0;
	}

	int choice = 0;

	while (true)
	{
		cout << "Выберите номер работы ["
			 << work.begin()->first
			 << "-"
			 << work.rbegin()->first
			 << "]: ";

		if (cin >> choice && work.find(choice) != work.end())
			break;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Работа не найдена!" << endl;
	}

	work.at(choice)();

	/** Pause the console before exiting */
	cout << endl
		 << "Press Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait only for Enter
	cin.get();											 // Wait for the user to close the console
	return 0;											 // Return success
}
