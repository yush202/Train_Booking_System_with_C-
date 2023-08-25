#include<iostream>//basic
#include<string>//string
#include<conio.h>//use for getch()
#include<fstream>//file hadling
#include<iomanip>//setw
#include<windows.h>//sleep


using namespace std;


class Train
{
private:
    char x,y,temp;
    int rpk,temprpk,temprpk1,temprpk2,slow,express,city,totbill;
    int sfar,getdfar,getafar,totfar,totfar1,totrate,far1;
    string linename,mstation,estation,templinename,templinename1,templinename2,stationame,tempstation,tempsstation,tempestation;

public:

     void railway_line_menu()
    {
        lable5:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t_RALIWAY LINE MENU_"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t01.SHOW RAILWAY LINES"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t02.ADD RAILWAY LINE"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t03.EDIT RAILWAY LINE"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t04.DELETE RAILWAY LINE"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t05.BACK"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t06.EXIT"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER CHOICE:";
        cin>>x;
        switch(x)
        {


        case '1':
            {
                system("cls");
                show_train_line();
                getch();
                goto lable5;
            }break;
            case '2':
            {
                system("cls");
                add_train_line();
                goto lable5;
            }break;
        case '3':
            {
                system("cls");
                edit_or_delete_line();
                goto lable5;
            }break;
        case '4':
            {
                system("cls");
                edit_or_delete_line(1);
                goto lable5;
            }break;
        case '5':
            {
                //back
            }break;
        case '6':
            {
                exit(0);
                cout<<"fk";
                getch();
            }break;
        default:
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\t\t\t\tENTER CORRECT VALUE:";
                cout<<"\n\n\t\t\t\t\tENTER ANY KEY TO CONTINU:";
                getch();
            }break;
        }

    }

    void add_train_line()
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t_ADD LINE_"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tENTER LINE NAME:";
        cin>>linename;
        cout<<"\n\n\t\t\t\t\t\t\tENTER RATE PER KILOMETER:";
        cin>>rpk;
        cout<<"\n\n\t\t\t\t\t\t\tENTER MAIN STATION:";
        cin>>mstation;
        cout<<"\n\n\t\t\t\t\t\t\tENTER END STATION:";
        cin>>estation;

        fstream line;
        line.open("linenames.txt",ios::app | ios::in);

        line<<linename<<" "<<rpk<<" "<<mstation<<" "<<estation<<endl;

         cout<<"\n\n\n\t\t\t\t\t\t\tNEW LINE RECODED:";
         cout<<"\n\t\t\tPRESS ANY KEY TO MENU:";

         //create text file for line names

         linename+=".txt";
         fstream  stations (linename.c_str(),ios::app);



         getch();

    }

    void edit_or_delete_line()
    {
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER LINE NAME FOR EDIT:";
        cin>>templinename;

        fstream line;
        line.open("linenames.txt",ios::app | ios::in);
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in);
        if(!line)
        {
            cout<<"no data yet";
        }else
        {
            line>>linename>>rpk>>mstation>>estation;
            while(!line.eof())
            {
                if(templinename==linename)
                {
                    cout<<"\n\n\n\t\t\t\t\t\t\tENTER LINE NAME:";
                    cin>>linename;
                    cout<<"\n\n\t\t\t\t\t\t\tENTER RATE PER KILOMETER:";
                    cin>>rpk;
                    cout<<"\n\n\t\t\t\t\t\t\tENTER MAIN STATION:";
                    cin>>mstation;
                    cout<<"\n\n\t\t\t\t\t\t\tENTER END STATION:";
                    cin>>estation;

                    temp<<linename<<" "<<rpk<<" "<<mstation<<" "<<estation<<endl;

                    line>>linename>>rpk>>mstation>>estation;
                }else
                {
                    temp<<linename<<" "<<rpk<<" "<<mstation<<" "<<estation<<endl;
                    line>>linename>>rpk>>mstation>>estation;

                }

            }
            temp.close();
            line.close();

            remove("linenames.txt");
            rename("temp.txt","linenames.txt");
            cout<<"ENTER ANY KEY TO CONTINU:";
            getch();


        }

}

    void edit_or_delete_line(int x)
    {
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER LINE NAME FOR DELETE:";
        cin>>templinename;

        fstream line;
        line.open("linenames.txt",ios::app | ios::in);
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in);
        if(!line)
        {
            cout<<"no data yet";
        }else
        {
            line>>linename>>rpk>>mstation>>estation;
            while(!line.eof())
            {
                if(templinename==linename)
                {
                    lable10:
                    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tALL THE STATIONS WILL BE DELETE ON "<<linename<<" LINE";
                    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t01.YES";
                    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t02.NO";
                    cin>>y;

                    if(y=='1')
                    {
                        cout<<"\n\n\n\t\t\t\t\t\t"<<linename<<" IS DELETED...."<<endl;
                        linename+=".txt";
                        remove(linename.c_str());
                    }else if(y=='2')
                    {
                        temp<<linename<<" "<<rpk<<" "<<mstation<<" "<<estation<<endl;
                    }else
                    {
                        system("cls");
                        cout<<"\n\n\n\n\t\t\t\t\tENTER CORRECT VALUVE:";
                        goto lable10;

                    }



                    line>>linename>>rpk>>mstation>>estation;
                }else
                {
                    temp<<linename<<" "<<rpk<<" "<<mstation<<" "<<estation<<endl;
                    line>>linename>>rpk>>mstation>>estation;

                }

            }
            temp.close();
            line.close();

            remove("linenames.txt");
            rename("temp.txt","linenames.txt");
            cout<<"ENTER ANY KEY TO CONTINU:";
            getch();
        }


        }
    void show_train_line()
    {
        fstream train;
        train.open("linenames.txt",ios::app | ios::in);
        train>>linename>>rpk>>mstation>>estation;
        if(!train)
        {
            cout<<"\n\n\n\n\n\t\tNO DATA ENTERD YET...."<<endl;
            cout<<"\n\n\t\t\t\t\tPRESS ANY KEY TO MENU::"<<endl;
            getch();
        }else
        {
//            train lines
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_TRAIN LINES_\n\n\n"<<endl;
            cout<<"\n\t\t\t\t\t LINE NAME \t\t RATE \t\t  MAIN STATION  \t\t END STATION\n\n"<<endl;

            while(!train.eof())
            {
                cout<<"\t"<<setw(40)<<linename<<setw(20)<<rpk<<setw(25)<<mstation<<setw(30)<<estation<<endl;
                cout<<"\n";
                train>>linename>>rpk>>mstation>>estation;

            }
        }

    }


    void station_menu()
    {
        lable5:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t_RALIWAY LINE MENU_"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t01.SHOW STATIONS"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t02.ADD STATIONS"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t03.EDIT STATIONS"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t04.DELETE STATIONS"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t05.BACK"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t06.EXIT"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER CHOICE:";
        cin>>x;

            switch(x)
            {
            case '1':
                {
                system("cls");
                show_train_station();
                getch();
                goto lable5;
                }
                break;
            case '2':
            {
                add_station();
                goto lable5;
            }
            break;
            case '3':
            {
                edit_or_delete_station();
                goto lable5;
            }
            break;
            case '4':
            {
                edit_or_delete_station(5);
                goto lable5;
            }
            break;
            case '5':
            {
//                back
            }
            break;
            case '6':
            {
                exit(0);
            }
            break;
            default:
                {
                cout<<"\n\n\n\t\t\t\tWRONG INPUT...";
                cout<<"\n\t\t\tPRESS ANYKEY..";
                getch();
                goto lable5;
                }


    }
    }

    void show_train_station()
    {
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER LINE NAME:";
        cin>>templinename;
        fstream train;
        train.open("linenames.txt",ios::app | ios::in);
        train>>linename>>rpk>>mstation>>estation;
        if(!train)
        {
            cout<<"\n\n\n\n\n\t\tNO DATA ENTERD YET...."<<endl;
            cout<<"\n\n\t\t\t\t\tPRESS ANY KEY TO MENU::"<<endl;
            getch();
        }else
        {
            while(!train.eof())
            {
                if(linename==templinename)
                {
                    templinename+=".txt";
                    fstream station(templinename.c_str(),ios::app | ios::in);
                    station>>stationame>>sfar;
                    cout<<"\n\n\n\t\t\t\t\t\tSTATION \t\tFROM MAIN STATION\n\n"<<endl;
                    while(!station.eof())
                    {
                        cout<<setw(55)<<stationame<<setw(30)<<sfar<<endl;
                        station>>stationame>>sfar;
                    }

                }
                train>>linename>>rpk>>mstation>>estation;

            }
        }
        cout<<"PRESS ANYKEY...";

    }

    void add_station()
    {
        cout<<"\n\nPLEASE ENTER RAILWAY LINE NAME:-";
        cin>>templinename;
        templinename+=".txt";
        fstream stations(templinename.c_str(),ios::app | ios::out );
        if(!stations)
        {
            cout<<"\n\n\t\t WRONG INPUT....";
            cout<<"\n\n\t\t\t\t01.GOTO LINE LIST"<<endl;
            cout<<"\n\t\t\t\t02.ENTER AGAIN"<<endl;
            cout<<"\n\t\t\t\t03.MENU"<<endl;
            cin>>x;
            if(x==1)
            {
                show_train_line();
            }else if(x==2)
            {
                system("cls");
                cout<<"\n\n\n\t\t\tENETR AGAIN....";
                add_station();
            }else if(x==3)
            {

            }else
            {
                cout<<"\n\n\n\t\t\t\tPLEASE ENTER CORRECT VALUE...."<<endl;
                cout<<"\n\n\n\t\t\t\t\tENTER ANY KEY TO COUNTINU"<<endl;
            }
        }else
        {
            cout<<"\n\n\t\t\t\tENTER STATION NAME:-";
            cin>>stationame;
            cout<<"\n\n\t\t\t\t HOW FAR FROM MAIN STATION";
            cin>>sfar;
            stations<<stationame<<" "<<sfar<<endl;
        }

    }

    void edit_or_delete_station()
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\tENTER LINE NAME:";
        cin>>templinename;
        fstream line;
        line.open("linenames.txt",ios::app | ios::in);
        line>>linename>>rpk>>mstation>>estation;
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in );
        while(!line.eof())
        {
            if(linename==templinename)
            {
                templinename+=".txt";

                  fstream  stations (templinename.c_str(),ios::app | ios::in);
                  stations>>stationame>>sfar;
                  cout<<"\n\n\n\n\n\t\t\t\t\tENTER STATION THAT YOU WANT EDIT:";
                  cin>>tempstation;

                  while(!stations.eof())
                  {
                     if(tempstation==stationame)
                     {
                         cout<<"\n\n\t\t\t\t\tENTER STATION NAME:";
                         cin>>stationame;
                         cout<<"\n\n\t\t\t\t\tENTER HOW FAR FROM MAIN STATION:";
                         cin>>sfar;
                         temp<<stationame<<" "<<sfar<<endl;
                     }else
                     {
                         temp<<stationame<<" "<<sfar<<endl;
                     }

                     stations>>stationame>>sfar;
                  }
                  temp.close();
                  stations.close();


            }

            line>>linename>>rpk>>mstation>>estation;
        }
        remove(templinename.c_str());
        rename("temp.txt",templinename.c_str());
        cout<<"\n\n\n\n\n\t\tENTER ANYKEY:";
        getch();



    }

        void edit_or_delete_station(int x)
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\tENTER LINE NAME:";
        cin>>templinename;
        fstream line;
        line.open("linenames.txt",ios::app | ios::in);
        line>>linename>>rpk>>mstation>>estation;
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in );
        while(!line.eof())
        {
            if(linename==templinename)
            {
                templinename+=".txt";

                  fstream  stations (templinename.c_str(),ios::app | ios::in);
                  stations>>stationame>>sfar;
                  cout<<"\n\n\n\n\n\t\t\t\t\tENTER STATION THAT YOU WANT EDIT:";
                  cin>>tempstation;

                  while(!stations.eof())
                  {
                     if(tempstation==stationame)
                     {
                         cout<<"STATION DELETED...";
                     }else
                     {
                         temp<<stationame<<" "<<sfar<<endl;
                     }

                     stations>>stationame>>sfar;
                  }
                  temp.close();
                  stations.close();


            }

            line>>linename>>rpk>>mstation>>estation;
        }
        remove(templinename.c_str());
        rename("temp.txt",templinename.c_str());
        cout<<"\n\n\n\n\n\t\tENTER ANYKEY:";
        getch();



    }

   void cal_far()
    {
        cout<<"ENTER DEPATURE:";
        cin>>tempsstation;
        cout<<"ENTER ARRIVAL:";
        cin>>tempestation;

        fstream line;
        line.open("linenames.txt",ios::app | ios::in);
        line>>linename>>rpk>>mstation>>estation;
        while(!line.eof())
        {
            cout<<linename<<endl;
            templinename=linename;
            templinename+=".txt";
            fstream line1(templinename.c_str(),ios::app | ios::in);
            line1>>stationame>>sfar;
            while(!line1.eof())
            {
                cout<<stationame<<endl;

                if(tempsstation==stationame)
                {
                    getdfar=sfar;
                    templinename1=linename;

                }
                if(tempestation==stationame)
                {
                    getafar=sfar;
                    templinename2=linename;
                }

                line1>>stationame>>sfar;
            }


           line>>linename>>rpk>>mstation>>estation;

        }


//cout<<getafar<<templinename1<<getdfar<<templinename2;

        if(templinename1==templinename2)
        {
            if(getafar>getdfar)
            {
                totfar=(getafar-getdfar);
            }
            else if(getafar<getdfar)
            {
                totfar=(getdfar-getafar);
            }else
            {
                totfar=0;
            }
        }else
        {
            totfar=(getafar+getdfar);
        }



        lable11:
           system("Cls");
       cout<<"\n\n\n\n\t\t\t\t\tCHOOSE YOUR Train:"<<endl;
       cout<<"\n\n\\n\t\t\t\t\t01.INTER CITY"<<endl;
       cout<<"\n\n\\n\t\t\t\t\t02.EXPRESS"<<endl;
       cout<<"\n\n\\n\t\t\t\t\t03.SLOW"<<endl;
       cin>>temp;
        fstream ticket;

        far1=totfar;

       ticket.open("ticket.txt",ios::app | ios::in);
       ticket>>express>>city>>slow;

       switch (temp)
       {
       case '1':
           break;
           {
                totbill=(far1*express);
           }
           case '2':
               {
                   totbill=(far1*city);
               }
           break;
           case '3' :
               {
                   totbill=(far1*slow);
               }
           break;

       default:
           {
               cout<<"please ENTER AGAIN..."<<endl;
               getch();
               goto lable11;
           }
           break;
       }

    }

   void add_ticket()
   {

        remove("ticket.txt");
       fstream ticket;

       ticket.open("ticket.txt",ios::app | ios::in);
       cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tEXPRESS PRICE:"<<endl;
       cin>>express;
       cout<<"\n\t\t\t\t\tINTER CITY:"<<endl;
       cin>>city;
       cout<<"\n\t\t\t\t\tSLOW PRICE:"<<endl;
       cin>>slow;
       ticket<<express<<" "<<city<<" "<<slow<<endl;
       ticket.close();



   }

   void book_ticket()
   {


   }



    void train_menu()
    {
        lable4:
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tRAILWAY SYSTEM...."<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t01.RAILWAY LINE"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t02.STATION"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t03.TICKET PRICE"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t04.BACK TO ADMIN MENU"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t05.EXIT"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE:";

        cin>>x;

        switch (x)
        {
        case '1':
            {

                railway_line_menu();
                goto lable4;
            }
            break;
        case '2' :
            {
                station_menu();
                goto lable4;
    }
        break;
        case '3':
            {
//                Canteen obj2;
//                obj2.add_iteam();
//                goto lable4;
            }
            break;
        case '4':
            {
//               back
            }
        break;
            case '5':
            {
                exit(0);
            }
            break;

        default:
            {
            cout<<"\n\n\nPLEASE ENTER VALIDE VALUE"<<endl;
            cout<<"\n\t\t\tENTER ANY KEY TO MENU";
            getch();
            system("cls");
            goto lable4;
            }
            break;
        }
    }
};


