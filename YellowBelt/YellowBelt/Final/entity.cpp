#include "entity.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Entity& entry)
{
	os << entry.date << " " << entry.event;
	return os;
}