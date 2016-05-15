#include "piece.hpp"


Piece::Piece(Piece::Type type, Piece::Team owner) :
	m_type(type),
	m_team(owner)
{
}

Piece::Type Piece::getType()
{
	return m_type;
}

Piece::Team Piece::getOwner()
{
	return m_team;
}

void Piece::addTransported(Piece* transported)
{
	m_transported.insert(transported);
}

QSet<Piece*> Piece::getTransported()
{
	return m_transported;
}
