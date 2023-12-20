#include "ProyectoPA_V2.h"

Ratings::Ratings(int user, int book, int rat ) {
	this->user_id = user;
	this->book_id = book;
	this->rating = rat;
}
std::string busqueda_libro(const long& libro_id, std::vector<Book>& vec){    
    std::string titulo;
    for (int i = 0; i < vec.size(); i++) {        
        if (vec[i].book_id == libro_id) {
            if (vec[i].original_title == "") {
                titulo = vec[i].title;
                break;
            }
            else {
                titulo = vec[i].original_title;
                break;
            }
        }
    }
    return titulo;
}
std::ostream& operator<<(std::ostream& os, const Ratings& objeto) {
	os << "User ID: " << objeto.user_id << ", Book ID: " << objeto.book_id << ", Rating: " << objeto.rating;
	return os;
}
std::ostream& operator<<(std::ostream& os, const Book& objeto) {
	os << "ID Libro: " << objeto.book_id
		<< "\nGood reads ID: " << objeto.good_reads_book_id
		<< "\nBest Book ID: " << objeto.best_book_id
		<< "\nWork ID: " << objeto.work_id
		<< "\nBook count: " << objeto.books_count
		<< "\nISBN: " << objeto.isbn
		<< "\nISBN13: " << objeto.isbn13
		<< "\nAutor: " << objeto.author
		<< "\nAgno: " << objeto.original_publication_year
		<< "\nOriginal: " << objeto.original_title
		<< "\nTitulo: " << objeto.title;
		
	return os;
}
std::map<int, std::vector<std::string>> user_map(std::vector<Book>& vec,
    const std::vector<Ratings>& vec1, const std::vector<Ratings>& vec2,
    const std::vector<Ratings>& vec3, const std::vector<Ratings>& vec4,
    const std::vector<Ratings>& vec5) {
    std::map<int, std::vector<std::string>> mapa;    
    for (int i = 0; i < vec1.size(); i++) {        
        mapa[vec1[i].user_id].push_back(busqueda_libro(vec1[i].book_id, vec));     
    }
    for (int i = 0; i < vec2.size(); i++) {
        mapa[vec2[i].user_id].push_back(busqueda_libro(vec2[i].book_id, vec));
    }
    for (int i = 0; i < vec3.size(); i++) {
        mapa[vec3[i].user_id].push_back(busqueda_libro(vec3[i].book_id, vec));
    }
    for (int i = 0; i < vec4.size(); i++) {
        mapa[vec4[i].user_id].push_back(busqueda_libro(vec4[i].book_id, vec));
    }
    for (int i = 0; i < vec5.size(); i++) {
        mapa[vec5[i].user_id].push_back(busqueda_libro(vec5[i].book_id, vec));
    }
    return mapa;
}
// Clase Book
Book::Book(long book_id, long good_reads_book_id = 0, long best_book_id = 0, long work_id = 0, long books_count = 0,
	const std::string isbn = "", const std::string isbn13 = "", const std::string author = "",
	long year = 0, const std::string original_title = "", const std::string title = "") {
	this->book_id = book_id;
    this->good_reads_book_id = good_reads_book_id;
    this->best_book_id = best_book_id;
    this->work_id = work_id;
    this->books_count = books_count;
	set_isbn(isbn);
	set_isbn13(isbn13);
	set_author(author);
	this->original_publication_year = year;
	set_original_title(original_title);
	set_title(title);
}
// Setter's definición
void Book::set_isbn(const std::string& isbn_par) {
	size_t lenght{isbn_par.size()};	
	lenght = lenght < 20 ? lenght : 19;
	isbn_par.copy(isbn, lenght);
	isbn[lenght] = '\0';	
}
void Book::set_isbn13(const std::string& isbn_par) {
	size_t lenght{ isbn_par.size() };
	lenght = lenght < 20 ? lenght : 19;
	isbn_par.copy(isbn13, lenght);
	isbn13[lenght] = '\0';
}
void Book::set_author(const std::string& author_par) {
	size_t lenght{ author_par.size() };
	lenght = lenght < 150 ? lenght : 149;
	author_par.copy(author, lenght);
	author[lenght] = '\0';
}
void Book::set_original_title(const std::string& original_t){
	size_t lenght{ original_t.size() };
	lenght = lenght < 150 ? lenght : 149;
	original_t.copy(original_title, lenght);
	original_title[lenght] = '\0';
}
void Book::set_title(const std::string& title_par) {
	size_t lenght{ title_par.size() };
	lenght = lenght < 150 ? lenght : 149;
	title_par.copy(title, lenght);
	title[lenght] = '\0';
}