class Canteen:public Train
{
private:
    int avelablecontity,itemnum,temp,contity,x;
    float price,bill,totbill;
    string itemname;

public:
    Canteen()
    {
        totbill=0;

    };


    void add_iteam()
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\tADD ITEAM TO CANTEEN"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tENTER ITEM NAME:-";
        cin>>itemname;
        cout<<"\n\n\t\t\t\t\t\t\tENTER ITEM PRICE:-";
        cin>>price;
        cout<<"\n\n\t\t\t\t\t\t\tENTER ITEM AVELABLE CONTITY:";
        cin>>avelablecontity;

        fstream canteen_items;
        canteen_items.open("canteen.txt",ios::app | ios::in);
        canteen_items<<itemname<<" "<<price<<" "<<avelablecontity<<endl;
        cout<<"\n\n\t\t\t\t\t\t\tENTER ANY KEY TO BACK:";
        getch();
        system("cls");

    }

    void show_list()
    {
        fstream canteen_items;
    canteen_items.open("canteen.txt", ios::in);
    if (!canteen_items)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        canteen_items.close();
    }else
    {   int total=0;
        canteen_items >> itemname >>price >> avelablecontity;

         cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t___CANTEEN MENU___ \n\n\n"<< endl;
         cout<<"\t\t\t\t\t\t"<<"ITEM_NUMBER"<<"\t\t"<<"ITEAM_NAME"<<"\t\t"<<"price"<<"\t\t"<<"avelable_contity"<<endl;
         cout<<"\n\n";
         itemnum=0;
        while (!canteen_items.eof())
            {
            ++itemnum;
            cout<<"\t\t\t\t\t\t"<<setw(6)<<itemnum<<setw(25)<<itemname<<"\t\t"<<setw(12)<<price<<"\t\t"<<setw(10)<<avelablecontity<<endl;
            cout<<"\n\n";
            canteen_items >> itemname >>price >> avelablecontity;
            }

    }
    }


    void biling()
    {
        lable5:

        cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE ENTER NUMBER WHAT DID U WONT:-";
        cin>>temp;

        fstream canteen_items;
        canteen_items.open("canteen.txt",ios::out | ios::in);
        itemnum=0;


        canteen_items>>itemname>>price>>avelablecontity;

        while (!canteen_items.eof())
        {
            itemnum++;
            canteen_items>>itemname>>price>>avelablecontity;


            if(itemnum==temp)
            {

                cout<<"\n\n\n\n\n\t\t\t\tHOW MANY "<<itemname<<" DO YOU WONT:-";
                cin>>contity;
                bill=contity*price;
                totbill=totbill+bill;
                cout<<"\n\n\t\t\t\tYOUR BILL IS:-"<<bill<<endl;
                cout<<"\n\n\n\n\t\t\t\t\t\t01.GET MORE ITEMS"<<endl;
                cout<<"\n\n\n\t\t\t\t\t\t02.GOTO MAIN MENU"<<endl;
                cout<<"\n\n\t\t\t\t\t\t\tENTER YOUR CHOICE:-";
                cin>>x;
                if(x==1)
                {
                    system("cls");
                    goto lable5;
                }else if(x==2)
                {
                    cout<<"\n\n\t\t\t\t\tYOUR TOTAL BILL IS:"<<totbill<<endl;
                    cout<<"\n\n\n\t\t\t\t\tHAVE A NICE DAY!!"<<endl;
                    cout<<"n\n\t\t\t\t\tENTER ANY KEY FOR MAIN MENU"<<endl;
                    getch();
                    system("cls");
                }else
                {
                    cout<<"PLEASE ENTER CORRECT VALUE"<<endl;
                    goto lable5;
                }





            }


        }



    }



};

