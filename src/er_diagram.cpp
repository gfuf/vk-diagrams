#include <er_diagram.h>
er::er()
{
    i_at=0;
    i_re=0;
    relations=new std::vector<relation>;
    atributs=new std::vector<void*>;
}

er::~er() {
   if (relations)
      delete[] relations;
   if (atributs)
      delete[] atributs;

}



int er::insert_relatin(std::string type,er *other)
{
  relations->push_back(relation());
  relations->at(i_re).type=type;
  relations->at(i_re).other=other;
  i_re++;
  return 0;
}

int er::insert_atribut(void* atribute)
{
  atributs->push_back(atribute);
  i_at++;
  return 0;
}
int er::return_amount_atributs()
{
    return i_at;
}

int er::return_amount_relations()
{
    return i_re;
}


er* er::return_relation(int i)
{
    return relations->at(i).other;
}
void* er::return_atribut(int i)
{
    return atributs->at(i);
}

std::string er::return_relation_type(int i)
{
    return relations->at(i).type;
}
