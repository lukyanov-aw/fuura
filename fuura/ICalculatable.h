#pragma once
#include "Value.h"
//#include "RegisterPlaceholder.h"
#include "ExecutionFlow.h"

namespace fuura::language
{
	//////////////////////////////////////////////////////////////////////////////
	//
	//	���������� ������.
	//	� ���� ��������������� ������� ����� ������� �������������� � ������
	//	��������, ����������� ������ ���������.
	//
	//////////////////////////////////////////////////////////////////////////////
	class ICalculatable
	{
	public:
		virtual ~ICalculatable() = default;

		// --------------------------------------------------------------------
		// ���������� �������� ���������.
		// --------------------------------------------------------------------
		virtual Value Calculate() const = 0;

		// --------------------------------------------------------------------
		// ���������� ��� ���������.
		// --------------------------------------------------------------------
		virtual ValueType GetType() const = 0;

		// --------------------------------------------------------------------
		// ������������ ��� ����������.
		// --------------------------------------------------------------------
		/*
		virtual compilation::IRegisterPlaceholder* GenerateFlow(compilation::ExecutionFlow& executionFlow, compilation::VirtualRegisterManager& tempValues) const
		{
			// TODO: �������� �� ����� ����������� ������� ����� ���������� ����� �����������.
			//throw std::exception("not implemented yet");
			return nullptr;
		}*/
	};

	//////////////////////////////////////////////////////////////////////////////
}