class Resort:public Canteen
{
private:
        float rent,totalrent;
        int rprice,avelableacrooms,avelablnonacrooms,acprice,nonacprice,itemnum,count2,temptype;
        string resortname,tempresort;
public:


    void add_resort()
    {
        lable10:
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tADD ITEAM TO RESORT"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tENTER RESORT NAME:-";
        cin>>resortname;
        cout<<"\n\n\t\t\t\t\t\t\tENTER TOTAL RESORT  PRICE:-";
        cin>>rprice;
        cout<<"\n\n\t\t\t\t\t\t\tENTER  AVELABLE AC ROOMS:";
        cin>>avelableacrooms;
        cout<<"\n\n\t\t\t\t\t\t\tENTER  AVELABLE NON|AC ROOMS:";
        cin>>avelablnonacrooms;
        cout<<"\n\n\t\t\t\t\t\t\tENTER  AC ROOMS PRICE:";
        cin>>acprice;
        cout<<"\n\n\t\t\t\t\t\t\tENTER   NON|AC ROOMS PRICE:";
        cin>>nonacprice;

        cout<<"\n\n\t\t\t\t\t\t\tCONFIRM DETAILS:";
        cout<<"\n\n\t\t\t\t\t\t\t01.YES:";
        cout<<"\n\n\t\t\t\t\t\t\t02.NO:";
        int temp2;
        cin>>temp2;
        if(temp2==1)
        {
            fstream resorts;
            resorts.open("resort.txt",ios::app | ios::in);
            resorts<<resortname<<" "<<rprice<<" "<<avelableacrooms<<" "<<avelablnonacrooms<<" "<<acprice<<" "<<nonacprice<<endl;
            resorts.close();
        }else
        {
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER AGAIN:__";
            Sleep(2000);
            goto lable10;
        }

        cout<<"\n\n\n\n\n\t\t\t\t\t\t\tENTER ANY KEY TO MENU:"<<endl;
        getch();

    }


