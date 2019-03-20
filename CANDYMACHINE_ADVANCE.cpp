#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>
int option;
char *target;
using namespace std;
class item{
    int cost,quantity,tot_cost;
public:
    item(int price){
        quantity=0;
        cost=price;
        tot_cost=0;

    }
    void quantity_check();//TO LIMT THE QUANTITY UPTO 10
    int bill();//TO SHOW WHAT THE CUSTOMER HAS SELECTED TO BUY.

};
void item::quantity_check(){
    cout <<"ENTER THE QUANTITY OF THE ITEM YOU WANT TO BUY(NOT MORE THAN 10)--";
    for(int i=0;;i++){
        cin>>quantity;
        if(quantity<=10)
            break;
        else{
            //LOGIC TO LIMIT THE MAXIMUM NUMBER OF TRY UPTO 3
            if(i==2){
                cout <<"YOU HAVE EXHAUSTED ALL YOUR CHANCES"<<endl<<"Thankyou!!!";
                exit(1);//HOW TO DISPLAY THE EXIT STATUS?????????
            }
                cout << "PLEASE TRY AGAIN!!"<<endl;
                cout <<"ENTER THE QUANTITY OF THE ITEM YOU WANT TO BUY(NOT MORE THAN 10)--";


        }


    }


}
int item::bill(){
    int temp;
    //char temp_opt;
    tot_cost=cost*quantity;
    cout <<"ITEM CHOOSED IS:-"<<endl;
    switch(option){
    case 1:
        cout <<"CHOCOLATE";
        break;
    case 2:
        cout <<"BISCUIT";
        break;
    case 3:
        cout <<"CANDY";
        break;
    case 4:
        cout <<"JUICE";
        break;

    }
    cout <<"--------------------- "<<cost<<"*"<<quantity<<"="<<tot_cost<<endl;

    //cout <<"PLEASE MAKE THE PAYEMENT"<<endl;

    return (tot_cost);


 }
 /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
 class payment
  {
     int total_cost,deposit,change,rem_money;
 public:
    payment(int total_cost){
        this->total_cost=total_cost;

    }
    void transaction();
    void final_bill();

 };
void payment::transaction(){
    cout <<"PLAEASE DEPOSIT Rs "<<total_cost<<endl;

    int i;
    for(i=0;i<3;i++){
        cin>>deposit;
        if(deposit>=0){
            break;
        }
        cout <<"PLEASE ENTER VALID MONEY!! "<<endl;
    }
    if(i==3){
        cout <<"YOU HAVE EXHAUSTED ALL YOUR LIMITS "<<endl<<"THANKYOU!!!";
        exit(5);
    }
    if(deposit>=total_cost){
        final_bill();

    }
    else{
        //LOGIC TO RESTRICT NUMBER OF CHANCES TO PAY MONEY TO 3
        int i;
        for(i=0;i<2;i++){
            int temp;
            rem_money=total_cost-deposit;
            cout <<"PLEASE DEPOSIT Rs "<<rem_money<<" MORE FOR SUCCESFULL TRANSACTION!!"<<endl;
            cin>>temp;
            deposit= deposit + temp;
            if(temp>=rem_money){
                final_bill();
                break;
            }
        }
        if(i==2){
            cout <<"YOU HAVE EXHAUSTED ALL YOUR CHANCES"<<endl<<"YOU DIDN'T DEPOSIT ENOUGH MONEY!!"<<endl<<"THANKYOU!!!";
            exit(2);
        }
    }
}

void payment::final_bill(){
    change=total_cost-deposit;
    cout <<endl<<"YOUR PAYMENT INFORMATION:-"<<endl;
    /*switch(option){
    case 1:
        cout <<"CHOCOLATE";
        break;
    case 2:
        cout <<"BISCUIT";
        break;
    case 3:
        cout <<"CANDY";
        break;
    case 4:
        cout <<"JUICE";
        break;

    }*/
    cout <<"BILL---------- "<<total_cost<<endl;
    cout <<"MONEY DEPOSITED------"<<deposit<<endl;
    cout <<"BALANCE MONEY--------"<<change<<endl;
    if(change!=0)
        cout <<"PLEASE COLLECT THE BALANCE AMOUNT!!!!!!!!"<<endl;
    cout <<"THANKYOU FOR SHOPPING WITH US!!!!!!!";
    exit(3);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------*/
int menu_opt(){
    char *source="INITIALISATION";
    cout << "PLEASE SELECT ONE OF THE BELOW ITEMS:--"<<endl<<endl;
    cout <<"1. CHOCOLATE"<<endl;
    cout <<"2. BISCUIT"<<endl;
    cout <<"3. CANDY"<<endl;
    cout <<"4. JUICE"<<endl;
    cout <<"PLEASE MENTION THE NUMBER"<<endl;
    cin >>option;
    switch(option){
    case 1:
        source="CHOCOLATE";
        target=source;
        return (50);
        break;
    case 2:
        source="BISCUIT";
        target=source;
        //strcpy(target,source);
        //target=source
        return (60);
        break;
    case 3:
        source="CANDY";
        target=source;
        //strcpy(target,source);
        return (80);
        break;
    case 4:
        source="JUICE";
        target=source;
        //strcpy(target,source);
        return(100);
        break;
    default:
        cout <<"INVALID OPTION!! "<<endl;
        cout <<"PLEASE TRY AGAIN"<<endl<<endl;
        menu_opt();//ERROR WHEN MAIN FUNCTION WAS CALLED. SAME ERROR OCCURED EARLIER ALSO
        break;

    }

 }

int exit_check(){
    char temp_opt;
    cout <<"DO YOU WANT TO SHOP MORE!!! [Y/N]";
    cin >>temp_opt;//TO STORE THE USER'S RESPONSE FOR Y/N
    if(temp_opt=='n' || temp_opt=='N')
        return(0);
    else
        return(1);
}
void welcome(){
    cout <<"                             +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout <<"                             +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout <<"                             +++                                                                                   +++"<<endl;
    cout <<"                             +++                                                                                   +++"<<endl;
    cout <<"                             +++                             THE BAZAR!!!!!                                        +++"<<endl;
    cout <<"                             +++                               WELCOME!!!!                                         +++"<<endl;
    cout <<"                             +++                                                                                   +++"<<endl;
    cout <<"                             +++                                                            --BY INDERPREET SINGH  +++"<<endl;
    cout <<"                             +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout <<"                             +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

}
main(){
    int check,price,total_cost;
    int i=0;
    char name[4];
    ofstream fout;
    ifstream fin;
    fout.open("data.dat");
    welcome();
    do{
        //cout <<"welcome";
        price=menu_opt();//FUNCTION HAS RETURN TYPE INT
        item i1(price);
        i1.quantity_check();
        total_cost=i1.bill();
        fout <<target<<endl;
        fout <<total_cost<<endl;
        check=exit_check();
        i++;
    }while(check);
    char temp[20];
    fout.close();
    fin.open("data.dat");
    total_cost=0;
    cout <<endl<<"LIST OF ITEMS YOU BOUGHT:--"<<endl;
    for(;i>0;i--){
        fin>>temp;
        fin>>price;
        total_cost+=price;
        cout <<temp<<"------------------"<<price<<endl;

    }


    payment p1(total_cost);//PASSING TOTAL COST TO PAYEMENT CLASS
    p1.transaction();
    p1.final_bill();
    /*SCREEN NOT STOPPING AT THE END----VVIP
    int scr_stopper;
    cin >>scr_stopper;
    cout <<"PRESS ANY KEY TO EXIT";
    cin >>scr_stopper;
    */
}//END OF MAIN FUNCTION
