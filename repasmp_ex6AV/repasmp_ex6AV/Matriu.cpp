#include "Matriu.h"
#include <cmath>

Matriu::~Matriu()
{
}

void Matriu::resize(int nFiles, int nColumnes)
{

    float** novaMatriu = new float* [nFiles];
    for (int i = 0; i < nFiles; ++i)
    {
        novaMatriu[i] = new float[nColumnes];
        for (int j = 0; j < nColumnes; ++j)
        {
            novaMatriu[i][j] = 0.0f;
        }
    }

    if (m_matriu != nullptr)
    {
        int minFiles = (nFiles < m_nFiles) ? nFiles : m_nFiles;
        int minColumnes = (nColumnes < m_nColumnes) ? nColumnes : m_nColumnes;

        for (int i = 0; i < minFiles; ++i)
        {
            for (int j = 0; j < minColumnes; ++j)
            {
                novaMatriu[i][j] = m_matriu[i][j];
            }
        }

        for (int i = 0; i < m_nFiles; ++i)
        {
            delete[] m_matriu[i];
        }
        delete[] m_matriu;
    }

    m_matriu = novaMatriu;
    m_nFiles = nFiles;
    m_nColumnes = nColumnes;
}



void Matriu::transpose()
{
    
    float** novaMatriu = new float* [m_nColumnes];
    for (int i = 0; i < m_nColumnes; ++i)
        novaMatriu[i] = new float[m_nFiles];
  
    for (int i = 0; i < m_nFiles; ++i)
        for (int j = 0; j < m_nColumnes; ++j)
            novaMatriu[j][i] = m_matriu[i][j];
   
    m_matriu = novaMatriu;
    int aux = m_nFiles;
    m_nFiles = m_nColumnes;
    m_nColumnes = aux;
}


Matriu& Matriu::operator=(const Matriu& m)
{
    if (this != &m) {
        if (m_matriu != nullptr) {
            for (int i = 0; i < m_nFiles; ++i)
                delete[] m_matriu[i];
            delete[] m_matriu;
        }

        m_nFiles = m.m_nFiles;
        m_nColumnes = m.m_nColumnes;

        if (m_nFiles > 0 && m_nColumnes > 0) {
            m_matriu = new float* [m_nFiles];
            for (int i = 0; i < m_nFiles; ++i) {
                m_matriu[i] = new float[m_nColumnes];
                for (int j = 0; j < m_nColumnes; ++j) {
                    m_matriu[i][j] = m.m_matriu[i][j];
                }
            }
        }
        else {
            m_matriu = nullptr;
        }
    }
    return *this;
}


void Matriu::initValor(float valor)
{
}

void Matriu::setValor(int fila, int columna, float valor)
{
    if (fila >= 0 && fila < m_nFiles && columna >= 0 && columna < m_nColumnes && m_matriu != nullptr)
    {
        m_matriu[fila][columna] = valor;
    }
}

Matriu Matriu::operator+(const Matriu& m)
{
	return Matriu();
}

Matriu Matriu::operator+(float s)
{
    Matriu resultat(m_nFiles, m_nColumnes);
    for (int i = 0; i < m_nFiles; ++i) {
        for (int j = 0; j < m_nColumnes; ++j) {
            resultat.setValor(i, j, m_matriu[i][j] + s);
        }
    }
    return resultat;
}

bool Matriu::operator==(const Matriu& m)
{
    bool vof = false;
    if (m_nFiles== m.m_nFiles && m_nColumnes == m.m_nColumnes) {
        for (int i = 0; i < m_nFiles; ++i) {
            for (int j = 0; j < m_nColumnes; ++j) {
                if (m_matriu[i][j] == m.m_matriu[i][j])
                    vof = true;
                else
                    return false;
            }
        }
    }
    else {
        return false;
    }
    return vof;
    
}

float Matriu::getValor(int fila, int columna) const
{
    if (fila >= 0 && fila < m_nFiles && columna >= 0 && columna < m_nColumnes && m_matriu != nullptr)
        return m_matriu[fila][columna];
    else
        return 0.0f;
}
