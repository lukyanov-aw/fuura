#pragma once
#include <exception>
#include <string>

namespace fuura
{
	///////////////////////////////////////////////////////////////////////////
	//
	//	�������������� ��� ������������� ������.
	//
	///////////////////////////////////////////////////////////////////////////
	class SyntaxError : public std::exception
	{
		size_t m_line, m_charPositionInLine;
		std::string m_message;

	public:
		// --------------------------------------------------------------------
		SyntaxError(const std::string& message, size_t line, size_t charPositionInLine);

		// --------------------------------------------------------------------
		// ���������� ����� ������, �� ������� ��������� ������.
		// --------------------------------------------------------------------
		size_t GetLine() const;

		// --------------------------------------------------------------------
		// ���������� ����� ������� � ������, �� ������� ��������� ������.
		// --------------------------------------------------------------------
		size_t GetCharPositionInLine() const;

		// --------------------------------------------------------------------
		// ���������� ���������, ��������������� ������.
		// --------------------------------------------------------------------
		const std::string& GetMessage() const;

		// --------------------------------------------------------------------
	};

	///////////////////////////////////////////////////////////////////////////
	class RegisterTypeMismatch : public std::exception
	{
	public:
		RegisterTypeMismatch(int uid, char expected, char actual);
	};

	///////////////////////////////////////////////////////////////////////////
	class RegisterValueIsNotSet : public std::exception
	{
	public:
		RegisterValueIsNotSet(int uid);
	};

	///////////////////////////////////////////////////////////////////////////
}