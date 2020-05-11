#ifndef PTREE_HPP
#define PTREE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
class PTree : public Drawable
{
public:
	PTree();
	PTree(int inputLength, int inputDepth);
	void pTree (Vector2f vec1, Vector2f vec2, int recDepth);
	void draw(RenderTarget& target, RenderStates states) const;
private:
	std::vector <ConvexShape> squareVector;
	sf::ConvexShape square;
	int recDepth;
	
	Vector2f vec1;
	Vector2f vec2;
	
};

#endif