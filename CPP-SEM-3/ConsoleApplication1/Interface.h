#pragma once
#include "Teacher.h"
#include "Party.h"
#include "Teacher_Party.h"
#include "File.h"
#include "myalgorithm.h"


template<typename T>
class Interface
{
private:
    int txtbin;
    T obj;
    std::string fileN;
public:
    Interface() { }
    ~Interface() { }
    Interface(std::string f, int value) : fileN(f), txtbin(value) { }
    static void menu();
    void Funck();
};



template<typename T>
inline void Interface<T>::menu()
{
    int state = 0;
    int ch = 0;
    do {

        std::cout << " Работа с Файлами." << std::endl;
        std::cout << " 1. TXT." << std::endl;
        std::cout << " 2. Binary." << std::endl;
        std::cout << " 0. exit." << std::endl;
        state = input_INT(std::cin, 0, 2);
        if (state == 0)
            break;

        system("cls");
        std::cout << " 1. Учитель." << std::endl;
        std::cout << " 2. Партия." << std::endl;
        std::cout << " 3. Учитель Партия. " << std::endl;
        std::cout << " 0. Выход. ";
        ch = input_INT(std::cin, 0, 3);
        system("cls");
        switch (ch)
        {
        case 1:
        {
            std::string filenameT;
            if (state == 1)
                filenameT = "teacher.txt";
            else if (state == 2)
                filenameT = "teacherBin.txt";

            Interface<Teacher> objTeacher(filenameT, state);
            objTeacher.Funck();
            break;
        }
        case 2:
        {
            std::string filenameP;
            if (state == 1)
                filenameP = "party.txt";
            else if (state == 2)
                filenameP = "partyBin.txt";

            Interface<Party> objParty(filenameP, state);
            objParty.Funck();
            break;
        }
        case 3:
        {
            std::string filenameTP;
            if (state == 1)
                filenameTP = "teacher_party.txt";
            else if (state == 2)
                filenameTP = "teacher_partyBin.txt";

            Interface<Teacher_Party> objTeacher_Party(filenameTP, state);
            objTeacher_Party.Funck();
            break;
        }
        default:
            break;
        }
    } while (ch != 0);
}

