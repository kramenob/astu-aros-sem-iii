#include "../bootstrap.hpp"

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
		(labNumber == "main")
			? "src/docs/messages.main.md"
			: "src/labs/" + labNumber + "/docs/messages." + labNumber + ".md";

	ifstream file(path);

	if (!file)
	{
		throw runtime_error("Не удаётся открыть файл сообщений: " + path);
	}

	const string heading = "# " + key;
	string line;
	bool found = false;
	bool previousEmpty = false;

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
			{
				if (!previousEmpty)
					cout << '\n';

				previousEmpty = true;
				continue;
			}

			previousEmpty = false;

			string output = line;

			if (author)
				while (output.find("${author}") != string::npos)
					output.replace(output.find("${author}"), 9, author);

			if (author_full)
				while (output.find("${author_full}") != string::npos)
					output.replace(output.find("${author_full}"), 14, author_full);

			if (group)
				while (output.find("${group}") != string::npos)
					output.replace(output.find("${group}"), 8, group);

			if (supervisor)
				while (output.find("${supervisor}") != string::npos)
					output.replace(output.find("${supervisor}"), 13, supervisor);

			if (year)
				while (output.find("${year}") != string::npos)
					output.replace(output.find("${year}"), 7, year);

			if (env_variant)
				while (output.find("${variant}") != string::npos)
					output.replace(output.find("${variant}"), 10, env_variant);

			cout << output << '\n';
		}
	}
}