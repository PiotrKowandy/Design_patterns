#include <iostream>


class Singleton{

    public:
    Singleton(Singleton&) = delete;
    Singleton& operator=(Singleton&) = delete;

    static Singleton* get_instance(){
        static Singleton* instance(new Singleton);
        return instance;
    }
   ~Singleton(){
       counter--;
       delete instance;
    }
    static int counter;

    private:
    Singleton(){
        counter++;
    }
    static Singleton* instance;

};
int Singleton::counter = 0;


int main(){
    
    Singleton* new_one = Singleton::get_instance();
    Singleton* second_one = Singleton::get_instance();
    std::cout<< "Number of instances: " << Singleton::counter << "\n";

    return 0;
}