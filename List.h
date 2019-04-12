#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>
template <typename T>
class List
{
	/*
	Die Klasse List dient zur Verwaltung von Knoten (Node<T>). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
	*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } list_form;
	Node<T> * head_tail;						// Zeiger auf Kopf- und End-Element -> next der 1. Knoten; -> prev der letzte Knoten
	int list_size;							// Länge der Kette
	bool temp;								// normalerweise false; ist true, wenn es sich um eine temoräre Liste handelt
											// die innerhalb der überladenen Operatoren angelegt wird
public:
	List();
	List(const List & _List);				// Kopie Konstruktor
	List(const List * _List);				// Kopie Konstruktor
	~List();
	void insertFront(T key);				// Einfügen eines Knotens am Anfang
	void insertFront(List & _List);			// Einfügen einer vorhandenen Liste am Anfang
	void insertFront(List * _List);			// Einfügen einer vorhandenen Liste am Anfang
	void insertBack(T key);				// Einfügen eines Knotesn am Ende
	void insertBack(List & _List);			// Einfügen einer vorhandenen Liste am Ende
	void insertBack(List * _List);			// Einfügen einer vorhandenen Liste am Ende
	bool getFront(T & key);				// Entnehmen eines Knoten am Anfang
	bool getBack(T & key);				// Entnehmen eines Knoten am Ende
	bool del(T key);						// löschen eines Knotens [key]
	bool search(T key);					// Suchen eines Knoten
	bool swap(T key1, T key2);			// Knoten in der Liste vertauschen
	int size(void);							// Größe der Lise (Anzahl der Knoten)
	bool test(void);						// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	
											// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
											// start: stirng vor der Ausgabe der Liste
											// zwischen: string zwischen Listenknoten
											// ende: string am Ende der Liste
	List & operator = (const List & _List);						// Zuweisungsoperator definieren
	List & operator = (const List * _List);						// Zuweisungsoperator definieren
	List & operator + (const List & List_Append);				// Listen zusammenführen zu einer Liste
	List & operator + (const List * List_Append);				// Listen zusammenführen zu einer Liste
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const & Liste);		// Ausgabeoperator überladen
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const * Liste);		// Ausgabeoperator überladen
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, const List<T> & Liste);
	friend Node<T>* get_anker(List& l);
	friend int get_AnzahlNodes(List& l);
};


template <typename T>
List<T>::List()
{
	// Konstruktor für eine leere Liste
	head_tail = new Node<T>;
	list_size = 0;
	temp = false;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
}
template <typename T>
List<T>::List(const List & _List)
{
	// Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	list_form = _List.list_form;
	head_tail = new Node<T>;
	list_size = 0;
	temp = _List.temp;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
	Node<T> * tmp_node;
	tmp_node = _List.head_tail->next;
	while (tmp_node != _List.head_tail)
	{
		head_tail->prev = new Node<T><T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
		head_tail->prev->prev->next = head_tail->prev;
		list_size++;
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}
template <typename T>
List<T>::List(const List * _List)
{
	// Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	list_form = _List->list_form;
	head_tail = new Node<T>;
	list_size = 0;
	temp = _List->temp;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
	Node<T> * tmp_node;
	tmp_node = _List->head_tail->next;
	while (tmp_node != _List->head_tail)
	{
		head_tail->prev = new Node<T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
		head_tail->prev->prev->next = head_tail->prev;
		list_size++;
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}
template <typename T>
List<T>::~List()
{
	while (head_tail->prev != head_tail->next)
	{
		Node<T>* x = head_tail->prev;
		head_tail->prev = x->prev;
		head_tail->prev->next = head_tail;
		delete x;
	}

	// Dekonstruktor
	// Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.
/*
	hier alle Knoten löschen, die im Objekt List allokiert wurden
*/

}
template <typename T>
void List<T>::insertFront(T key)
{
	Node<T> *neu(new Node<T>(key, head_tail->next, head_tail));
	head_tail->next = neu;
	head_tail->next->next->prev = neu;
	list_size++;



	// Einfügen eines neuen Knotens am Anfang der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Anfang der Liste einfügen
*/
}
template <typename T>
void List<T>::insertFront(List & _List)
{
	Node<T>* neu1 = _List.head_tail->next;
	Node<T>* neu2 = head_tail->next;
	head_tail->next = neu1;
	neu1->prev = head_tail;
	neu2->prev = _List.head_tail->prev;
	_List.head_tail->prev->next = neu2;
	list_size = _List.list_size + list_size;
	_List.head_tail->next = 0;
	_List.head_tail->prev = 0;
	_List.list_size = 0;



	// Einfügen einer vorhandenen Liste am Anfang
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	*/
}
template <typename T>
void List<T>::insertFront(List * _List)
{
	Node<T>* neu1 = _List->head_tail->next;
	Node<T>* neu2 = head_tail->next;
	head_tail->next = neu1;
	neu1->prev = head_tail;
	neu2->prev = _List->head_tail->prev;
	_List->head_tail->prev = neu2;
	list_size = _List->list_size + list_size;
	_List->head_tail->next = 0;
	_List->head_tail->prev = 0;
	_List->list_size = 0;
	// Einfügen einer vorhandenen Liste am Anfang
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	*/
}
template <typename T>
void List<T>::insertBack(T key)
{
	Node<T> *neu(new Node<T>(key, head_tail, head_tail->prev));
	head_tail->prev = neu;
	head_tail->prev->prev->next = neu;
	list_size++;
	// Einfügen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Ende der Liste einfügen
*/
}
template <typename T>
void List<T>::insertBack(List & _List)
{
	Node<T>* neu1 = _List.head_tail->prev;
	Node<T>* neu2 = head_tail->prev;
	head_tail->prev = neu1;
	neu1->next = head_tail;
	neu2->next = _List.head_tail->next;
	_List.head_tail->next->prev = neu2;
	list_size = _List.list_size + list_size;
	_List.head_tail->next = 0;
	_List.head_tail->prev = 0;
	_List.list_size = 0;
	// Einfügen einer vorhandenen Liste am Ende
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
	*/
}
template <typename T>
void List<T>::insertBack(List * _List)
{
	Node<T>* neu1 = _List->head_tail->prev;
	Node<T>* neu2 = head_tail->prev;
	head_tail->prev = neu1;
	neu1->next = head_tail;
	neu2->next = _List->head_tail->next;
	_List->head_tail->next->prev = neu2;
	list_size = _List->list_size + list_size;
	_List->head_tail->next = 0;
	_List->head_tail->prev = 0;
	_List->list_size = 0;
	// Einfügen einer vorhandenen Liste am Ende
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
	*/
}
template <typename T>
bool List<T>::getFront(T & key)
{
	Node<T>* neu = head_tail->next;
	if (list_size != 0) {
		head_tail->next->next->prev = head_tail;
		head_tail->next = head_tail->next->next;
		list_size--;
		key = neu->key;
		delete neu;
		return true;
	}



	// entnehmen des Knotens am Anfang der Liste
	// der Wert wird als Parameter zurückgegeben
	// der Knoten wird entnommen
/*
	Der Wert des vorderen Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/
	return false;
}
template <typename T>
bool List<T>::getBack(T & key)
{
	Node<T>* neu = head_tail->prev;
	if (list_size != 0) {
		head_tail->prev->prev->next = head_tail;
		head_tail->prev = head_tail->prev->prev;
		list_size--;
		key = neu->key;
		delete neu;
		return true;
	}
	// entnehmen des Knotens am Ende der Liste
	// der Wert wird als Parameter zurückgegeben
	// der Knoten wird entnommen
/*
	Der Wert des letzten Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/
	return false;
}
template <typename T>
bool List<T>::del(T key)
{
	if (list_size != 0)
	{
		Node<T>* neu = head_tail->next;
		for (int i = 0; i < list_size; i++)
		{

			if (key == neu->key) {
				neu->prev->next = neu->next;
				neu->next->prev = neu->prev;
				delete neu;
				list_size--;
				return true;
			}
			neu = neu->next;

		}
	}

	// Löschen eines gegebenen Knotens
/*
	Löschen des Knotens mit dem Schlüssel key
*/
	return false;
}
template <typename T>
bool List<T>::search(T key)
{
	if (list_size != 0)
	{
		Node<T>* neu = head_tail->next;
		for (int i = 0; i < list_size; i++)
		{

			if (key == neu->key) { return true; }
			neu = neu->next;

		}
	}
	// suchen eines Knotens
/*
	suchen ob ein Knoten mit dem Schlüssel key existiert.
*/
	return false;
}
template <typename T>
bool List<T>::swap(T key1, T key2)
{
	if (list_size != 0)
	{
		Node<T>* neu1 = head_tail->next;
		for (int i = 0; i < list_size && key1 != neu1->key; i++)
		{
			neu1 = neu1->next;
		}
		Node<T>* neu2 = head_tail->next;
		for (int i = 0; i < list_size && key2 != neu2->key; i++)
		{
			neu2 = neu2->next;
		}

		if (neu1 != head_tail && neu2 != head_tail)
		{
			if (neu1->next == neu2)
			{
				Node<T> *tempneunext = neu2->next;
				Node<T> *tempneuprev = neu1->prev;
				neu1->next = tempneunext;
				neu1->prev = neu2;
				neu2->prev = tempneuprev;
				neu2->next = neu1;
				tempneunext->prev = neu1;
				tempneuprev->next = neu2;
			}
			else if (neu2->next == neu1)
			{
				Node<T> *tempneunext = neu1->next;
				Node<T> *tempneuprev = neu2->prev;
				neu2->next = tempneunext;
				neu2->prev = neu1;
				neu1->prev = tempneuprev;
				neu1->next = neu2;
				tempneunext->prev = neu2;
				tempneuprev->next = neu1;
			}
			else {
				Node<T> *tempneunext = neu2->next;
				Node<T> *tempneuprev = neu2->prev;
				neu2->prev->next = neu1;
				neu2->next->prev = neu1;
				neu1->prev->next = neu2;
				neu1->next->prev = neu2;
				neu2->next = neu1->next;
				neu2->prev = neu1->prev;
				neu1->next = tempneunext;
				neu1->prev = tempneuprev;
			}
			return true;
		}

	}

	// Vertauschen von zwei Knoten
	// Dabei werden die Zeiger der Knoten und deren Nachbarn verändert.
/*
	Vertauschen von zwei Knoten mit dem key1 und dem key2
	Es dürfen nicht nur einfach die Schlüssel in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhängen.
*/
	return false;
}
template <typename T>
int List<T>::size(void)
{

	// Rückgabe der Knoten in der Liste mit O(1)
/*
	Anzahl der Knoten in der Liste zurückgeben.
*/
	return list_size;
}
template <typename T>
bool List<T>::test(void)
{
	// Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und zurück
	// Es werden dabei die Anzahl der Knoten gezählt.
	// Stimmt die Anzahl der Knoten überein liefert die Methode true
	Node<T> * tmp = head_tail->next;
	int i_next = 0, i_prev = 0;
	while (tmp != head_tail) {
		tmp = tmp->next;
		if (i_next > list_size) return false;
		i_next++;
	}
	if (i_next != list_size) return false;
	tmp = head_tail->prev;
	while (tmp != head_tail) {
		tmp = tmp->prev;
		if (i_prev > list_size) return false;
		i_prev++;
	}
	return i_prev == i_next;
}
template <typename T>
List<T> & List<T>::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;		//  !! keine Aktion notwendig
	list_form = _List.list_form;
	Node<T> * tmp_node;
	if (list_size)
	{
		Node<T> * tmp_del;
		tmp_node = head_tail->next;
		while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		list_size = 0;
		head_tail->next = head_tail;
		head_tail->prev = head_tail;
	}
	tmp_node = _List.head_tail->next;		// Die Listen-Knotenwerte werden kopiert
	while (tmp_node != _List.head_tail)
	{
		insertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;			// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}
template <typename T>
List<T> & List<T>::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;		//  !! keine Aktion notwendig
	list_form = _List->list_form;
	Node<T> * tmp_node;
	if (list_size)
	{
		Node<T> * tmp_del;
		tmp_node = head_tail->next;
		while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		list_size = 0;
		head_tail->next = head_tail;
		head_tail->prev = head_tail;
	}
	tmp_node = _List->head_tail->next;
	while (tmp_node != _List->head_tail)	// Die Listen-Knotenwerte werden kopiert
	{
		insertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;			// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}
template <typename T>
List<T> & List<T>::operator + (const List & List_Append)
{
	// Die Methode +
	// Es werden zwei Listen aneinander gehangen.
	// Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {										// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List(this);						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;							// Merker setzten, dass es sich um eine temporäre Liste handelt
	}
	if (List_Append.list_size) {					// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head_tail->next;
		while (tmp_node != List_Append.head_tail) {
			tmp->insertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht						
	return *tmp;
}
template <typename T>
List<T> & List<T>::operator + (const List * List_Append)
{
	// Die Methode +
	// Es werden zwei Listen aneinander gehangen.
	// Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {										// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List(this);						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;							// Merker setzten, dass es sich um eine temporäre Liste handelt
	}
	if (List_Append->list_size) {					// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head_tail->next;
		while (tmp_node != List_Append->head_tail) {
			tmp->insertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht					
	return *tmp;
}
template <typename T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	// Setzen des Formates für die Ausgabesteuerung der Liste bei cout
	// das Format wird für den überladenen Operator << verwendet
	list_form.start = start;
	list_form.zwischen = zwischen;
	list_form.ende = ende;
}
template <typename T>
std::ostream & operator<<(std::ostream  & stream, List<T> const & Liste)
{
	// Ausgabe der Liste mit cout
	stream << Liste.list_form.start;
	for (Node<T> * tmp = Liste.head_tail->next; tmp != Liste.head_tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}
template <typename T>
std::ostream & operator << (std::ostream & stream, List<T> const * Liste)
{
	// Ausgabe der Liste mit cout
	stream << Liste->list_form.start;
	for (Node<T> * tmp = Liste->head_tail->next; tmp != Liste->head_tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->head_tail ? Liste->list_form.ende : Liste->list_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

#endif

