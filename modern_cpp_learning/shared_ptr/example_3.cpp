// example_3.cpp shared ownership with containers
#include <iostream>
#include <memory>
#include <vector>
//-------------------------------------------------------------------
class Robot          // our simple class for demostration
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
int main(int argc, char*argv[])
{
   std::cout << "\n=== Shared ownership example ===\n";
   std::vector<std::shared_ptr<Robot>> vect1;
   std::vector<std::shared_ptr<Robot>> vect2;
   auto s_robot = std::make_shared<Robot>("Bender");
   vect1.push_back(s_robot);
   vect2.push_back(s_robot);     // the same object in two containers
   std::cout << "The counter of links: " << s_robot.use_count() << "\n";
   vect1.clear();
   std::cout << "After clearing vect1: " << s_robot.use_count() << "\n";
   vect2.clear();
   std::cout << "After clearing vect2: " << s_robot.use_count() << "\n";
   return 0;
} // s_robot will be destroyed here
