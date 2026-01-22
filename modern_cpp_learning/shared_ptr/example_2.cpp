// example_2.cpp  - usage of std::shared_ptr with containers
#include <iostream>
#include <memory>    // for std::shared_ptr
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
   std::vector<std::shared_ptr<Robot>> robots;
   robots.push_back(std::make_shared<Robot>("Robo-1"));
   robots.push_back(std::make_shared<Robot>("Robo-2"));
   robots.push_back(std::make_shared<Robot>("Robo-3"));
   std::cout << "The number of links to the first robot: "
             << robots[0].use_count() << "\n";
   auto copy = robots[0];      // copying increments the counter
   std::cout << "After the copying: " << robots[0].use_count() << "\n";
   return 0;
} // All objects will be automatically destroyed