    void showlist()
    {
         fstream resorts;
    resorts.open("resort.txt", ios::in);
    if (!resorts)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        resorts.close();
    }else
    {   int total=0;
         cout << "\n\n\n\t\t\t\t\t\t\t\t\t___RESORT MENU___ \n\n\n"<< endl;
         cout<<"\t\t\t"<<"RESORT_ID"<<"\t"<<"RESORT_NAME"<<"\t"<<"RESORT_TOTALL_PRICE"<<"\t"<<"AC_ROOMS"<<"\t"<<"NON|AC_ROOMS"<<"\t"<<"AC_PRICE"<<"\t"<<"NON|AC_PRICE"<<endl;
         cout<<"\n\n";
         itemnum=0;


        while (!resorts.eof())
            {
            ++itemnum;
                     resorts>>resortname>>rprice>>avelableacrooms>>avelablnonacrooms>>acprice>>nonacprice;

            cout<<"\t\t"<<setw(15)<<itemnum<<setw(17)<<resortname<<setw(20)<<rprice<<setw(17)<<avelableacrooms<<setw(17)<<avelablnonacrooms<<setw(17)<<acprice<<setw(17)<<nonacprice;
            cout<<"\n\n";
            resorts>>resortname>>rprice>>avelableacrooms>>avelablnonacrooms>>acprice>>nonacprice;
            }

    }

    }

    void bill()
    {
        labale7:
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPLEASE CHOICE A RESORT(enter name):-";
        cin>>tempresort;
        lable6:
        cout<<"\n\t\t\t\t\t\t\tENTRE YOUR ROOM TYPE:"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t01.AC\n\n\t\t\t\t\t\t\t\t02.NON|AC\n\n\t\t\t\t\t\t\t\t03.FULL RESORT"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE:-";
        cin>>temptype;
        cout<<"\n\n\n\t\t\t\t\t\t\t\tENTER HOW MANY ROOMS DO YOU WANT:";
        cin>>count2;

        fstream resorts;
        resorts.open("resort.txt",ios::app | ios::in);
        while (!resorts.eof())
            {

            resorts>>resortname>>rprice>>avelableacrooms>>avelablnonacrooms>>acprice>>nonacprice;

            if (tempresort==resortname)
            {

                if (temptype==1)
                {
                    rent=acprice*count2;

                }
                else if (temptype==2)
                {
                    rent=nonacprice*count2;
                }
                else if(temptype==3)
                {
                    rent=rprice;
                }else
                {
                    cout<<"PLEASE ENTER VALIED VALUE";
                    Sleep(3000);
                    goto lable6;
                }

                totalrent=rent+totalrent;
                cout<<"\n\n\t\t\t\tBOOK MORE RESORT?"<<endl;
                cout<<"\n\t\t\t\t01.yes\n\n\t\t\t\t02.NO\n\n"<<endl;
                cout<<"\t\t\t\tENTER CHOICE:";
                cin>>temptype;
                if (temptype==1)
                {
                    goto labale7;
                }else
                 {
                     cout<<"\n\n\n\t\t\t\tYOUR TOTALL BILL IS :-"<<totalrent;
                     cout<<"\n\n\t\t\t\t\tENTER ANY KEY TO MAIN MENU:"<<endl;
                     getch();
                 }
            }


            resorts>>resortname>>rprice>>avelableacrooms>>avelablnonacrooms>>acprice>>nonacprice;
            }
    }


};

