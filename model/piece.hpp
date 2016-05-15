#ifndef PIECE_HPP
#define PIECE_HPP

#include <QSet>


class Piece
{
	public:
		enum Type {
			CITY,
			FIGHT,
			ARMY,
			TRANSPORT,
			PATROL,
			BATTLESHIP
		};
		enum Team {
			PLAYER1,
			PLAYER2,
			NEUTRAL
		};


		Piece(Type type, Team owner);

		Type getType();
		Team getOwner();
		void addTransported(Piece* transported);
		QSet<Piece*> getTransported();


	private:
		Type m_type;
		Team m_team;
		QSet<Piece*> m_transported;
};

#endif // PIECE_HPP
