#ifndef ATRIBUT_H
#define ATRIBUT_H
#include <string>

template <typename T>
class  atribut
{
  private:
  std::string name;
  std::string type;
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
  void insert_type(std::string s)
  {
      type=s;
  }
  T return_value()
  {
      return value;
  }
  std::string return_name()
  {
      return name;
  }
  std::string return_type()
  {
      return type;
  }
};
#endif // ATRIBUT_H