std::string obtenerEntreComillas(std::istream& input) {
	char c;
	input >> c;  
	std::string entreComillas;	
	while (input.get(c) && (c != '"' || (input.peek() != ',' && input.peek() != '\n'))) {
		entreComillas += c;
	}	
    if (!(input.get(c) && c == ',')) {
        input.unget();
	}	
	return entreComillas;
}
bool primerCaracterEsComilla(std::istream& input) {
	char primerCaracter = input.peek();
	return (primerCaracter == '"');
}
std::vector<Book> lectureBook(std::string directorio) {
    std::vector<Book> libros;
    std::ifstream inputFile(directorio, std::ios::in);
    if (!inputFile) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string linea;
    std::getline(inputFile, linea);    

    while (std::getline(inputFile, linea)) {       
        std::istringstream lineStream(linea);
        std::string campo;

        long book_id = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            book_id = std::stol(campo);
        }        

        long good_reads_book_id = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            good_reads_book_id = stol(campo);
        }        

        long best_book_id = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            best_book_id = stol(campo);
        }        

        long work_id = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            work_id = stol(campo);
        }
        
        long books_count = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            books_count = std::stol(campo);
        }


        std::getline(lineStream, campo, ',');
        std::string isbn = campo;

        std::getline(lineStream, campo, ',');
        std::string isbn13 = campo;

        std::string author;
        if (primerCaracterEsComilla(lineStream)) {
            author = obtenerEntreComillas(lineStream);
        }
        else {
            std::getline(lineStream, campo, ',');
            author = campo;
        }

        long year = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            year = std::stol(campo);
        }


        std::string original_title;
        if (primerCaracterEsComilla(lineStream)) {
            original_title = obtenerEntreComillas(lineStream);
        }
        else {
            std::getline(lineStream, campo, ',');
            original_title = campo;
        }

        std::string title;
        if (primerCaracterEsComilla(lineStream)) {
            title = obtenerEntreComillas(lineStream);
        }
        else {
            std::getline(lineStream, campo);
            std::string title = campo;
        }

        Book obj(book_id, good_reads_book_id, best_book_id, work_id,
            books_count, isbn, isbn13, author, year, original_title, title);

        libros.push_back(obj);
    }

    inputFile.close();

  
    return libros;
}
std::vector<Ratings> lectureRating(std::string directorio) {
    std::vector<Ratings> rating;
    std::ifstream inputFile(directorio, std::ios::in);
    if (!inputFile) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string linea;
    std::getline(inputFile, linea);

    while (std::getline(inputFile, linea)) {
        std::istringstream lineStream(linea);
        std::string campo;

        int user_id = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            user_id = std::stol(campo);
        }        

        int book_id = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            book_id = stol(campo);
        }
        

        int rating_tem = 0;
        std::getline(lineStream, campo, ',');
        if (campo != "") {
            rating_tem = stol(campo);
        }

        Ratings obj = Ratings(user_id, book_id, rating_tem);
        rating.push_back(obj);
    }
    return rating;
}
std::pair<int, std::vector<std::string>> mayor(std::map<int, std::vector<std::string>>& mapa) {    
    std::pair<int, std::vector<std::string>> aux = { 1, {"h"}};    
    for (auto& par : mapa) {
        if (par.second.size() > aux.second.size()) {
            aux = par;
        }
    }
    return aux;
}

std::pair<int, std::vector<std::string>> menor(std::map<int, std::vector<std::string>>& mapa) {
    std::vector<std::string> aux_vec(200);
    std::pair<int, std::vector<std::string>> aux = { 1, aux_vec};
    for (auto& par : mapa) {
        if (par.second.size() < aux.second.size()) {
            aux = par;
        }
    }
    return aux;
}

Opciones enterOpciones() {
    std::cout << "\nEnter your choice\n"
        << "1 - Ver todos los libros\n"
        << "2 - Usuario con mas libros leidos\n"
        << "3 - Usuario con menos libros leidos\n"
        << "4 - Promedio de libros leidos por usuario\n"
        << "5 - Salir\n? ";

    int menuChoice;
    std::cin >> menuChoice; // input menu selection from user
    return static_cast<Opciones>(menuChoice);
}

void menu(std::map<int, std::vector<std::string>>& mapa, std::vector<Book>& libros) {
    Opciones choice;
    while ((choice = enterOpciones()) != Opciones::SALIR) {
        switch (choice) {
        case Opciones::TODOS_LIB: 
            impresion_libros(libros);
            break;
        case Opciones::MAYOR: 
            devolver_mayor(mapa);
            break;
        case Opciones::MENOR: 
            devolver_menor(mapa);
            break;
        case Opciones::LIB_PROMEDIO: 
            promedio_libros(mapa);
            break;
        default: 
            std::cerr << "No se selecciono una opcion valida" << std::endl;
            break;
        }
    }
}

void devolver_mayor(std::map<int, std::vector<std::string>>& mapa) {
    std::pair<int, std::vector<std::string>> respuesta = mayor(mapa);
    std::cout << "El usuario " << respuesta.first << " leyo " << respuesta.second.size() << " libros" << std::endl;
    std::cout << "Titulos: " << std::endl;
    for (int i = 0; i < respuesta.second.size(); i++) {
        std::cout << i + 1 << ") " << respuesta.second[i] << std::endl;
    }
}

void devolver_menor(std::map<int, std::vector<std::string>>& mapa) {
    std::pair<int, std::vector<std::string>> respuesta = menor(mapa);
    std::cout << "El usuario " << respuesta.first << " leyo " << respuesta.second.size() << " libros" << std::endl;
    std::cout << "Titulos: " << std::endl;
    for (int i = 0; i < respuesta.second.size(); i++) {
        std::cout << i + 1 << ") " << respuesta.second[i] << std::endl;
    }
}

void impresion_libros(std::vector<Book>& libros) {
    for (auto& libro : libros) {
        std::cout << libro << std::endl;
    }
}

void promedio_libros(std::map<int, std::vector<std::string>>& mapa) {
    size_t lenght{ mapa.size() };
    int lib_total{ 0 };
    for (auto& item : mapa) {
        lib_total += item.second.size();
    }
    double promedio = lib_total / lenght;
    std::cout << "El promedio de libros leidos por usuario es: " << promedio << " libros." << std::endl;
}
