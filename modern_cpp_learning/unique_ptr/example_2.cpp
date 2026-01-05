// example_2.cpp make_unique and ownership transfer
#include <iostream>
#include <vector>
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
//-------------------------------------------------------------------
std::unique_ptr<Robot> createRobot(const char* szName)
{
   return std::make_unique<Robot>(szName);
}
//-------------------------------------------------------------------
void takeOwnership(std::unique_ptr<Robot> owned_obj)
{// owned_ojb now manages the lifetime of the object
   owned_obj->work();
   // when takeOwnership() returns, owned_obj goes out of scope
   // and deletes the object
}
int main(int argc, char* argv[])
{
   std::vector<std::unique_ptr<Robot>> v_Robots;
   v_Robots.push_back(createRobot("R2D2"));
   v_Robots.push_back(createRobot("Voltron"));
   v_Robots.push_back(createRobot("Megatron"));
   for (auto& ptr : v_Robots)
   {
      takeOwnership(std::move(ptr));
   }
   return 0;
}
