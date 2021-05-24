#include "pch.hpp"
#include "helpers.hpp"
#include "slot.hpp"

class ChineseCheckers {
private:
	sf::RenderWindow* m_Window;
	sf::CircleShape m_Outline;
	sf::Texture m_BackTex;
	sf::Sprite m_BackImg;
	sf::Transform m_Rotater;

	int m_PlayerCount;
	int m_CurrentPlayer;
	sf::Color m_PlayerColors[6];

	Slot* m_Selected;
	bool m_GameOver;
	bool m_EnableMouse;
	int m_Degrees;

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
	void spin(sf::Keyboard::Key code);

	/* TURN LOGIC */
	bool movedAtAll();
	void nextTurn();

	/* MAIN GAME */
	void processClick(float x, float y);
	void selector(Slot* clicked);
	void move(Slot* clicked);
	int checkWin();
	bool isOver();
	
	/* EXTRA */
	MoveType validateMove(Slot* s1, Slot* s2);
	Slot* findSlot(float x, float y);
	void normalize(float* x, float* y);
	void showErrors(Slot* clicked);
};