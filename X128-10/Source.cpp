// Play game of rock, paper, scissors with computer

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

int main() {
	int user_score{ 0 }, comp_score{ 0 };
	char user_move{ 'x' };
	vector<char> comp_move = { 'r', 'p', 's' };
	int comp_move_idx{ 0 };

	while (true) {
		cout << "Enter your move (r)ock, (p)aper, (s)cisssors.  Enter x to exit: ";
		cin >> user_move;
		// check input
		switch (user_move)
		{
			case 'r': case 'p': case 's':
				break;
			case 'x': {
				cout << "Your score: " << user_score << "  Computer score: " << comp_score << "\n\n";
				keep_window_open();
				return (0);
			}
			default: //bad input
				continue;
		}

		// generate computer move
		random_device rd;   // non-deterministic generator  
		mt19937 gen(rd());  // to seed mersenne twister.  
		uniform_int_distribution<> dist(1, 3); // distribute results between 1 and 3 inclusive.  

		comp_move_idx = dist(gen)-1;

		// evaluate

		switch (user_move)
		{
		case 'r':
			if (comp_move[comp_move_idx] == 'r') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: Draw\n\n";
				continue;
			}
			else if(comp_move[comp_move_idx] == 'p') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: Computer Wins\n\n";
				comp_score++;
				continue;
			}
			else if (comp_move[comp_move_idx] == 's') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: You win!\n\n";
				user_score++;
				continue;
			}
			break;
		case 'p':
			if (comp_move[comp_move_idx] == 'r') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: You win!\n\n";
				user_score++;
				continue;
			}
			else if (comp_move[comp_move_idx] == 'p') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: Draw\n\n";
				continue;
			}
			else if (comp_move[comp_move_idx] == 's') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: Computer wins.\n\n";
				comp_score++;
				continue;
			}
			break;
		case 's':
			if (comp_move[comp_move_idx] == 'r') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: Computer wins.\n\n";
				comp_score++;
				continue;
			}
			else if (comp_move[comp_move_idx] == 'p') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: You win!\n\n";
				user_score++;
				continue;
			}
			else if (comp_move[comp_move_idx] == 's') {
				cout << "Your move: " << user_move << "\tComputer move: " << comp_move[comp_move_idx] << "\tResult: Draw.\n\n";
				continue;
			}
			break;
		default:
			cout << "default case reached for some reason... \n";
			break;
		}
	}
}