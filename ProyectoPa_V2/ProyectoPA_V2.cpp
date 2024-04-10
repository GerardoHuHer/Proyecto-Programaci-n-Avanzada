#include "ProyectoPA_V2.h"

int main(){
  std::vector<Book> libros = lectureBook("/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/books.csv");
  std::vector<Ratings> rat1;
  std::vector<Ratings> rat2;
  std::vector<Ratings> rat3;
  std::vector<Ratings> rat4;
  std::vector<Ratings> rat5;
  // std::vector<Book> libros;
  std::thread t1(lectureRating, "/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/chunk_1.csv", ref(rat1));
  std::thread t2(lectureRating, "/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/chunk_2.csv", ref(rat2));
  std::thread t3(lectureRating, "/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/chunk_3.csv", ref(rat3));
  std::thread t4(lectureRating, "/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/chunk_4.csv", ref(rat4));
  std::thread t5(lectureRating, "/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/chunk_5.csv", ref(rat5));
  // std::thread b1(lectureBook, "/home/gd_15/Escritorio/CPP/Proyecto-Programaci-n-Avanzada/ArchivosLectura/books.csv", ref(libros));


  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  // b1.join();
  // std::vector<Ratings> rat2 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_2.csv");
  // std::vector<Ratings> rat3 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_3.csv");
  // std::vector<Ratings> rat4 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_4.csv");
  // std::vector<Ratings> rat5 = lectureRating("/home/gerardohuerta1502/Escritorio/ProyectaPA_V2/ArchivosLectura/chunk_5.csv");
  std::map<int, std::vector<std::string>> mapa = user_map(libros, rat1, rat2, rat3, rat4, rat5);
  menu(mapa, libros);
  return 0;
}
