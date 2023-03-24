 #include "danh_sach.cpp"

class BN : public PS{
    private:
        string mbn, mhs, tsb, cdb;
        NS nc;
        long int vp;
        Ds *ds_dt;
        Ds *ds_dv;
    public:
        BN(){}
        BN(string mbn, string mhs, string tsb, string cdb, NS nc, long int vp, Ds *ds_dt, Ds *ds_dv);
        ~BN(){}
        
        friend istream& operator>>(istream &is, BN* a);

        friend ostream& operator<<(ostream &os, BN* a);

        void setMbn(string mbn);
        string getMbn();

        void setMhs(string mhs);
        string getMhs();

        void setTsb(string tsb);
        string getTsb();

        void setCdb(string cdb);
        string getCdb();

        void setNc(NS nc);
        NS getNc();

        void setVp(long int vp);
        long int getVp();

        void setDs_dt(Ds *ds_dt);
        Ds* getDs_dt();

        void setDs_dv(Ds *ds_dv);
        Ds* getDs_dv();

        long int thanh_tien();
};


BN :: BN(string mbn, string mhs, string tsb, string cdb, NS nc, long int vp, Ds *ds_dt, Ds *ds_dv){
    this -> mbn = mbn;
    this -> mhs = mhs;
    this -> tsb = tsb;
    this -> cdb = cdb;
    this -> nc = nc;
    this -> vp = vp;
    this -> ds_dt = ds_dt;
    this -> ds_dv = ds_dv;
}
 
istream& operator>>(istream &is, BN* a){
    is >> (PS*) a;
    cout << "Ma benh nhan: "; getline(is, a -> mbn);
    cout << "Ma ho so: "; getline(is, a -> mhs);
    cout << "Tien su benh: "; getline(is, a -> tsb);
    cout << "Chan doan benh: "; getline(is, a -> cdb);
    cout << "\n\tNgay chuyen" << endl;
    is >> a -> nc;
    cout << "Vien phi: "; is >> a -> vp;
    ds_dthuoc(is, a -> ds_dt);
    ds_dvu(is, a -> ds_dv);
    return is;

}   

ostream& operator<<(ostream &os, BN* a){
    os << (PS*) a;
    os << '|' << setw(25) << a -> mbn;
    os << '|' << setw(15) << a -> mhs;
    os << '|' << setw(25) << a -> tsb;
    os << '|' << setw(25) << a -> cdb;
    os << a -> nc;
    os << '|' << setw(15) << a -> vp;
    os << '|' << setw(15) << a -> thanh_tien();
    return os;
} 

long int BN :: thanh_tien(){
    return 1;
}

void BN :: setMbn(string mbn){
    this -> mbn = mbn;
}
string BN :: getMbn(){
    return mbn;
}

void BN :: setMhs(string mhs){
    this -> mhs = mhs;
}
string BN :: getMhs(){
    return mhs;
}

void BN :: setTsb(string tsb){
    this -> tsb = tsb;
}
string BN :: getTsb(){
    return tsb;
}

void BN :: setCdb(string cdb){
    this -> cdb = cdb;
}
string BN :: getCdb(){
    return cdb;
}

void BN :: setNc(NS nc){
    this -> nc = nc;
}
NS BN :: getNc(){
    return nc;
}

void BN :: setVp(long int vp){
    this -> vp = vp;
}
long int BN :: getVp(){
    return vp;
}

void BN :: setDs_dt(Ds *ds_dt){
    this -> ds_dt = ds_dt;
}
Ds* BN :: getDs_dt(){
    return ds_dt;
}

void BN :: setDs_dv(Ds *ds_dv){
    this -> ds_dv = ds_dv;
}
Ds* BN :: getDs_dv(){
    return ds_dv;
}