class Geust:public Resort
{
private:

public:

    void menu()
    {
        lable3:
        system("cls");
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\tWELCOME TO PASSENGER PORTAL...."<<endl;
        cout<<"\n\n\t\t\t\t\t\t\tHELLO USER";//user.tempusername<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t01.TICKET BOOKING"<<endl;
//        cout<<"\n\n\t\t\t\t\t\t\t\t\t02.PARCLE SENDING"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t02.RESORT BOOKING"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t03.CANTEEN"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t04.ABOUT US"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t05.BACK TO LOGIN MENU"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t06.EXIT"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE:";

        int x;
        cin>>x;

        switch (x)
        {
        case 1:
            {
                Train obj1;
                obj1.cal_far();
                goto lable3;
            }
            break;
//        case 2 :
//            {
//                goto lable3;
//            }
//        break;
        case 2:
            {
                system("cls");
                Resort obj5;
                obj5.showlist();
                cout<<"\n\n\nENTER ANY KEY TO CONTINUE";
                getch();
                obj5.bill();
                getch();

                goto lable3;
            }
            break;
        case 3:
            {
                system("cls");
                Canteen obj4;
                obj4.show_list();
                cout<<"\n\n\nENTER ANY KEY TO CONTINUE";
                getch();
                obj4.biling();
                getch();
                goto lable3;

            }
        break;
        case 4:
            {


                goto lable3;
            }
            break;
        case 5:
            {

            }
            break;
            case 6:
            {
                exit(0);
            }
            break;

        default:
            {
                cout<<"\n\n\nPLEASE ENTER VALIDE VALUE"<<endl;
                cout<<"\n\t\t\tENTER ANY KEY TO MENU";
                getch();
                system("cls");
                goto lable3;
            }
            break;
        }


    }
};


