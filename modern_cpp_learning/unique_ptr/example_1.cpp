// example_1.cpp - basic usage of std::unique_ptr
#include <iostream>
#include <memory>    // for std::unique_ptr
//-------------------------------------------------------------------
class Robot
{
   std::string m_name;
public:
   Robot(const std::string &n)
   : m_name(n)
   {
      std::cout << "Robot " << m_name << " created.\n";
   }
   ~Robot()
   {
      std:: cout << "Robot " << m_name << " destroyed.\n";
   }
   void work()
   {
      std::cout << m_name << " is working.\n";
   }
};
//-------------------------------------------------------------------
int main(int argc, char* argv[])
{
   auto ptr{std::make_unique<Robot>("R2D2")};
   ptr.get()->work();
   return 0;
}
