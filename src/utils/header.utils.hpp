#ifndef HEADER_UTILS_HPP
#define HEADER_UTILS_HPP

#pragma once

#include "../bootstrap.hpp"

string readMessage(const string &path);
void message(
	const string &workType,
	const string &number,
	const string &key
);

#endif