class Admin:public Resort
{
private:

public:
    int x;

    void menu()
    {
        lable4:
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWELCOME TO ADMIN PORTAL...."<<endl;
        cout<<"\n\n\t\t\t\t\t\t\tHELLO AMIN!!";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t01.RAILWAY LINE"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t02.STATION"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t03.ADD CANTEEN"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t04.ADD RESORTS"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t05.BACK TO LOGIN MENU"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t\t\t06.EXIT"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE:";

        cin>>x;

        switch (x)
        {
        case 1:
            {
                Train obj1;
                obj1.railway_line_menu();
                goto lable4;
            }
            break;
        case 2 :
            {
                station_menu();
                goto lable4;
            }
        break;
        case 3:
            {
                Canteen obj2;
                obj2.add_iteam();
                goto lable4;
            }
            break;
        case 4:
            {
                Resort obj3;
                obj3.add_resort();
                goto lable4;
            }
        break;
        case 5:
            {
                //goto again account class
            }
            break;
            case 6:
            {
                exit(0);
            }
            break;

        default:
            {
            cout<<"\n\n\nPLEASE ENTER VALIDE VALUE"<<endl;
            cout<<"\n\t\t\tENTER ANY KEY TO MENU";
            getch();
            system("cls");
            goto lable4;
            }
            break;
        }


    }

};




