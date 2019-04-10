# ADS 1.1 Aufgabenstellung
1. Der erste Teil der Aufgabe besteht darin, dass Sie eine Klasse bereit stellen, die die Datenstruktur einer dynamisch, doppelt verketteten Liste zur Verfugung stellt. Um die Aufgabe zun ¨ ¨achst zu
vereinfachen gehen wir von der Speicherung von integer-Werten (als key) aus. Zur Speicherung
der Daten ben¨otigen wir eine Klasse Node. Die Klasse List dient zur Verwaltung der Datenstruktur und die Klasse Node zu Speicherung der Inhalte.
Wir ben¨otigen folgende Dateien:
Node.h Headerdatei der Klasse Node
Node.cpp c++ Quelle der Klasse Node
List.h Headerdatei der Klasse List
List.cpp c++ Quelle der Klasse List
main.cpp Testprogramm fur die Klasse List ¨
Diese Dateien liegen als Download auf dem ILIAS-Server (Praktikum 1 - Hilfsmaterialien: Aufgabe1a - zip-archivierte Dateien).
Kopieren Sie die Dateien in ein neues C++ Projekt. Ver¨andern Sie nicht die Headerdateien und
auch nicht die Datei ”Node.cpp”. Fugen Sie den fehlenden Code in die Quelldateien ein (List.cpp ¨
und main.cpp).
In einem Objekt der Klasse List gibt es mindestens ein Objekt der Klasse Node. Das erste Objekt
der Klasse Node wird im Konstruktor der Klasse List erzeugt (Anker: head tail). Dieses Objekt
zeigt auf den Anfang und gleichzeitig auf das Ende der Liste. Auf den Wert key in diesem
Objekt wird nicht zugegriffen.
1
FH Aachen
Fachbereich
Elektrotechnik und
Informationstechnik ADS Praktikum
SS 2019
In der C++ Quelle der Klasse List sind einige Methoden nur allgemein sprachlich in der zu
erfullenden Funktion beschrieben. Erzeugen Sie den notwendigen C++ Quellcode. ¨
Die main.cpp enth¨alt ein Testprogramm mit dem die Methoden der Klasse gepruft werden ¨
k¨onnen. Dort mussen Sie weitere Testbeispiele einf ¨ ugen, um alle m ¨ ¨oglichen F¨alle testen zu
k¨onnen.
Bevor Sie weitermachen: Testen Sie mit Hilfe des Debuggers, ob der Dekonstruktor
korrekt arbeitet. Dies fuhren Sie im Praktika Ihrem Betreuer vor. ¨
2. Der zweite Teil der Aufgabe besteht darin, dass Sie die Klasse List und die Klasse Node je zu
einer Template Klasse umbauen.
Gehen Sie wie folgt vor:
Kopieren Sie alle Dateien in ein neues Projekt. Anschließend wird der Programmteil von Node.cpp in die Datei Node.h kopiert (unterhalb der Klassendefinition). Anschließen kopieren Sie
den Programmteil von List.cpp in List.h und l¨oschen dann die Dateien Node.cpp und List.cpp.
Jetzt bauen Sie beide Klassen zu Template Klassen um.
Hinweis zu friend ... im ursprunglichen List.h-Teil der Klasse List: Hier muss zus ¨ ¨atzlich noch ein:
template <typename T>
friend std::ostream & operator << (std::ostream & stream, const List<T> & Liste);
eingesetzt werden.
W¨ahlen Sie fur die Template-Klasse List den Datentyp ¨ <int> im main-Programm.
3. Der letzte Teil der Aufgabe besteht nun darin, die ursprungliche Aufgabe zu realisieren. Kopie- ¨
ren Sie dazu wieder alle Datein vom 2. Projekt in ein neues Projekt außer die Datei main.cpp.
Dafur f ¨ ugen Sie die Datei tweet.h und main.cpp, die Sie im Downloadbereich des ILIAS-Server ¨
(Praktikum 1 - Hilfsmaterialien: Aufgabe1b - zip-archivierte Dateien) finden, ein
