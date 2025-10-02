#include "LliuramentsEstudiant.h"

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
	auto it = m_trameses.before_begin();
	for (auto next = m_trameses.begin(); next != m_trameses.end(); ++next, ++it);
	m_trameses.insert_after(it, Tramesa(fitxer, data));
}

bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
	for (const Tramesa& t : m_trameses) {
		if (t.getData() == data) {
			fitxer = t.getFitxer();
			return true;
		}
	}
	return false;
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
	auto prev = m_trameses.before_begin();
	for (auto it = m_trameses.begin(); it != m_trameses.end(); ++it) {
		if (it->getData() == data) {
			m_trameses.erase_after(prev);
			return true;
		}
		prev = it;
	}
	return false;
}
