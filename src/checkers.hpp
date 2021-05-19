#include "pch.hpp"
#include "helpers.hpp"
#include "slot.hpp"

class ChineseCheckers {
private:
	sf::RenderWindow* m_Window;
	sf::CircleShape m_Outline;
	sf::Transform m_Rotter;
	
	int m_PlayerCount;
	int m_CurrentPlayer;
	Slot* m_Selected;
	bool m_GameOver;
	bool m_EnableMouse;

	std::vector<Slot> m_Slots;

	enum MoveType {
		NOHOPE, SINGLE, MULTIPLE
	};

public:
	ChineseCheckers(sf::RenderWindow* window, int playerCount=2);
	~ChineseCheckers();
	
	/* DRAWING */
	void draw();
	void createBoard();
	void config();
	void addSlotRow(float Y, int row);

	/* TURN LOGIC */
	void rotateBoard();
	bool movedAtAll();
	void nextTurn();

	/* MAIN GAME */
	void processClick(float, float, bool force=false);
	void selector(Slot* clicked);
	void move(Slot* clicked);
	int checkWin();
	bool isGameOver();
	
	/* VALIDATION / AUX */
	MoveType validateMove(Slot*, Slot*);
	Slot* findSlot(float x, float y);
};