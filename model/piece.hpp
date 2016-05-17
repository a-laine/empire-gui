#ifndef PIECE_HPP
#define PIECE_HPP

#include <QSet>


class Piece
{
	public:
		enum Type {
			ARMY = 0,
			FIGHT = 1,
			TRANSPORT = 2,
			PATROL = 3,
			BATTLESHIP = 4,
			CITY
		};


		Piece(int id, int type, int ownerId);

		int getId();
		int getType();
		int getOwner();
		void setGraphicsObject(void* object);
		void* getGraphicsObject();
		void addTransported(Piece* transported);
		void removeTransported(Piece* transported);
		QSet<Piece*>& getTransported();


	private:
		int m_id;
		int m_type;
		int m_team;
		void* m_graphics;
		QSet<Piece*> m_transported;
};

#endif // PIECE_HPP
