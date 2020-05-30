#pragma once
#include <string>
#include <memory>
#include "date.h"

struct Entity
{};

enum Comparison
{
	NotEqual = 0,
	Equal,
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual	
};

enum LogicalOperation
{
	Or,
	And
};

class Node
{
public:
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node
{
	bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node
{
public:
	DateComparisonNode(Comparison comp, const Date& date);

	bool Evaluate(const Date& date, const std::string& event) const override;

private:
	Comparison m_comp;
	Date m_date;
};

class EventComparisonNode : public Node
{
public:
	EventComparisonNode(Comparison comp, const std::string& ev);

	bool Evaluate(const Date& date, const std::string& event) const override;

private:
	Comparison m_comp; 
	std::string m_event;
};

class LogicalOperationNode : public Node
{
public:
	LogicalOperationNode(LogicalOperation op, std::shared_ptr < Node> lhs, std::shared_ptr < Node> rhs);

	bool Evaluate(const Date& date, const std::string& event) const override;	

private:
	LogicalOperation m_operation;
	std::shared_ptr<Node> m_leftParent;
	std::shared_ptr<Node> m_rightParent;
};