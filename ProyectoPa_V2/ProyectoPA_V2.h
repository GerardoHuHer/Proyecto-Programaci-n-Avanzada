#ifndef PROYECTOPA_V2_H
#define PROYECTOPA_V2_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <map>

class Book {
private:
	long book_id;
	long good_reads_book_id;
	long best_book_id;
	long work_id;
	long books_count;
	char isbn[20];
	char isbn13[20];
	char author[150];
	long original_publication_year;
	char original_title[150];
	char title[150];
public:
	// Constructor
	Book(long, long, long, long, long, std::string, std::string, std::string, long, std::string, std::string);

	// Sobrecarga de operadores
	friend std::ostream& operator<<(std::ostream& os, const Book& objeto);
	friend std::string busqueda_libro(const long& libro_id, std::vector<Book>& vec);

	// Setter's	
	void set_isbn(const std::string& isbn);
	void set_isbn13(const std::string& isbn13);
	void set_author(const std::string& author);	
	void set_original_title(const std::string& original_title);
	void set_title(const std::string& title);
};

// Clase Ratings
class Ratings {
private:
	int user_id;
	int book_id;
	int rating;
public:	
	Ratings(int user = 0, int bookid = 0, int rat = 0);
	friend std::ostream& operator<<(std::ostream& os, const Ratings& objeto);

	friend std::map<int, std::vector<std::string>> user_map(std::vector<Book>& vec,
		const std::vector<Ratings>& vec1, const std::vector<Ratings>& vec2, 
		const std::vector<Ratings>& vec3, const std::vector<Ratings>& vec4, 
		const std::vector<Ratings>& vec5);	
};

enum class Opciones {
	TODOS_LIB = 1, MAYOR, MENOR, LIB_PROMEDIO, SALIR
};

std::string obtenerEntreComillas(std::istream& input);
bool primerCaracterEsComilla(std::istream& input);
std::vector<Book> lectureBook(std::string, std::vector<Book>&);
std::vector<Ratings> lectureRating(std::string, std::vector<Ratings>&);
std::pair<int, std::vector<std::string>> mayor(std::map<int, std::vector<std::string>>& mapa);

Opciones enterOpciones();

void menu(std::map<int, std::vector<std::string>>&, std::vector<Book>&);
void devolver_mayor(std::map<int, std::vector<std::string>>& mapa);
void devolver_menor(std::map<int, std::vector<std::string>>& mapa);
void impresion_libros(std::vector<Book>&);
void promedio_libros(std::map<int, std::vector<std::string>>& mapa);

#endif
