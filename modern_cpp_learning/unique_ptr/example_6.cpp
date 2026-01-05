// example_6.cpp using of a raw function pointer as a custom file_deleter
// for std::unique_ptr
#include <iostream>
#include <memory> // for std::unique_ptr
#include <cstdio>

void file_cleanup(FILE* fl)
{
   if (fl)
   {
      std::cout << "Closing using function pointer deleter." << std::endl;
      std::fclose(fl);
   }
}
//-------------------------------------------------------------------
int main(int argc, char* argv[])
{
   // the deleter type is a pointer to a function: void(*)(FILE*)
   std::unique_ptr<FILE, void(*)(FILE*)>
            file_ptr(std::fopen("text.txt", "w"), file_cleanup);
   if (file_ptr)
   {
      std::fputs("One last hello!\n", file_ptr.get());
   }
   // file_cleanup is called when file_ptr goes out of scope
   return 0;
}
