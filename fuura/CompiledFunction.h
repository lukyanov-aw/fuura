#pragma once
#include <memory>

namespace fuura::compilation
{
	template <typename ...FunctionSignature> class CompiledFunction;

	///////////////////////////////////////////////////////////////////////////
	//
	//	����������������� �������, ��������� ��� ����������.
	//	������ ��������� �� ����������������� ��� � ��������� ��� ���������.
	//
	///////////////////////////////////////////////////////////////////////////
	template <typename ResultType, typename ...Args>
	class CompiledFunction <ResultType(Args...)>
	{
		std::shared_ptr<void> m_compiledCode;

	public:
		// --------------------------------------------------------------------------
		CompiledFunction(std::shared_ptr<void> compiledCode)
			: m_compiledCode(compiledCode)
		{}

		// --------------------------------------------------------------------------
		// ���������� ���������� ������������������ ���� ��� ������� � ���������� �����������.
		// --------------------------------------------------------------------------
		ResultType operator () (Args... args)
		{
			// ��������������� �� ������������� ��������� ������� � ��������� - �� ������������ ����.
			auto func = reinterpret_cast<ResultType(*)(Args...)>(m_compiledCode.get());
			return func(args...);
		}

		// --------------------------------------------------------------------------
	};

	///////////////////////////////////////////////////////////////////////////
}