
#include "header.utils.hpp"

string readMessage(const string &path)
{
	ifstream file(path);

	if (!file)
	{
		throw runtime_error("Не удаётся открыть файл сообщений: " + path);
	}

	stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

void message(const string &labNumber, const string &key)
{
	const string path =
		"src/labs/" + labNumber + "/docs/messages." + labNumber + ".md";

	ifstream file(path);

	if (!file)
	{
		throw runtime_error("Не удаётся открыть файл сообщений: " + path);
	}

	const string heading = "# " + key;
	string line;
	bool found = false;

	while (getline(file, line))
	{
		if (line == heading)
		{
			found = true;
			continue;
		}

		if (found && line.rfind("# ", 0) == 0)
			break;

		if (found)
		{
			if (line.empty())
				continue;

			cout << line << '\n';
		}
	}
}