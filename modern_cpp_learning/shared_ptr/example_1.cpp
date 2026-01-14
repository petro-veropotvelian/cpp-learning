// example_1.cpp - simple example of using std::shared_ptr
#include <iostream>
#include <memory> // for std::shared_ptr
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
   Robot* rbt {new Robot("Grendizer")};   // allocate a Robot object
   std::shared_ptr<Robot> ptr1{rbt};      // and make it owned by shared_ptr
   ptr1.get()->work();
   std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;
   {
      std::shared_ptr<Robot> ptr2{ptr1};  // make another shared_ptr,
                                          // pointing at the same object
      ptr2.get()->work();
      std::cout<<"ptr2.use_count() = " << ptr2.use_count() << std::endl;
      std::cout<< "\nDestroying one shared pointer\n";
   } // ptr2 is goes out of scope and nothing happens
   std::cout << "\nDestroying another shared pointer\n";
   return 0;
}// ptr1 is goes out of scope and allocated resource is destroyed
