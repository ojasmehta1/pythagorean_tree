#include <cmath>
#include "PTree.hpp"

PTree::PTree(){}

PTree::PTree(int length, int recDepth) {
    vec1.x = 6 * length/2 - length/2;
	vec2.x = 6 * length/2 + length/2;
    vec1.y = 4 * length;
    vec2.y = 4 * length;

    this->recDepth = recDepth;
    square.setPointCount(4);
    pTree(vec1, vec2, recDepth);
}

void PTree::pTree (Vector2f vec1, Vector2f vec2, int recDepth) {

    if(recDepth > 0) {
        Vector2f vec3;
        Vector2f vec4;
        Vector2f vec5; 
        vec3.x = vec2.x - (vec1.y -  vec2.y);
        vec3.y = vec2.y - (vec2.x - vec1.x);
    
        vec4.x = vec1.x - (vec1.y -  vec2.y);
        vec4.y = vec1.y - (vec2.x - vec1.x);
    
        vec5.x = vec4.x +  ( vec2.x - vec1.x - (vec1.y -  vec2.y) ) / 2;
        vec5.y = vec4.y -  ( vec2.x - vec1.x + vec1.y -  vec2.y ) / 2;
        
        square.setPoint(0, vec1);
        square.setPoint(1, vec2);
        square.setPoint(2, vec3);
        square.setPoint(3, vec4);
        square.setFillColor(sf::Color(100,vec1.x, vec2.x)); 
        squareVector.push_back(square);
		
        pTree(vec4, vec5, recDepth - 1);
        pTree(vec5, vec3, recDepth - 1);
    }
}

void PTree::draw(RenderTarget& target, RenderStates states) const {
    for(int i = 0; i < squareVector.size(); i++) {
        target.draw(squareVector.at(i));
    }         
}
