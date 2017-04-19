#ifndef ER_DIAGRAM_H
#define ER_DIAGRAM_H
#include <string>
#include <vector>

class er
{
  private:

  struct relation{
                std::string type;
                er *other;
            };

  std::vector<relation> *relations;
  std::vector<void*> *atributs;
  std::vector<std::string> *types;
  int i_at;
  int i_re;
 public:
  er();
  ~er();
  int insert_relatin(std::string type,er *other);
  int insert_atribut(void* atribute,std::string type);
  int return_amount_atributs();
  std::string return_atribut_type(int i);
  int return_amount_relations();
  void* return_atribut(int i);
  er* return_relation(int i);
  std::string return_relation_type(int i);
};


#endif // ER_DIAGRAM_H