class Account :public Geust
{

private:
        int type,age,mnum;
        string fname,lname,email,adminpassword,username,password,tempusername,temppassword,acctype;
public:

friend void pass_value(Account user);

void sign_up()
{



    lable:
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO OUR RAILWAY SYSTEM"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tSIGN IN...."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t01.AS ADMIN"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t02.AS PASSENGER"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tSIGN UP...."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t03.AS ADMIN"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t04.AS PASSENGER"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tEXIT...."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t05.EXIT PROGRAM"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE_";
    cin>>type;

    if(type==1)
    {
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO OUR RAILWAY SYSTEM"<<endl;
        cout<<"\n\n\t\t\t\t\t ADMIN PORTAL..."<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR USER NAME:-";
        cin>>tempusername;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR PASSWORD:-";
        cin>>temppassword;

        fstream signup;
        signup.open("admin.txt",ios::in);
        if(!signup)
        {
            cout<<"\n\n\n\t\t\t\tNO ANY ADMIN LOGIN YET"<<endl;
            signup.close();
            goto lable;
        }else
        {
            signup>>acctype >>username>>password>>fname>>lname>>age>>mnum>>email;
            while(!signup.eof())
            {
                if(username==tempusername || password==temppassword)
                {
                    cout<<"\n\n\n\t\t\t\tACCOUNT LOGIN SUCCESS.......";
//                    cout<<"\n\n\n\t\t\t\t............................"<<endl;
                    Sleep(3000);
                    system("cls");
                    Admin obj2;
                    obj2.menu();
                    goto lable;
                }else
                {
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tINVALID LOGIN PLEASE TRY AGAIN...."<<endl;
                    Sleep(3000);
                    goto lable;

                }
                signup>>acctype >>username>>password>>fname>>lname>>age>>mnum>>email;
            }
        }

    }
    else if(type==2)
    {
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO OUR RAILWAY SYSTEM"<<endl;
        cout<<"\n\n\t\t\t\t\t PASSENGER PORTAL..."<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR USER NAME:-";
        cin>>tempusername;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR PASSWORD:-";
        cin>>temppassword;
        fstream signup;
        signup.open("guest.txt",ios::in);
        if(!signup)
        {
            cout<<"\n\n\n\t\t\t\tNO ANY USER LOGIN YET"<<endl;
            signup.close();
            goto lable;
        }else
        {
            signup >>username>>password>>fname>>lname>>age>>mnum>>email;
            while(!signup.eof())
            {
                if(username==tempusername || password==temppassword)
                {
                    cout<<"\n\n\n\t\t\t\tACCOUNT LOGIN SUCCESS";
                    Sleep(2500);
                    Geust obj2;
                    obj2.menu();
                    goto lable;
                }
                signup>>username>>password>>fname>>lname>>age>>mnum>>email;
            }
        }
    }else if(type==3)
    {
//        signup as admin
        cout<<"\n\t\t\t\t\t\tPLEASE ENTER PASSWORD::";
        cin>>adminpassword;
        if("lahirusuwahas"==adminpassword)
        {

            lable2:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO PASSWENGER PORTAL"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tENTER YOUR FIRST NAME:-";
            cin>>fname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR LAST NAME:-";
            cin>>lname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR AGE:-";
            cin>>age;
            cout<<"\n\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:-";
            cin>>mnum;
            cout<<"\n\t\t\t\t\t\tENTER YOUR EMAIL ADDRESS:-";
            cin>>email;
            cout<<"\n\t\t\t\t\t\tENTER YOUR USERNAME:-";
            cin>>username;
            cout<<"\n\t\t\t\t\t\tENTER YOUR PASSWORD:-";
            cin>>password;

            cout<<"\n\n\t\t\t\t\tPLEASE CONFOIRM YOUR DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 1 FOR CONFIRM DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 2 FOR ENTER DETAILS AGAIN"<<endl;  //chek spells
            cin>>type;

            if(type==1)
            {
                fstream signup;
                signup.open("admin.txt",ios::app );
                signup<<"admin "<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;


            }else
            {   system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
                goto lable2;
            }
        }else{
                cout<<"_INVALID PASSWORD_"<<endl;
                cout<<"PLEASE ENTER CORRECT PASSWORD OR TRY AS A PASSENGER"<<endl;
                cout<<"PLEASE ENTER ANY KEY FOR LOGIN MENU"<<endl;
                getch();
                system("cls");
                goto lable;
             }



    }
    else if(type==4)
    {
//        signup as a passenger
            lable1:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO PASSWENGER PORTAL"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tENTER YOUR FIRST NAME:-";
            cin>>fname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR LAST NAME:-";
            cin>>lname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR AGE:-";
            cin>>age;
            cout<<"\n\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:-";
            cin>>mnum;
            cout<<"\n\t\t\t\t\t\tENTER YOUR EMAIL ADDRESS:-";
            cin>>email;
            cout<<"\n\t\t\t\t\t\tENTER YOUR USERNAME:-";
            cin>>username;
            cout<<"\n\t\t\t\t\t\tENTER YOUR PASSWORD:-";
            cin>>password;

            cout<<"\n\n\t\t\t\t\tPLEASE CONFOIRM YOUR DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 1 FOR CONFIRM DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 2 FOR ENTER DETAILS AGAIN"<<endl;  //chek spells
            cin>>type;

            if(type==1)
            {
                fstream signup;
                signup.open("guest.txt",ios::app );
                signup<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;


            }else
            {   system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
                goto lable1;
            }
    }else if(type==5)
    {
        exit(0);
    }

    goto lable;


}




};



int main()
{
//

    system("color 2");

    Account obj1;
    obj1.sign_up();

//
//                Train obj2;
//                obj2.cal_far();


    return 0;
}

