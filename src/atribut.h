#ifndef ATRIBUT_H
#define ATRIBUT_H
#include <string>

template <typename T>
class  atribut
{
  private:
  std::string name;
  T value;
  public:
  void insert_value(const T val)
  {
      value=val;
  }
  void insert_name(std::string s)
  {
      name=s;
  }
  T return_value()
  {
      return value;
  }
  std::string return_name()
  {
      return name;
  }
};
#endif // ATRIBUT_H
