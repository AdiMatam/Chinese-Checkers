#include "pch.hpp"
#include "checkers.hpp"

void ChineseCheckers::initConnection() {
	m_Data << m_PlayerCount;
	this->send(m_Data);
	m_Data.clear();
}

