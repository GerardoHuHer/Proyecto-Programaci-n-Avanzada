#include "ProyectoPA_V2.h"

int main(){
  std::vector<Book> libros = lectureBook("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/books.csv");
  std::vector<Ratings> rat1 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_1.csv");
  std::vector<Ratings> rat2 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_2.csv");
  std::vector<Ratings> rat3 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_3.csv");
  std::vector<Ratings> rat4 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_4.csv");
  std::vector<Ratings> rat5 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_5.csv");
  std::map<int, std::vector<std::string>> mapa = user_map(libros, rat1, rat2, rat3, rat4, rat5);
  menu(mapa, libros);
  return 0;
}
