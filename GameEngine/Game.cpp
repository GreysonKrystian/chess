#include "Game.h"


Game::Game()
{
	is_white_turn = true;
	board = Board();
	this->create_figures();

}

Game::~Game()
{
	auto my_board = this->get_board().get_board();
	for (auto itr_x = my_board.begin(); itr_x != my_board.end(); ++itr_x)
	{
		for (auto itr_y = (*itr_x).begin(); itr_y != (*itr_x).end(); ++itr_y)
		{
			delete* itr_y;
		}
	}
}

Board Game::get_board()
{
	return board;
}

void Game::capture_figure(int x, int y)
{
 	Figure* captured = board.get_figure(x, y);
	delete captured;
}

bool Game::check_win_condition(Player const& current_player, Player const& checked_player) const
{
	auto king_positions = restrict_king_positions(current_player, checked_player);
	if ((get_allowed_moves(current_player).size() == 0) && (king_positions.size() == 0))
	{
		return true;
	}
	return false;
}

std::list<Figure*> Game::get_checking_figures(Player const& current_player) const
{
	std::list<Figure*> checking_figures;

	std::vector<int> king_pos = current_player.get_king()->get_position();
	
	auto enemy_figures = current_player.get_player_figures();
	for (auto itr_fig = enemy_figures.begin(); itr_fig != enemy_figures.end(); ++itr_fig)
	{
		std::list<std::vector<int>> figure_move_positions = board.get_free_positions_for_figure(*itr_fig);
		auto itr_to_add = std::find(figure_move_positions.begin(), figure_move_positions.end(), king_pos);
		if(itr_to_add != figure_move_positions.end())
		{
			checking_figures.push_back(*itr_fig);
		}
	}
	return checking_figures;
}

std::list<std::vector<int>> Game::get_allowed_moves(Player const& current_player) const //zwraca możliwe ruchy dla szachowanego gracza
{
	std::list<std::vector<int>> allowed_positions;

	std::list<Figure*> checking_figures = get_checking_figures(current_player);

	auto itr_checking_figure = checking_figures.begin();
	std::vector<int> checking_pos = (*itr_checking_figure)->get_position();

	int checking_x = checking_pos[0];
	int checking_y = checking_pos[1];

	std::vector<int> king_pos = (current_player.get_king())->get_position();
	int king_x = king_pos[0];
	int king_y = king_pos[1];

	if ((king_x == checking_x) && (checking_y > king_y)) //pion w górę
	{
		king_y--;
		while (king_y > checking_y)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_y--;
		}
	}

	if ((king_x == checking_x) && (checking_y < king_y)) //pion w dół
	{
		king_y++;
		while (king_y < checking_y)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_y++;
		}
	}


	if ((checking_x > king_x) && (checking_y == king_y)) //poziom w prawo
	{
		king_x++;
		while (king_x < checking_x)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_x++;
		}
	}

	if ((checking_x < king_x) && (checking_y == king_y)) //poziom w lewo
	{
		king_x--;
		while (king_x > checking_x)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_x--;
		}
	}

	if ((checking_x > king_x) && (checking_y < king_y)) // prawy ukos w górę
	{
		king_x++;
		king_y--;
		while (king_x < checking_x && king_y > checking_y)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_x++;
			king_y--;
		}
	}

	if ((checking_x > king_x) && (checking_y > king_y)) // prawy ukos w dół
	{
		king_x++;
		king_y++;
		while (king_x < checking_x && king_y < checking_y)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_x++;
			king_y++;
		}
	}

	if ((checking_x < king_x) && (checking_y < king_y)) // lewy ukos w górę
	{
		king_x--;
		king_y--;
		while (king_x > checking_x && king_y > checking_y)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_x--;
			king_y--;
		}
	}

	if ((checking_x < king_x) && (checking_y > king_y)) // lewy ukos w dół
	{
		king_x--;
		king_y++;
		while (king_x > checking_x && king_y < checking_y)
		{
			std::vector<int> point = { king_x, king_y };
			allowed_positions.push_back(point);
			king_x--;
			king_y++;
		}
	}

	return allowed_positions;
}


std::list<std::vector<int>> Game::restrict_king_positions(Player const& current_player, Player const& checked_player) const //zrwaca listę pól na które może ruszyć się król, ze względu na przeciwne figury // przyjmuje grasza szachującego
{
	Figure* king = checked_player.get_king();
	std::list<std::vector<int>> king_free_positions = board.get_free_positions_for_figure(king);
	
	//std::list<Figure*> enemy_figures = checked_player.get_player_figures();
	
	//for (auto itr = enemy_figures.begin(); itr != enemy_figures.end(); ++itr)
	//{
	//	std::list<std::vector<int>> attacking_positions = (*itr)->get_possible_positions();
	//	for (auto itr_attack = attacking_positions.begin(); itr_attack != attacking_positions.end(); ++itr_attack)
	//	{
	//		auto itr_del = std::find(king_free_positions.begin(), king_free_positions.end(), *itr_attack);
	//		king_free_positions.erase(itr_del);
	//	}
	//}
	auto checking_figures = get_checking_figures(current_player);
	auto temp_board = board.get_board();
	temp_board[king->get_position()[0]][king->get_position()[1]] = nullptr;
	for (auto itr = checking_figures.begin(); itr != checking_figures.end(); ++itr)
	{
		std::list<std::vector<int>> attacking_positions = (*itr)->get_possible_positions();
		for (auto itr_attack = attacking_positions.begin(); itr_attack != attacking_positions.end(); ++itr_attack)
		{
			auto itr_del = std::find(king_free_positions.begin(), king_free_positions.end(), *itr_attack);
			king_free_positions.erase(itr_del);
		}
	}
	return king_free_positions;
}


