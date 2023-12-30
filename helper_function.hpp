#include<iostream>
#include<vector>
std::vector<int>minus_one(std::vector<int>v, int pos){
    if(v.front()==0&&v.size()==1){
        return v;
    }else if(v[pos]==0){
        v[pos]=9;
        return minus_one(v,pos-1);
    }else{
        v[pos]--;
        if(v.front()==0&&v.size()>1){
            v.erase(v.begin());
        }
        return v;
    }
}

std::vector<int>flat(std::vector<int>&v,int c,int pos){
    int t = v[pos]+c;
    v[pos] = t%10;
    c = t/10;
    if(pos==0){
        while(c!=0){
            v.insert(v.begin(),c%10);
            c = c/10;
        }
        return v;
    }else{
        return flat(v, c, pos-1);
    }
}

std::vector<int>ftimes(std::vector<int> a,std::vector <int>b){
    if (a.size()<b.size()){
        std::swap(a,b);
    }
    std::vector<int>res;
    for(int i=0;i<b.size();i++){
        if(i==0){
            for(int j=b.size()-1;j>i;j--){
                res.push_back(0);
            }
            for(int j=a.size()-1;j>-1;j--){
                res.insert(res.begin(),a[j]*b[i]);
            }
            flat(res,0,res.size()-1);
        }else{
            for(int j=a.size()-1;j>-1;j--){
                res[res.size()-(b.size()-i)+(j- a.size()+1)] = a[j]*b[i]+res[res.size()-(b.size()-i)+(j- a.size()+1)];
            }
            // more likely to get overflow when put outside for loop, but much faster
            flat(res,0,res.size()-1);

        }
    }
    return res;
}


void print(std::vector<int>s){
    for(int i =0;i<s.size();i++){
        std::cout<<s[i];
    }
    std::cout<<std::endl;
}

std::vector<int>factorial(std::vector<int>v){
        if(v.size()==1&&v.front()<=1){
            std::vector<int> res = {1};
            return res;
        }else{
            return ftimes(v,factorial(minus_one(v,v.size()-1)));
        }
}

std::vector<int>char_to_vec(std::string arg){
    std::vector<int>res;
    try{
        for(int i =0;i<arg.size();i++){
            int inp = arg[i]-'0';
            if(inp<0||inp>9){
                throw arg[i];
            }else{
                res.push_back(inp);
            }
        }
    }catch(char e){
        std::cout<<"Expect Integer>=0, get "<<e<<std::endl;
        res.clear();
    }
    return res;
}



