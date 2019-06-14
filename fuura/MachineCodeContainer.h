#pragma once
#include <vector>
#include "ProcessorTypes.h"

namespace fuura::compilation
{
	//////////////////////////////////////////////////////////////////////////////
	//
	//	��������� ��� ��������� ����.
	//
	//////////////////////////////////////////////////////////////////////////////
	class MachineCodeContainer
	{
		std::vector<byte> m_currentCode;

	public:
		// �����:
		//		����� ������ ���������� ��� ����������� int, �.�. ��������� int
		//		����� �������� ��������� ������, �������� byte | byte ��� int.

		// ----------------------------------------------------------------------------
		// ��������� ����.
		// ----------------------------------------------------------------------------
		inline MachineCodeContainer& operator << (byte b)
		{
			m_currentCode.push_back(b);
			return *this;
		}

		// ----------------------------------------------------------------------------
		// ��������� char ��� ����.
		// ----------------------------------------------------------------------------
		inline MachineCodeContainer& operator << (char b)
		{
			return (*this) << (byte)b;
		}

		// ----------------------------------------------------------------------------
		// ��������� ��������� ���� dword � �������� ������� ���������� ������.
		// ----------------------------------------------------------------------------
		inline MachineCodeContainer& operator << (dword constant)
		{
			m_currentCode.push_back(GetByte<3>(constant));
			m_currentCode.push_back(GetByte<2>(constant));
			m_currentCode.push_back(GetByte<1>(constant));
			m_currentCode.push_back(GetByte<0>(constant));

			return *this;
		}

		// ----------------------------------------------------------------------------
		// ��������� ��������� ���� int32 � �������� ������� ���������� ������.
		// ----------------------------------------------------------------------------
		inline MachineCodeContainer& operator << (int32 constant)
		{
			return (*this) << (dword)constant;
		}

		// ----------------------------------------------------------------------------
		// ��������� ��������� ���� word � �������� ������� ���������� ������.
		// ----------------------------------------------------------------------------
		inline MachineCodeContainer& operator << (word constant)
		{
			m_currentCode.push_back(GetByte<1>(constant));
			m_currentCode.push_back(GetByte<0>(constant));

			return *this;
		}

		// ----------------------------------------------------------------------------
		// ��������� ��������� ���� int16 � �������� ������� ���������� ������.
		// ----------------------------------------------------------------------------
		inline MachineCodeContainer& operator << (int16 constant)
		{
			return (*this) << (word)constant;
		}


	public:
		// ----------------------------------------------------------------------------
		// ���������� ������� ������ ������������������ ���� � ������.
		// ----------------------------------------------------------------------------
		inline std::size_t GetCodeSize() const
		{
			return m_currentCode.size();
		}

		// ----------------------------------------------------------------------------
		// ���������� ��������� �� ������ ����� ����.
		// ���� ��������� ����, ���������� ����������.
		// ----------------------------------------------------------------------------
		inline byte* GetCode()
		{
			return &(m_currentCode.at(0));
		}

		// ----------------------------------------------------------------------------
		// ������� ��������� �� ����.
		// ----------------------------------------------------------------------------
		inline void Clear()
		{
			m_currentCode.clear();
		}
	};

	//////////////////////////////////////////////////////////////////////////////
}