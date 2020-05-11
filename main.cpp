#include "PTree.hpp"
using namespace std;

int main () {
	
	int length = 0;
	int	recDepth = 0;
	cout << "Size of the base square:";
	cin >> length;
	cout << "Depth of recursion:";
	cin >> recDepth;
	cout << endl;

	PTree tree(length, recDepth);

	RenderWindow window(VideoMode(6 * length, 4 * length), "Pythagorean Tree");
	
	while(window.isOpen()) {
		sf:: Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(tree);
		window.display();
	}
	
	return 0;
}