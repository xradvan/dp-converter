/**
 *@file UIData.h
 *@author Bc. Peter Radvan
 *@brief Structure to hold data for the UI
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <variant>
#include <vector>

struct Header
{
	std::string text;
};

struct Header1 : Header { friend std::ostream &operator<<(std::ostream &os, const Header1 &h); };
struct Header2 : Header { friend std::ostream &operator<<(std::ostream &os, const Header2 &h); };
struct Separator {};

using UIData = std::vector<std::pair<std::string, std::variant<
		Header1,
		Header2,
		Separator,
		int,
		float,
		std::string,
		std::vector<int>
	>>>;
