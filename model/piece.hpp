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


		Piece(int id, Type type, Team owner);

		int getId();
		Type getType();
		Team getOwner();
		void addTransported(Piece* transported);
		void removeTransported(Piece* transported);
		QSet<Piece*> getTransported();


	private:
		int m_id;
		Type m_type;
		Team m_team;
		QSet<Piece*> m_transported;
};

#endif // PIECE_HPP
