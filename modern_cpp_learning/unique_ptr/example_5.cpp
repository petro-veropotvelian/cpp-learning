// exmaple_5.cpp specificity of usage std::unique_ptr with a custom deleter
// using Lambda function as a custom deleter
#include <iostream>
#include <memory>  // for std::unique_ptr
#include <cstdio>  // for FILE* and fopen

int main(int argc, char* argv[])
{
   // Define the lambda deleter
   auto file_deleter = [](FILE* f)
   {
      if (f)
      {
         std::cout << "Closing a file using lambda deleter." << std::endl;
         std::fclose(f);
      }
   };
   // The deleter type (decltype(file_deleter)) must be a template
   // argument
   std::unique_ptr<FILE, decltype(file_deleter)>
                          file_ptr(std::fopen("text.txt", "w"), file_deleter);
   if (file_ptr)
   {
      std::fputs("Hello again!\n", file_ptr.get());
   }
   // The lambda function is called when file_ptr is goes out of scope
   return 0;
}
