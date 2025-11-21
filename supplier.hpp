#include"program.hpp"
#include"object.hpp"

class supplier : public object{
private:

public:
    int supply;
    supplier(int num,int x,int y);
    void update() override;
};