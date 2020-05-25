#pragma once
#include <string>
#include "date.h"

struct Entity
{};

class Node
{
public:
	virtual bool Evaluate(const Date& date, const std::string& event);
};

class EmptyNode : public Node
{};

class DateComparisonNode : public Node
{};

class EventComparisonNode : public Node
{};

class LogicalOperationNode : public Node
{};