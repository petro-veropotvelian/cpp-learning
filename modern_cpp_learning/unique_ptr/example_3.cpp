// example_3.cpp typical mistakes of using std::unique_ptr
#include <iostream>
#include <memory> // for std::unique_ptr
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
//--------------------------------------------------------------
int main(int argc, char*argv[])
{
   std::unique_ptr<Robot> r1 = std::make_unique<Robot>("R1");
   // std::unique_ptr<Robot> r2 = r1;  // this code will cause a
                                       // compilation error because
                                       // copy assignment is disabled
   std::unique_ptr<Robot> r2{};
   std::cout << "r1 is " << (r1 ? "not null\n": "null\n");
   std::cout << "r2 is " << (r2 ? "not null\n": "null\n");
   r2 = std::move(r1);    // r2 takes ownerhsip , and r1 is set to null
   std::cout << "Ownership transferred\n";
   std::cout << "r1 is " << (r1 ? "not null\n": "null\n");
   std::cout << "r2 is " << (r2 ? "not null\n": "null\n");
   return 0;
}
