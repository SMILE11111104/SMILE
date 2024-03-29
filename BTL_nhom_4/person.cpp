#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class NS{
    private:
        int d, m, y;
    public:
        NS(){}
        ~NS(){}

        friend istream& operator>>(istream &is, NS &a);
        friend ostream& operator<<(ostream &os, NS a);

        void setD(int d);
        int getD();

        void setM(int m);
        int getM();

        void setY(int y);
        int getY();
};

class PS{
    protected:
        string ht, cmt, dc, gt;
        NS ns;
    public:
        PS(){}
        PS(string ht, NS ns, string cmt, string gt, string dc);
        ~PS(){}
        
        friend istream& operator>>(istream &is, PS* a);

        friend ostream& operator<<(ostream &os, PS* a); 
        
        void setHt(string ht);
        string getHt();

        void setCmt(string cmt);
        string getCmt();

        void setGt(string gt);
        string getGt();

        void setDc(string dc);
        string getDc();

        void setNs(NS ns);
        NS getNs();

};

//Tai dinh nghia toan tu cua class NS

istream& operator>>(istream &is, NS &a){
    cout << "Ngay: "; is >> a.d;
    cout << "Thang: "; is >> a.m;
    cout << "Nam: "; is >> a.y;
    return is;
}

ostream& operator<<(ostream &os, NS a){
    if (a.d < 10) os << '|' << setw(4) << '0' << a.d;
    else os << '|' << setw(5) << a.d;

    if (a.m < 10) os << "-0" << a.m;
    else os << '-' << a.m;

    os << '-' << setw(4) << a.y;
    return os;
}

//Dinh nghia ben ngoai class PS
PS :: PS(string ht, NS ns, string cmt, string gt, string dc){
    this -> ht = ht;
    this -> ns = ns;
    this -> cmt = cmt;
    this -> gt = gt;
    this -> dc = dc;
}

istream& operator>>(istream &is, PS* a){
    cout << "Ho ten: "; getline(is, a -> ht);
    cout << "\n\tNgay sinh" << endl;
    is >> a -> ns;
    is.ignore();
    cout << "Chung minh thu: "; getline(is, a -> cmt);
    cout << "Gioi tinh: "; getline(is, a -> gt);
    cout << "Dia chi: "; getline(is, a -> dc);
    return is;
}

string tach_cmt(string a, int k){
    string b = "";
    while(a[a.length() - 1] != 'B'){
        b = a[a.length() - 1] + b;
        a.pop_back();
    }
    if (k == 1) return b;
    return a;
}

ostream& operator<<(ostream &os, PS* a){
    os << '|' << setw(20) << a -> ht;
    os << a -> ns;
    os << '|' << setw(15) << tach_cmt(a -> cmt, 1);
    os << '|' << setw(10) << a -> gt;
    os << '|' << setw(20) << a -> dc;
    return os;
} 

void PS :: setHt(string ht){
    this -> ht = ht;
}
string PS :: getHt(){
    return ht;
}

void PS :: setCmt(string cmt){
    this -> cmt = cmt;
}
string PS :: getCmt(){
    return cmt;
}

void PS :: setGt(string gt){
    this -> gt = gt;
}
string PS :: getGt(){
    return gt;
}

void PS :: setDc(string dc){
    this -> dc = dc;
}
string PS :: getDc(){
    return dc;
}

void PS :: setNs(NS ns){
    this -> ns = ns;
}
NS PS :: getNs(){
    return ns;
}