template<typename T>
inline void Interface<T>::Funck()
{
    Queue<T>* obj = new Queue<T>;
    typename Queue<T>::Iter it;
    T value{};
    T result{};
    int flags = 0;
    do {
        system("cls");
        std::cout << " ---===[ Выбор меню ]===---" << std::endl;
        std::cout << " 1.  Добавить элемент." << std::endl;
        std::cout << " 2.  Вывод на экран." << std::endl;
        std::cout << " 3.  Удалить." << std::endl;
        std::cout << " 4.  Удалить и возвратить." << std::endl;
        std::cout << " 5.  Удалить Все." << std::endl;
        std::cout << " 6.  Поиск." << std::endl;
        std::cout << " 7.  Изменить." << std::endl;
        std::cout << " 8.  Сортировать." << std::endl;
        std::cout << " 9.  Читать из файла." << std::endl;
        std::cout << " 10. Запись в файла." << std::endl;
        std::cout << " 11. iterator.begin(); " << std::endl;
        std::cout << " 12. iterator.end(); " << std::endl;
        std::cout << " 13. for(iterator) ." << std::endl;
        std::cout << " 14. for(iterator.reverse) ." << std::endl;
        std::cout << " 0   Возврат в главный меню.\t  ";
        flags = input_INT(std::cin, 0, 15);
        system("cls");
        switch (flags)
        {
        case 1:
        {
            rewind stdin;
            std::cin >> value;
            obj->Enqueue(value);
            break;
        }
        case 2:
        {
            if (!obj->Empty())
            {
                obj->Title();
                obj->show();
                break;
            }
            std::cout << "Очередь пуст!!! " << std::endl;
            break;
        }
        case 3:
        {
            if (!obj->Empty())
            {
                obj->Dequeue1();
                break;
            }
            std::cout << "Очередь пуст!!! " << std::endl;
            break;
        }
        case 4:
        {
            if (!obj->Empty())
            {
                result = obj->Dequeue();
                std::cout << " Удаленный данные:  " << result << std::endl;
            }
            else std::cout << "  Пуст! " << std::endl;
            break;
        }
        case 5:
        {
            obj->Clear();
            break;
        }
        case 6:
        {
            if (!obj->Empty())
            {
                /*  T count{};
                  std::cout << " Enter found value \n"; std::cin >> count;*/
                Queue<T>* elem = Searche<T>(obj->begin(), obj->end(), [](T a, T b) -> bool { return a == b; });
                if (!elem->Empty()) {
                    obj->Title();
                    for (typename Queue<T>::Iter i = elem->begin(); i != elem->end(); i++)
                    {
                        std::cout << *i << std::endl;
                    }
                }
                else
                    std::cout << " nothing " << std::endl;
                break;
                /*  Queue<T>* elem = obj->sSearch();
                obj->Title();
                elem->show();*/
                delete elem;
            }
            else
                std::cout << "  Пуст! " << std::endl;
            break;
        }
        case 7:
        {
            if (!obj->Empty()) {
                Print<T>(obj->begin(), obj->end());
                std::cout << " Введите номер редоктируемого объекта " << std::endl;
                int elem = input_INT(std::cin, 1, obj->GetSize()) - 1;
                Edited<T>(obj->begin(), obj->end(), elem, obj->GetSize());
                //Edited(obj);
            }
            else
                std::cout << " Nothing editing" << std::endl;
            break;
        }
        case 8:
        {
            if (!obj->Empty()) {
                std::cout << " <----= Сортировать =----> ; " << std::endl;
                std::cout << " 1. Фамилия. " << std::endl;
                std::cout << " 2. Имя." << std::endl;
                std::cout << " 3. Год рождения." << std::endl;
                switch (input_INT(std::cin, 1, 3))
                {
                case 1:BubbleSort<T>(obj->begin(), obj->end(), [](T a, T b) -> bool {return a.getFirstname() > b.getFirstname(); }); break;
                case 2:BubbleSort<T>(obj->begin(), obj->end(), [](T a, T b) -> bool {return a.getLastname() > b.getLastname(); }); break;
                case 3:BubbleSort<T>(obj->begin(), obj->end(), [](T a, T b) -> bool {return b.getYear() > a.getYear(); }); break;
                default:
                    break;
                }
            }
            else {
                std::cout << " Nothing sort" << std::endl;
            }
            //BubbleSort<T>(obj->begin(), obj->end(), [](T a, T b) -> bool {return a.getFirstname() > b.getFirstname(); });
            //obj->BubleSort();
            break;
        }
        case 9:
        {
            T data;
            if (this->txtbin == 1)
            {
                FileTXT<T> fin(fileN);
                obj->Clear();
                fin.fileTxTOpenIn();
                while (1)
                {
                    fin.readTxt(data);
                    if (fin.FileTxTeofIn())
                    {
                        fin.fileTxTCloseIn();
                        break;
                    }
                    obj->Enqueue(data);
                }
            }
            else if (this->txtbin == 2)
            {
                FileBin<T> file(fileN);
                obj->Clear();
                while (1)
                {
                    file.ReadBin(data);
                    if (file.EndOfFile())
                        break;
                    obj->Enqueue(data);
                }
            }
            break;
        }
        case 10:
        {
            T data;
            if (this->txtbin == 1)
            {
                FileTXT<T> fout(fileN);
                fout.fileTxTOpenOut();
                while (!obj->Empty())
                {
                    data = obj->Dequeue();
                    fout.writeTxt(data);
                }
                fout.fileTxTCloseOut();
            }
            else if (this->txtbin == 2)
            {
                FileBin<T> file(fileN);
                while (!obj->Empty())
                {
                    data = obj->Dequeue();
                    file.WriteBin(data);
                }
            }
            break;
        }

        case 11: { it = obj->begin(); break; }
        case 12: { it = obj->end(); break;  }
        case 13: { Print<T>(obj->begin(), obj->end()); break; }
        case 14: {
            obj->Title();
            for (it = obj->r_begin(); it != obj->r_end(); it--)
                std::cout << *it << std::endl;
            break;
        }
        case 15: {
            /*  it = obj->begin();
              if (!obj->Empty())
              {
                  T count{};
                  std::cout << " Enter found value ";  std::cin >> count;
                  Queue<T> elem = Searche(obj->begin(),obj->end(), count);
                  obj->Title();
                  for (it = elem.begin(); it != elem.end(); it++)
                      std::cout << *it << std::endl;
                  //elem->show();
                  //delete elem;
          }*/
          // else std::cout << " Not Found sorry my friend " << std::endl;
            break;

        }
        default:
            break;
        }
        system("pause");
    } while (flags != 0);

    delete obj;
}
