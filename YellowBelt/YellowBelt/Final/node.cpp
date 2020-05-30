#include "node.h"
#include <string>
#include <iostream>


template <class Value>
bool ValueCompare(Comparison comp, const Value& lhs, const Value& rhs)
{
	switch (comp)
	{
	case Comparison::Equal:
		return lhs == rhs;
	case Comparison::Greater:
		return lhs > rhs;
	case Comparison::GreaterOrEqual:
		return lhs >= rhs;
	case Comparison::Less:
		return lhs < rhs;
	case Comparison::LessOrEqual:
		return lhs <= rhs;
	case Comparison::NotEqual:
		return lhs != rhs;
	}
	return false;
};

	bool EmptyNode::Evaluate(const Date& date, const std::string& event) const
	{
		return false;
	}

	DateComparisonNode::DateComparisonNode(Comparison comp, const Date& date)
	{
		m_comp = comp;
		m_date = date;
	}

	bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const
	{
		return ValueCompare(m_comp, date, m_date);
	}

	EventComparisonNode::EventComparisonNode(Comparison comp, const std::string& ev)
	{
		m_comp = comp;
		m_event = ev;
	}

	bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const
	{
		return ValueCompare(m_comp, event, m_event);
	}

	LogicalOperationNode::LogicalOperationNode(LogicalOperation op, std::shared_ptr < Node> lhs, std::shared_ptr < Node> rhs)
	{
		m_operation = op;
		m_leftParent = lhs;
		m_rightParent = rhs;
	}

	bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const
	{
		switch (m_operation)
		{
		case LogicalOperation::And:
			return m_leftParent->Evaluate(date, event) && m_rightParent->Evaluate(date, event);
		case LogicalOperation::Or:
			return m_leftParent->Evaluate(date, event) || m_rightParent->Evaluate(date, event);
		}
		return false;
	}