void Game::create_figures()
{
	//czarne
	Figure* bishop_l_b = new Bishop(0, 2, 0);
	Figure* bishop_r_b = new Bishop(0, 5, 0);
	Figure* rook_l_b = new Rook(0, 0, 0);
	Figure* rook_r_b = new Rook(0, 7, 0);
	Figure* knight_l_b = new Knight(0, 1, 0);
	Figure* knight_r_b = new Knight(0, 6, 0);
	Figure* king_b = new King(0, 4, 0);
	Figure* queen_b = new Queen(0, 3, 0);
	Figure* pawn_b_1 = new Pawn(0, 0, 1);
	Figure* pawn_b_2 = new Pawn(0, 1, 1);
	Figure* pawn_b_3 = new Pawn(0, 2, 1);
	Figure* pawn_b_4 = new Pawn(0, 3, 1);
	Figure* pawn_b_5 = new Pawn(0, 4, 1);
	Figure* pawn_b_6 = new Pawn(0, 5, 1);
	Figure* pawn_b_7 = new Pawn(0, 6, 1);
	Figure* pawn_b_8 = new Pawn(0, 7, 1);
	std::list <Figure*> black{ bishop_l_b, bishop_r_b, rook_l_b, rook_r_b, knight_l_b, knight_r_b, king_b, queen_b,
	pawn_b_1, pawn_b_2, pawn_b_3, pawn_b_4, pawn_b_5, pawn_b_6, pawn_b_7, pawn_b_8 };
	
	board.set_starting_postions(black);
	player_black.set_player_figures(black);
	
	//Biale
	Figure* bishop_l_w = new Bishop(1, 2, 7);
	Figure* bishop_r_w = new Bishop(1, 5, 7);
	Figure* rook_l_w = new Rook(1, 0, 7);
	Figure* rook_r_w = new Rook(1, 7, 7);
	Figure* knight_l_w = new Knight(1, 1, 7);
	Figure* knight_r_w = new Knight(1, 6, 7);
	Figure* king_w = new King(1, 4, 7);
	Figure* queen_w = new Queen(1, 3, 7);
	Figure* pawn_w_1 = new Pawn(1, 0, 6);
	Figure* pawn_w_2 = new Pawn(1, 1, 6);
	Figure* pawn_w_3 = new Pawn(1, 2, 6);
	Figure* pawn_w_4 = new Pawn(1, 3, 6);
	Figure* pawn_w_5 = new Pawn(1, 4, 6);
	Figure* pawn_w_6 = new Pawn(1, 5, 6);
	Figure* pawn_w_7 = new Pawn(1, 6, 6);
	Figure* pawn_w_8 = new Pawn(1, 7, 6);
	std::list < Figure*> white{ bishop_l_w, bishop_r_w, rook_l_w, rook_r_w, knight_l_w, knight_r_w, king_w, queen_w,
	pawn_w_1, pawn_w_2, pawn_w_3, pawn_w_4, pawn_w_5, pawn_w_6, pawn_w_7, pawn_w_8 };
	
	board.set_starting_postions(white);
	player_white.set_player_figures(white);
}



bool Game::castling_left_conditions(int pos_x, int pos_y) const
{
	if (board.get_figure(pos_x - 4, pos_y) == nullptr)
		return false;
	else
	{
		Figure* corner_figure = board.get_figure(pos_x - 4, pos_y);
		if ((corner_figure->get_type() == "R") && (corner_figure->get_first_move() == true))
			return true;
		return false;
	}
}

bool Game::castling_right_conditions(int pos_x, int pos_y) const
{
	if (board.get_figure(pos_x + 3, pos_y) == nullptr)
		return false;
	else
	{
		Figure* corner_figure = board.get_figure(pos_y + 3, pos_y);
		if ((corner_figure->get_type() == "R") && (corner_figure->get_first_move() == true))
			return true;
		return false;
	}
}

std::list<std::vector<int>> Game::get_castling_positions() const
{
	int pos_x = 4;
	int pos_y = 0;
	if (get_current_player() == true)
	{
		int pos_x = 4;
		int pos_y = 7;
	}
	std::list<std::vector<int>> castling_positions;

	if ((castling_left_conditions(pos_x, pos_y) == true) && (board.get_figure(pos_x - 1, pos_y) == nullptr) && (board.get_figure(pos_x - 2, pos_y) == nullptr)
		&& board.get_figure(pos_x - 3, pos_y))
	{
		castling_positions.push_back({ pos_x - 2, pos_y });
	}
	if ((castling_right_conditions(pos_x, pos_y) == true) && (board.get_figure(pos_x + 1, pos_y)) == nullptr && (board.get_figure(pos_x + 2, pos_y) == nullptr))
	{
		castling_positions.push_back({ pos_x + 2, pos_y });
	}

	return castling_positions;
}

bool Game::get_current_player() const
{
	return is_white_turn;
}

void Game::change_turn()
{
	if (is_white_turn == true)
	{
		is_white_turn = false;
	}
	else
	{
		is_white_turn = true;
	}
}

void Game::build_game()
{

}
///////////////////////////////////////// PLAYER /////////////////////////////////////////////

void Player::set_player_figures(std::list<Figure*> const& figures_list)
{
	player_figures = figures_list;
}

std::list<Figure*> Player::get_player_figures() const
{
	return player_figures;
}

Figure* Player::get_king() const
{
	for (auto itr = player_figures.begin(); itr != player_figures.end(); itr++)
	{
		if ((*itr)->get_type() == "K")
		{
			return *itr;
		}
	}
	return nullptr;
}
