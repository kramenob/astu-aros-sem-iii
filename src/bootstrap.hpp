/**
 * @file   bootstrap.hpp
 * @brief  Header file for bootstrap
 */

#ifndef BOOTSTRAP_HPP
#define BOOTSTRAP_HPP

/**
 * Include this header file only once per compilation unit,
 * no matter how many times it’s #included
 */
#pragma once

/** Standard library headers */
#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

/** Using namespace std */
using namespace std;

/** Environment configuration */
inline const char *author = getenv("author");
inline const char *author_full = getenv("author_full");
inline const char *group = getenv("group");
inline const char *supervisor = getenv("supervisor");
inline const char *year = getenv("year");
inline const char *env_variant = getenv("variant");

/** Utility headers */
#include "utils/header.utils.hpp"

/** Works headers */
#include "labs/header.labs.hpp"
#include "sels/header.sels.hpp"

using Handler = function<void()>;

#endif // BOOTSTRAP_HPP