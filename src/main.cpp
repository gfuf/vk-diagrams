#include <QCoreApplication>
#include <servise/VkServise.h>
#include <er_diagram.h>
#include <atribut.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //https://oauth.vk.com/authorize?client_id=5961166&scope=groups&response_type=token
    //Из этого адреса копируешь токен который просят не копировать в access_token
    QString access_token = "";
    //Сюда вводишь id пользователя
    int UserId = 127419409;
    VkServise vkSer(access_token);
    er diogram = er();
    //записываем фио и id пользователя
    VkUser user=vkSer.getVkUser(UserId);
    std::string s1=user.getFirstName().toUtf8().constData();
    std::string s2=user.getLastName().toUtf8().constData();
    atribut<std::string>* fio=new atribut<std::string>();
    fio->insert_name("fio");
    fio->insert_value(s1+" "+s2);
    diogram.insert_atribut(fio,"string");
    atribut<int>* id=new atribut<int>();
    id->insert_name("id");
    int g=user.getId();
     id->insert_value(g);
     diogram.insert_atribut(id,"int");

     //записываем фио и id друзей
    QList<VkUser> users = vkSer.getFriends(UserId);
    qDebug()<<"Вывод всех друзей: ";
    foreach (const VkUser & user, users) {
                er* new_diogram =new er();
                std::string s1=user.getFirstName().toUtf8().constData();
                std::string s2=user.getLastName().toUtf8().constData();
                fio=new atribut<std::string>();
                fio->insert_name("fio");
                fio->insert_value(s1+" "+s2);
                new_diogram->insert_atribut(fio,"string");
                id=new atribut<int>();
                id->insert_name("id");
                int g=user.getId();
                 id->insert_value(g);
                 new_diogram->insert_atribut(id,"int");
                diogram.insert_relatin("friend",new_diogram);
        qDebug()<<user.getFirstName() << " "<<user.getLastName();
    }

    //выводим фио и id друзей
    for(int i=0;i<diogram.return_amount_relations();i++)
        {
            qDebug()<<QString::fromStdString(diogram.return_relation_type(i));
            er* new_diogram=diogram.return_relation(i);
            int n=new_diogram->return_amount_atributs();
            for(int j=0;j<n;j++)
            {
                if(new_diogram->return_atribut_type(j)=="string")
                {
                    atribut<std::string>* a=(atribut<std::string>*)new_diogram->return_atribut(j);
                    qDebug()<<QString::fromStdString(a->return_name());
                    qDebug()<<QString::fromStdString(a->return_value());
                }
                if(new_diogram->return_atribut_type(j)=="int")
                {
                    atribut<int>* a=(atribut<int>*)new_diogram->return_atribut(j);
                    qDebug()<<QString::fromStdString(a->return_name()+"");
                    qDebug()<<a->return_value();
                }
            }
        }

    /*QList<VkGroup> groups = vkSer.getVkGroups(users.at(0).getId());
    qDebug()<<"Вывод всех групп первого друга: ";
    foreach (const VkGroup & group, groups) {
        qDebug()<<group.getName();
    }*/

    return a.exec();
}

