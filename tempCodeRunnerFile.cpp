void Display_Statement(){
        string cp[Statement.size()+1];
        for(size_t i=0;i<Statement.size();i++){
            cp[i]=Statement[i];

        }
        ostringstream occ;
        occ<<"Amount left "<<setprecision('0')<<Amount;
        cp[Statement.size()]=occ.str();

        print(cp,Statement.size()+1);

    }