#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"
#include "Node.h"
#include <forward_list>

class Poligon
{
public:
    Poligon();
    ~Poligon();
    Poligon(int nCostats);
    Poligon(const Poligon& other);

    Poligon& operator=(const Poligon& other);

    int getNCostats() const { return m_nCostats; };
    bool afegeixVertex(const Punt& v);
    bool getVertex(int iVertex, Punt& v) const;
    float calculaPerimetre() const;
private:
	static const int MIN_COSTATS = 3;
	std::forward_list<Punt> m_vertexs;
    std::forward_list<Punt>::iterator m_ultimVertex;
    int m_nCostats;
    int m_nVertexs;
};

#endif // POLIGON_H

