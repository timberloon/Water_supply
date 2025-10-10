#include"object.hpp"

class house : public object{
private: int h_no;
public:
    house(int num,std::string tex,int x,int y,int width,int height);
    void update() override;
};
