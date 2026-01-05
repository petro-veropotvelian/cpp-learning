// example_4.cpp specificity of usage std::unique_ptr with a custom deleter
#include <iostream>
#include <memory>
#include <cstdio>
//-------------------------------------------------------------------
// define a struct with an operator() that performs custom deletion/cleanup
struct FileCloser
{
   void operator()(FILE* fl) const
   {
      if (fl)
      {
         std::cout << "Closing file using custom deleter\n";
         std::fclose(fl);
      }
   }
};
//-------------------------------------------------------------------
int main(int argc, char* argv[])
{
   // define an alias for clarity
   using UniqueFilePtr = std::unique_ptr<FILE, FileCloser>;
   // create the unique_ptr, passing raw pointer to the constructor
   // the deleter is default-constructed internally
   FILE* file_handle = std::fopen("text.txt", "a+");
   if (file_handle)
   {
      UniqueFilePtr file_ptr(file_handle);
      fprintf(file_handle, "\nThe example of usage std::unique_ptr ");
      fprintf(file_handle, "with a custom deleter.\n");
   }
   else
   {
      std::cerr << "Failed to open file." << std::endl;
   }
   return 0;
}
