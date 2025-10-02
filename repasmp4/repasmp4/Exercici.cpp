#include "Exercici.h"
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace std;


Exercici::Exercici(const Exercici& e)
{
	m_descripcio = e.m_descripcio;
	m_dataLimit = e.m_dataLimit;
	m_nEstudiants = e.m_nEstudiants;
	if (m_nEstudiants > 0){
		m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		for (int i = 0; i < m_nEstudiants; i++) {
			m_lliuraments[i] = e.m_lliuraments[i];
		}
	}
	else {
		m_lliuraments = nullptr;
	}
}

Exercici::~Exercici()
{
	delete[] m_lliuraments;
}

Exercici& Exercici::operator=(const Exercici& e)
{
	if (this != &e) {
		delete[] m_lliuraments;
		m_descripcio = e.m_descripcio;
		m_dataLimit = e.m_dataLimit;
		m_nEstudiants = e.m_nEstudiants;
		if (m_nEstudiants > 0) {
			m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
			for (int i = 0; i < m_nEstudiants; i++)
				m_lliuraments[i] = e.m_lliuraments[i];
		}
		else {
			m_lliuraments = nullptr;
		}
	}
	return *this;
}

void Exercici::inicialitzaEstudiants(const string& fitxerEstudiants)
{	

	ifstream f(fitxerEstudiants);
	string line;

	getline(f, line);
	m_nEstudiants = stoi(line);
	delete[] m_lliuraments;
	m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];

	string niu;

	for (int i = 0; i < m_nEstudiants; i++) {
		getline(f, niu);
		m_lliuraments[i].setNiu(niu);
	}
	f.close();
			
}

bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
	for (int i = 0; i < m_nEstudiants; i++) {
		if (m_lliuraments[i].getNiu() == niu) {
			m_lliuraments[i].afegeixTramesa(fitxer, data);
			return true;
		}
	}
	return false;
}

bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
	for (int i = 0; i < m_nEstudiants; i++) {
		if (m_lliuraments[i].getNiu() == niu) {
			return m_lliuraments[i].consultaTramesa(data, fitxer);
		}
	}
	return false;
}

bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
	for (int i = 0; i < m_nEstudiants; i++) {
		if (m_lliuraments[i].getNiu() == niu) {
			return m_lliuraments[i].eliminaTramesa(data);
		}
	}
	return false;
}
