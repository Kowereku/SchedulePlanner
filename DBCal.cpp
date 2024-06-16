#include "DBCal.h"


void createDBCal(const char* s)
{
	sqlite3* DBCal;
	int exit = 0;

	exit = sqlite3_open(s, &DBCal);

	sqlite3_close(DBCal);
}
void createTable(const char* s)
{
	sqlite3* DBCal;

	string sql =
		"CREATE TABLE IF NOT EXISTS calevents ("
		"id	INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,"
		"priority	INTEGER NOT NULL DEFAULT 0,"
		"name	TEXT NOT NULL,"
		"desc	TEXT,"
		"type	TEXT NOT NULL DEFAULT 'NORMAL',"
		"day	TEXT NOT NULL,"
		"start	TEXT NOT NULL,"
		"end	TEXT);";


	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DBCal);

		char* messaggeError;
		exit = sqlite3_exec(DBCal, sql.c_str(), NULL, 0, &messaggeError);

		if (exit != SQLITE_OK)
		{
			cerr << "Nie dziala baza danych" << endl;
			sqlite3_free(messaggeError);
		}
		else
			cout << "Polaczono z baza danych" << endl;
		sqlite3_close(DBCal);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
}

void insert(const char* s, string name, string desc, string type, string day, string starth, string endh)
{
	sqlite3* DBCal;
	char* messageError;

	int exit = sqlite3_open(s, &DBCal);

	string sql("INSERT INTO calevents (name, desc, type, day, start, end) VALUES ('" + name + "', '" + desc + "', '" + type + "', '" + day + "', '" + starth + "', '" + endh + "');");

	exit = sqlite3_exec(DBCal, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Blad w dodawaniu: " << endl;
		sqlite3_free(messageError);
	}
	sqlite3_close(DBCal);
}

void update(const char* s, int id, string name, string desc, string type, string day, string starth, string endh)
{
	sqlite3* DBCal;
	char* messageError;

	int exit = sqlite3_open(s, &DBCal);
	if (exit != SQLITE_OK) {
		cerr << "Błąd przy otwieraniu bazy danych: " << sqlite3_errmsg(DBCal) << endl;
		return;
	}

	string sql = "UPDATE calevents SET name = ?, desc = ?, type = ?, day = ?, start = ?, end = ? WHERE id = ?";

	sqlite3_stmt* stmt;
	exit = sqlite3_prepare_v2(DBCal, sql.c_str(), -1, &stmt, nullptr);
	if (exit != SQLITE_OK) {
		cerr << "Błąd przy przygotowywaniu zapytania: " << sqlite3_errmsg(DBCal) << endl;
		sqlite3_close(DBCal);
		return;
	}

	// Bind the parameters
	sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, desc.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, type.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 4, day.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 5, starth.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 6, endh.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_int(stmt, 7, id);

	exit = sqlite3_step(stmt);
	if (exit != SQLITE_DONE) {
		cerr << "Błąd przy wykonywaniu zapytania: " << sqlite3_errmsg(DBCal) << endl;
	}
	else {
		cout << "Zaktualizowano pomyślnie" << endl;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DBCal);
}

void deleteRec(const char* s, int id)
{
	sqlite3* DBCal;

	int exit = sqlite3_open(s, &DBCal);

	string sql = "DELETE FROM calevents WHERE id = ?";
	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(DBCal, sql.c_str(), -1, &stmt, nullptr);
	sqlite3_bind_int(stmt, 1, id);
	if (sqlite3_step(stmt) != SQLITE_DONE) {
		cerr << "Blad w usuwaniu: " << sqlite3_errmsg(DBCal) << std::endl;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DBCal);
}

vector<Event> select(const char* s)
{
	sqlite3* DBCal;
	vector<Event> events;

	if (sqlite3_open(s, &DBCal)) {
		cerr << "Nie można otworzyć bazy danych: " << sqlite3_errmsg(DBCal) << endl;
		return events;
	}

	const char* sql = "SELECT * FROM calevents";
	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(DBCal, sql, -1, &stmt, nullptr) != SQLITE_OK) {
		cerr << "Nie można wykonać zapytania: " << sqlite3_errmsg(DBCal) << endl;
		return events;
	}

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		int id = sqlite3_column_int(stmt, 0);
		string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		string desc = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
		string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
		string day = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
		string starth = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
		string endh = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
		events.push_back(Event(id, title, desc, type, day, starth, endh));
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DBCal);

	return events;
}

Event select(const char* s, int id)
{
	sqlite3* DBCal;
	string title;
	string desc;
	string type;
	string day;
	string starth;
	string endh;

	if (sqlite3_open(s, &DBCal)) {
		cerr << "Nie można otworzyć bazy danych: " << sqlite3_errmsg(DBCal) << endl;
	}

	const char* sql = "SELECT * FROM calevents WHERE id = ?";
	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(DBCal, sql, -1, &stmt, nullptr) != SQLITE_OK) {
		cerr << "Nie można wykonać zapytania: " << sqlite3_errmsg(DBCal) << endl;
	}
	sqlite3_bind_int(stmt, 1, id);

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		desc = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
		type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
		day = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
		starth = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
		endh = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

	}
	Event event(id, title, desc, type, day, starth, endh);
	sqlite3_finalize(stmt);
	sqlite3_close(DBCal);
	

	return event;
}