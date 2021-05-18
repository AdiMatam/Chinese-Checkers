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

	std::vector<Slot> m_Slots;

	enum MoveType {
		NOHOPE, SINGLE, MULTIPLE
	};

public:
	ChineseCheckers(sf::RenderWindow* window, int playerCount=2);
	~ChineseCheckers();
	
	void draw();
	void createBoard();

	void rotateBoard();

	void handleEvent(sf::Event& ev);
	void nextTurn();
	int checkWin();
	bool isGameOver();
	MoveType validateMove(Slot*, Slot*);

	Slot* findSlot(float x, float y);
private:
	void config();
	void addSlotRow(float Y, int row);
};