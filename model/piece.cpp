#include "piece.hpp"


Piece::Piece(int id, Piece::Type type, Piece::Team owner) :
	m_id(id),
	m_type(type),
	m_team(owner)
{
}

int Piece::getId()
{
	return m_id;
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

void Piece::removeTransported(Piece* transported)
{
	m_transported.remove(transported);
}

QSet<Piece*> Piece::getTransported()
{
	return m_transported;
}
