#include <iostream>

class CSingleton{
public:
    static CSingleton * objSingleton();
    virtual ~CSingleton();
    int show_number();
private:
    CSingleton();
    int number;
};

CSingleton * CSingleton::objSingleton(){
    static CSingleton *singleObj = new CSingleton();
    return singleObj;
}

CSingleton::CSingleton(){
    std::cout<<"I am first and only one object which will be created." <<
    "(Amount of pointers can be more than one, but all of them will be point exactly that same address in memory)\n";
    this->number=1;
}

CSingleton::~CSingleton(){
};

int CSingleton::show_number(){
    return this->number;
}

int main (int argc, char *argv[]){

    //CSingleton obj_test;  //<- we can't do that, because constructor is private!
    //CSingleton *point_single = new CSingleton(); // Another example how do not do

    CSingleton *pointer_obj_single = CSingleton::objSingleton();
    std::cout<<"Address of object: "<<&pointer_obj_single<< " number: " << pointer_obj_single->show_number() << " \n";

    CSingleton *pointer_obj_single2 = CSingleton::objSingleton();
    std::cout<<"Address of object: "<<&pointer_obj_single2<< " number: " << pointer_obj_single2->show_number() << " \n";

    CSingleton *pointer_obj_single3 = CSingleton::objSingleton();
    std::cout<<"Address of object: "<<&pointer_obj_single3<< " number: " << pointer_obj_single3->show_number() << " \n";

    return 0;
}
