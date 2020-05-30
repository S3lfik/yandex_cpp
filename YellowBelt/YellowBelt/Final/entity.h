#pragma once
#include "date.h"

struct Entity
{
	Date date;
	std::string event;
};

std::ostream& operator<<(std::ostream& os, const Entity& entry);